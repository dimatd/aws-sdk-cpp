﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/wafv2/model/GetMobileSdkReleaseRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::WAFV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

GetMobileSdkReleaseRequest::GetMobileSdkReleaseRequest() : 
    m_platform(Platform::NOT_SET),
    m_platformHasBeenSet(false),
    m_releaseVersionHasBeenSet(false)
{
}

Aws::String GetMobileSdkReleaseRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_platformHasBeenSet)
  {
   payload.WithString("Platform", PlatformMapper::GetNameForPlatform(m_platform));
  }

  if(m_releaseVersionHasBeenSet)
  {
   payload.WithString("ReleaseVersion", m_releaseVersion);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection GetMobileSdkReleaseRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSWAF_20190729.GetMobileSdkRelease"));
  return headers;

}




