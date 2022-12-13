﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iot/model/SetDefaultAuthorizerResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::IoT::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

SetDefaultAuthorizerResult::SetDefaultAuthorizerResult()
{
}

SetDefaultAuthorizerResult::SetDefaultAuthorizerResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

SetDefaultAuthorizerResult& SetDefaultAuthorizerResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("authorizerName"))
  {
    m_authorizerName = jsonValue.GetString("authorizerName");

  }

  if(jsonValue.ValueExists("authorizerArn"))
  {
    m_authorizerArn = jsonValue.GetString("authorizerArn");

  }



  return *this;
}
