﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/states/model/GetActivityTaskRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::SFN::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

GetActivityTaskRequest::GetActivityTaskRequest() : 
    m_activityArnHasBeenSet(false),
    m_workerNameHasBeenSet(false)
{
}

Aws::String GetActivityTaskRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_activityArnHasBeenSet)
  {
   payload.WithString("activityArn", m_activityArn);

  }

  if(m_workerNameHasBeenSet)
  {
   payload.WithString("workerName", m_workerName);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection GetActivityTaskRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSStepFunctions.GetActivityTask"));
  return headers;

}




