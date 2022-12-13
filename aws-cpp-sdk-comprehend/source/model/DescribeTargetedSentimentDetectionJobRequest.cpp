﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/comprehend/model/DescribeTargetedSentimentDetectionJobRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Comprehend::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DescribeTargetedSentimentDetectionJobRequest::DescribeTargetedSentimentDetectionJobRequest() : 
    m_jobIdHasBeenSet(false)
{
}

Aws::String DescribeTargetedSentimentDetectionJobRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_jobIdHasBeenSet)
  {
   payload.WithString("JobId", m_jobId);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection DescribeTargetedSentimentDetectionJobRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "Comprehend_20171127.DescribeTargetedSentimentDetectionJob"));
  return headers;

}




