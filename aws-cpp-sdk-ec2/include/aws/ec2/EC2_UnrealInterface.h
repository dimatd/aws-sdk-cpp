#pragma once

#include <aws/ec2/EC2_EXPORTS.h>
#include <string>

namespace UE
{
	AWS_EC2_API void InitAPI    ();
	AWS_EC2_API void ShutdownAPI();

	AWS_EC2_API bool CreateInstance  (const std::string& InstanceName, const std::string& AmiID, const std::string& Region, std::string& OutputMsg);

	AWS_EC2_API bool StartInstance   (const std::string& InstanceID, const std::string& Region, std::string& OutputMsg);
	AWS_EC2_API bool StopInstance    (const std::string& InstanceID, const std::string& Region, std::string& OutputMsg);

	AWS_EC2_API bool GetInstanceState(const std::string& InstanceID, const std::string& Region, std::string& OutputMsg, int& OutInstanceState);
	AWS_EC2_API bool GetInstanceIP   (const std::string& InstanceID, const std::string& Region, std::string& OutputMsg, std::string& OutIp);
}
