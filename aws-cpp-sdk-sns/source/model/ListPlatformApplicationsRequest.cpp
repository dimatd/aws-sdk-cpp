﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/sns/model/ListPlatformApplicationsRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::SNS::Model;
using namespace Aws::Utils;

ListPlatformApplicationsRequest::ListPlatformApplicationsRequest() : 
    m_nextTokenHasBeenSet(false)
{
}

Aws::String ListPlatformApplicationsRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ListPlatformApplications&";
  if(m_nextTokenHasBeenSet)
  {
    ss << "NextToken=" << StringUtils::URLEncode(m_nextToken.c_str()) << "&";
  }

  ss << "Version=2010-03-31";
  return ss.str();
}


void  ListPlatformApplicationsRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
