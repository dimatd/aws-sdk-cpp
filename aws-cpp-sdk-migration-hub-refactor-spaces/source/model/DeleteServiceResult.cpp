﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/migration-hub-refactor-spaces/model/DeleteServiceResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::MigrationHubRefactorSpaces::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

DeleteServiceResult::DeleteServiceResult() : 
    m_state(ServiceState::NOT_SET)
{
}

DeleteServiceResult::DeleteServiceResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_state(ServiceState::NOT_SET)
{
  *this = result;
}

DeleteServiceResult& DeleteServiceResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ApplicationId"))
  {
    m_applicationId = jsonValue.GetString("ApplicationId");

  }

  if(jsonValue.ValueExists("Arn"))
  {
    m_arn = jsonValue.GetString("Arn");

  }

  if(jsonValue.ValueExists("EnvironmentId"))
  {
    m_environmentId = jsonValue.GetString("EnvironmentId");

  }

  if(jsonValue.ValueExists("LastUpdatedTime"))
  {
    m_lastUpdatedTime = jsonValue.GetDouble("LastUpdatedTime");

  }

  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

  }

  if(jsonValue.ValueExists("ServiceId"))
  {
    m_serviceId = jsonValue.GetString("ServiceId");

  }

  if(jsonValue.ValueExists("State"))
  {
    m_state = ServiceStateMapper::GetServiceStateForName(jsonValue.GetString("State"));

  }



  return *this;
}
