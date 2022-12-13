﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/panorama/model/ListNodeFromTemplateJobsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Panorama::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

ListNodeFromTemplateJobsResult::ListNodeFromTemplateJobsResult()
{
}

ListNodeFromTemplateJobsResult::ListNodeFromTemplateJobsResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

ListNodeFromTemplateJobsResult& ListNodeFromTemplateJobsResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }

  if(jsonValue.ValueExists("NodeFromTemplateJobs"))
  {
    Array<JsonView> nodeFromTemplateJobsJsonList = jsonValue.GetArray("NodeFromTemplateJobs");
    for(unsigned nodeFromTemplateJobsIndex = 0; nodeFromTemplateJobsIndex < nodeFromTemplateJobsJsonList.GetLength(); ++nodeFromTemplateJobsIndex)
    {
      m_nodeFromTemplateJobs.push_back(nodeFromTemplateJobsJsonList[nodeFromTemplateJobsIndex].AsObject());
    }
  }



  return *this;
}
