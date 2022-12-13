﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/wellarchitected/model/GetLensReviewResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::WellArchitected::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetLensReviewResult::GetLensReviewResult() : 
    m_milestoneNumber(0)
{
}

GetLensReviewResult::GetLensReviewResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_milestoneNumber(0)
{
  *this = result;
}

GetLensReviewResult& GetLensReviewResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("WorkloadId"))
  {
    m_workloadId = jsonValue.GetString("WorkloadId");

  }

  if(jsonValue.ValueExists("MilestoneNumber"))
  {
    m_milestoneNumber = jsonValue.GetInteger("MilestoneNumber");

  }

  if(jsonValue.ValueExists("LensReview"))
  {
    m_lensReview = jsonValue.GetObject("LensReview");

  }



  return *this;
}
