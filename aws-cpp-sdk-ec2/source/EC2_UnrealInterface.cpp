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

	bool CreateInstance(const std::string& InstanceName, const std::string& AmiID, const std::string& Region, std::string& OutputMsg)
	{
		char Outputbuffer[1024];
		Aws::String instanceName = InstanceName.c_str();
		Aws::String ami_id = AmiID.c_str();

		// snippet-start:[ec2.cpp.create_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region.c_str();

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::RunInstancesRequest run_request;
		run_request.SetImageId(ami_id.c_str());
		run_request.SetInstanceType(Aws::EC2::Model::InstanceType::t2_micro);
		run_request.SetMinCount(1);
		run_request.SetMaxCount(1);

		auto run_outcome = ec2.RunInstances(run_request);

		if (!run_outcome.IsSuccess())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to start ec2 instance %s based on ami_id %s : '%s'"
				, InstanceName.c_str()
				, AmiID.c_str()
				, run_outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		const auto& instances = run_outcome.GetResult().GetInstances();
		if (instances.size() == 0)
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to start ec2 instance %s based on ami_id %s : '%s'"
				, InstanceName.c_str()
				, AmiID.c_str()
				, run_outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
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
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to tag ec2 instance %s based on ami_id %s : '%s'"
				, instance_id.c_str()
				, AmiID.c_str()
				, create_outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		snprintf(Outputbuffer, sizeof(Outputbuffer), "Successfully started ec2 instance %s(%s) based on ami_id '%s'"
			, InstanceName.c_str()
			, instance_id.c_str()
			, AmiID.c_str());
		OutputMsg = Outputbuffer;

		return true;
	}

	bool StartInstance(const std::string& InstanceID, const std::string& Region, std::string& OutputMsg)
	{
		char Outputbuffer[1024];
		Aws::String instance_id = InstanceID.c_str();
		// snippet-start:[ec2.cpp.start_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region.c_str();

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::StartInstancesRequest start_request;
		start_request.AddInstanceIds(instance_id.c_str());
		start_request.SetDryRun(true);

		auto dry_run_outcome = ec2.StartInstances(start_request);
		if (!dry_run_outcome.IsSuccess() || dry_run_outcome.GetError().GetErrorType() != Aws::EC2::EC2Errors::DRY_RUN_OPERATION)
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed dry run to start instance %s : '%s'"
				, instance_id.c_str()
				, dry_run_outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		start_request.SetDryRun(false);
		auto start_instancesOutcome = ec2.StartInstances(start_request);

		if (!start_instancesOutcome.IsSuccess())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to start instance %s : '%s'"
				, instance_id.c_str()
				, start_instancesOutcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		snprintf(Outputbuffer, sizeof(Outputbuffer), "Successfully started instance '%s'"
			, instance_id.c_str());
		OutputMsg = Outputbuffer;
		return true;
	}

	bool StopInstance(const std::string& InstanceID, const std::string& Region, std::string& OutputMsg)
	{
		char Outputbuffer[1024];
		Aws::String instance_id = InstanceID.c_str();

		// snippet-start:[ec2.cpp.stop_instance.code]
		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region.c_str();

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::StopInstancesRequest request;
		request.AddInstanceIds(instance_id.c_str());
		request.SetDryRun(true);

		auto dry_run_outcome = ec2.StopInstances(request);
		if (!dry_run_outcome.IsSuccess() || dry_run_outcome.GetError().GetErrorType() != Aws::EC2::EC2Errors::DRY_RUN_OPERATION)
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed dry run to stop instance %s : %s"
				, instance_id.c_str()
				, dry_run_outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		request.SetDryRun(false);
		auto outcome = ec2.StopInstances(request);
		if (!outcome.IsSuccess())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to stop instance %s : %s"
				, instance_id.c_str()
				, outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		snprintf(Outputbuffer, sizeof(Outputbuffer), "Successfully stopped instance %s"
			, instance_id.c_str());
		OutputMsg = Outputbuffer;
		return true;

		// snippet-end:[ec2.cpp.stop_instance.code]
	}

	bool GetInstanceState(const std::string& InstanceID, const std::string& Region, std::string& OutputMsg, int& OutInstanceState)
	{
		char Outputbuffer[1024];
		Aws::String instance_id = InstanceID.c_str();

		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region.c_str();

		Aws::EC2::EC2Client ec2(clientConfiguration);

		Aws::EC2::Model::DescribeInstancesRequest request;
		request.AddInstanceIds(instance_id.c_str());

		auto outcome = ec2.DescribeInstances(request);
		if (!outcome.IsSuccess())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to describe ec2 instances: '%s'", outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
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

	bool GetInstanceIP(const std::string& InstanceID, const std::string& Region, std::string& OutputMsg, std::string& OutIp)
	{
		char Outputbuffer[1024];
		Aws::String instance_id = InstanceID.c_str();

		Aws::Client::ClientConfiguration clientConfiguration;
		clientConfiguration.region = Region.c_str();

		Aws::EC2::EC2Client ec2(clientConfiguration);
		Aws::EC2::Model::DescribeAddressesRequest request;

		auto outcome = ec2.DescribeAddresses(request);
		if (!outcome.IsSuccess())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Failed to describe elastic ip addresses: '%s'"
				, outcome.GetError().GetMessage().c_str());
			OutputMsg = Outputbuffer;
			return false;
		}

		const auto &addresses = outcome.GetResult().GetAddresses();
		auto address = std::find_if(addresses.begin(), addresses.end(), [instance_id](const Aws::EC2::Model::Address& Item) { return Item.GetInstanceId() == instance_id;  });
		if (address == addresses.end())
		{
			snprintf(Outputbuffer, sizeof(Outputbuffer), "Ip not found - instance '%s'"
				, instance_id.c_str());
			OutputMsg = Outputbuffer;
			return true;
		}

		OutIp = address->GetPublicIp().c_str();
		return true;
	}

}