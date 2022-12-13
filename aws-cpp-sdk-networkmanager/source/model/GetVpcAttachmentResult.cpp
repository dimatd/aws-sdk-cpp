﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/networkmanager/model/GetVpcAttachmentResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::NetworkManager::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetVpcAttachmentResult::GetVpcAttachmentResult()
{
}

GetVpcAttachmentResult::GetVpcAttachmentResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

GetVpcAttachmentResult& GetVpcAttachmentResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("VpcAttachment"))
  {
    m_vpcAttachment = jsonValue.GetObject("VpcAttachment");

  }



  return *this;
}
