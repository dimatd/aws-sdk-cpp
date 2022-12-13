﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/dms/model/CancelReplicationTaskAssessmentRunResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::DatabaseMigrationService::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

CancelReplicationTaskAssessmentRunResult::CancelReplicationTaskAssessmentRunResult()
{
}

CancelReplicationTaskAssessmentRunResult::CancelReplicationTaskAssessmentRunResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

CancelReplicationTaskAssessmentRunResult& CancelReplicationTaskAssessmentRunResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ReplicationTaskAssessmentRun"))
  {
    m_replicationTaskAssessmentRun = jsonValue.GetObject("ReplicationTaskAssessmentRun");

  }



  return *this;
}
