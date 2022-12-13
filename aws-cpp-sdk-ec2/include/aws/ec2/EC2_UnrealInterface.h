#pragma once

#include <aws/ec2/EC2_EXPORTS.h>
#include "aws/ec2/model/InstanceType.h"

namespace UE
{
	AWS_EC2_API void InitAPI    ();
	AWS_EC2_API void ShutdownAPI();

	AWS_EC2_API bool CheckConfig(char* OutputMsg, size_t OutputMsgSize);

	AWS_EC2_API bool CreateInstance  (const char* InstanceName, const char* AmiID, const char** SecurityGroup, size_t SecurityGroupNum, Aws::EC2::Model::InstanceType InstanceType, const char* Region, char* OutputMsg, size_t OutputMsgSize, char* OutInstanceID, size_t OutInstanceIDSize);

	AWS_EC2_API bool StartInstance   (const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize);
	AWS_EC2_API bool StopInstance    (const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize);

	AWS_EC2_API bool GetInstanceState(const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize, int& OutInstanceState);
	AWS_EC2_API bool GetInstanceIP   (const char* InstanceID, const char* Region, char* OutputMsg, size_t OutputMsgSize, char* OutPublicIp, size_t OutIpPublicSize, char* OutPrivateIp, size_t OutIpPrivateSize);
}
