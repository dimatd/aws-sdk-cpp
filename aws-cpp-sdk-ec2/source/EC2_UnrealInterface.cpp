#include "aws/ec2/EC2_UnrealInterface.h"

#include "aws/core/Aws.h"
#include "aws/core/client/ClientConfiguration.h"
#include "aws/ec2/EC2Client.h"
#include "aws/ec2/model/DescribeInstancesRequest.h"
#include "aws/ec2/model/Instance.h"
#include "aws/ec2/model/InstanceState.h"
#include "aws/ec2/model/RunInstancesRequest.h"
#include "aws/ec2/model/CreateTagsRequest.h"
#include "aws/ec2/model/StartInstancesRequest.h"
#include "aws/ec2/model/StopInstancesRequest.h"
#include "aws/ec2/model/DescribeAddressesRequest.h"
#include <iomanip>

Aws::SDKOptions options;

#define JCHECK(expr) if(!(expr)) { OutputMsg = #expr; return false; }

namespace UE
{
	void InitAPI()
	{
		Aws::InitAPI(options);
	}

	void ShutdownAPI()
	{
		Aws::ShutdownAPI(options);
	}

	bool CreateInstance(const char* InstanceName, const char* AmiID, Aws::EC2::Model::InstanceType InstanceType, const char* Region, char* OutputMsg, size_t OutputMsgSize)
	{
		//char Outputbuffer[1024];
		Aws::String instanceName = InstanceName;
		Aws::String ami_id = AmiID;

		// snippet-start:[ec2.cpp.create_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region;

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::RunInstancesRequest run_request;
		run_request.SetImageId(ami_id.c_str());
		//run_request.SetInstanceType(Aws::EC2::Model::InstanceType::t2_micro);
		run_request.SetInstanceType(InstanceType);
		run_request.SetMinCount(1);
		run_request.SetMaxCount(1);

		auto run_outcome = ec2.RunInstances(run_request);

		if (!run_outcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to start ec2 instance %s based on ami_id %s : '%s'"
				, InstanceName
				, AmiID
				, run_outcome.GetError().GetMessage().c_str());
			return false;
		}

		const auto& instances = run_outcome.GetResult().GetInstances();
		if (instances.size() == 0)
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to start ec2 instance %s based on ami_id %s : '%s'"
				, InstanceName
				, AmiID
				, run_outcome.GetError().GetMessage().c_str());
			return false;
		}
		// snippet-end:[ec2.cpp.create_instance.code]

		auto instance_id = instances[0].GetInstanceId();

		Aws::EC2::Model::Tag name_tag;
		name_tag.SetKey("Name");
		name_tag.SetValue(instanceName.c_str());

		Aws::EC2::Model::CreateTagsRequest create_request;
		create_request.AddResources(instance_id.c_str());
		create_request.AddTags(name_tag);

		auto create_outcome = ec2.CreateTags(create_request);
		if (!create_outcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to tag ec2 instance %s based on ami_id %s : '%s'"
				, instance_id.c_str()
				, AmiID
				, create_outcome.GetError().GetMessage().c_str());
			return false;
		}

		snprintf(OutputMsg, OutputMsgSize, "Successfully started ec2 instance %s(%s) based on ami_id '%s'"
			, InstanceName
			, instance_id.c_str()
			, AmiID);

		return true;
	}

	bool StartInstance(const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize)
	{
		Aws::String instance_id = InstanceID;
		// snippet-start:[ec2.cpp.start_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region;

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::StartInstancesRequest start_request;
		start_request.AddInstanceIds(instance_id);

		auto start_instancesOutcome = ec2.StartInstances(start_request);

		if (!start_instancesOutcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to start instance %s : '%s'"
				, instance_id.c_str()
				, start_instancesOutcome.GetError().GetMessage().c_str());
			return false;
		}

		snprintf(OutputMsg, OutputMsgSize, "Successfully started instance '%s'"
			, instance_id.c_str());
		return true;
	}

	bool StopInstance(const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize)
	{
		Aws::String instance_id = InstanceID;

		// snippet-start:[ec2.cpp.stop_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region;

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::StopInstancesRequest request;
		request.AddInstanceIds(instance_id);

		auto outcome = ec2.StopInstances(request);
		if (!outcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to stop instance %s : %s"
				, instance_id.c_str()
				, outcome.GetError().GetMessage().c_str());
			return false;
		}

		snprintf(OutputMsg, OutputMsgSize, "Successfully stopped instance %s"
			, instance_id.c_str());
		return true;

		// snippet-end:[ec2.cpp.stop_instance.code]
	}

	bool GetInstanceState(const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize, int& OutInstanceState)
	{
		Aws::String instance_id = InstanceID;

		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region;

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::DescribeInstancesRequest request;
		request.AddInstanceIds(instance_id);

		auto outcome = ec2.DescribeInstances(request);
		if (!outcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to describe ec2 instances: '%s'", outcome.GetError().GetMessage().c_str());
			return false;
		}

		const auto &reservations = outcome.GetResult().GetReservations();
		JCHECK(reservations.size() == 1);
		auto reservation = reservations[0];
		auto instances = reservation.GetInstances();
		JCHECK(instances.size() == 1);

		OutInstanceState = static_cast<int>(instances[0].GetState().GetName());
		return true;
	}

	bool GetInstanceIP(const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize, char* OutIp, size_t OutIpSize)
	{
		Aws::String instance_id = InstanceID;

		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region;

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::DescribeInstancesRequest request;
		request.AddInstanceIds(instance_id);

		auto outcome = ec2.DescribeInstances(request);
		if (!outcome.IsSuccess())
		{
			snprintf(OutputMsg, OutputMsgSize, "Failed to describe ec2 instances: '%s'", outcome.GetError().GetMessage().c_str());
			return false;
		}

		const auto &reservations = outcome.GetResult().GetReservations();
		JCHECK(reservations.size() == 1);
		auto reservation = reservations[0];
		auto instances = reservation.GetInstances();
		JCHECK(instances.size() == 1);

		const Aws::String& Ip = instances[0].GetPublicIpAddress();
		strncpy_s(OutIp, OutIpSize, Ip.c_str(), Ip.size());
		return true;
	}
}