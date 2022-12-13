﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/frauddetector/model/GetDeleteEventsByEventTypeStatusResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::FraudDetector::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetDeleteEventsByEventTypeStatusResult::GetDeleteEventsByEventTypeStatusResult() : 
    m_eventsDeletionStatus(AsyncJobStatus::NOT_SET)
{
}

GetDeleteEventsByEventTypeStatusResult::GetDeleteEventsByEventTypeStatusResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_eventsDeletionStatus(AsyncJobStatus::NOT_SET)
{
  *this = result;
}

GetDeleteEventsByEventTypeStatusResult& GetDeleteEventsByEventTypeStatusResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("eventTypeName"))
  {
    m_eventTypeName = jsonValue.GetString("eventTypeName");

  }

  if(jsonValue.ValueExists("eventsDeletionStatus"))
  {
    m_eventsDeletionStatus = AsyncJobStatusMapper::GetAsyncJobStatusForName(jsonValue.GetString("eventsDeletionStatus"));

  }



  return *this;
}
