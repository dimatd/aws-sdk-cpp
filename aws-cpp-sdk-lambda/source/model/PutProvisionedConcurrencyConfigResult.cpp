﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/lambda/model/PutProvisionedConcurrencyConfigResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Lambda::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

PutProvisionedConcurrencyConfigResult::PutProvisionedConcurrencyConfigResult() : 
    m_requestedProvisionedConcurrentExecutions(0),
    m_availableProvisionedConcurrentExecutions(0),
    m_allocatedProvisionedConcurrentExecutions(0),
    m_status(ProvisionedConcurrencyStatusEnum::NOT_SET)
{
}

PutProvisionedConcurrencyConfigResult::PutProvisionedConcurrencyConfigResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_requestedProvisionedConcurrentExecutions(0),
    m_availableProvisionedConcurrentExecutions(0),
    m_allocatedProvisionedConcurrentExecutions(0),
    m_status(ProvisionedConcurrencyStatusEnum::NOT_SET)
{
  *this = result;
}

PutProvisionedConcurrencyConfigResult& PutProvisionedConcurrencyConfigResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("RequestedProvisionedConcurrentExecutions"))
  {
    m_requestedProvisionedConcurrentExecutions = jsonValue.GetInteger("RequestedProvisionedConcurrentExecutions");

  }

  if(jsonValue.ValueExists("AvailableProvisionedConcurrentExecutions"))
  {
    m_availableProvisionedConcurrentExecutions = jsonValue.GetInteger("AvailableProvisionedConcurrentExecutions");

  }

  if(jsonValue.ValueExists("AllocatedProvisionedConcurrentExecutions"))
  {
    m_allocatedProvisionedConcurrentExecutions = jsonValue.GetInteger("AllocatedProvisionedConcurrentExecutions");

  }

  if(jsonValue.ValueExists("Status"))
  {
    m_status = ProvisionedConcurrencyStatusEnumMapper::GetProvisionedConcurrencyStatusEnumForName(jsonValue.GetString("Status"));

  }

  if(jsonValue.ValueExists("StatusReason"))
  {
    m_statusReason = jsonValue.GetString("StatusReason");

  }

  if(jsonValue.ValueExists("LastModified"))
  {
    m_lastModified = jsonValue.GetString("LastModified");

  }



  return *this;
}
