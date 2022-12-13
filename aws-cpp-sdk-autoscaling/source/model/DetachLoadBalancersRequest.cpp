﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/autoscaling/model/DetachLoadBalancersRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::AutoScaling::Model;
using namespace Aws::Utils;

DetachLoadBalancersRequest::DetachLoadBalancersRequest() : 
    m_autoScalingGroupNameHasBeenSet(false),
    m_loadBalancerNamesHasBeenSet(false)
{
}

Aws::String DetachLoadBalancersRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DetachLoadBalancers&";
  if(m_autoScalingGroupNameHasBeenSet)
  {
    ss << "AutoScalingGroupName=" << StringUtils::URLEncode(m_autoScalingGroupName.c_str()) << "&";
  }

  if(m_loadBalancerNamesHasBeenSet)
  {
    unsigned loadBalancerNamesCount = 1;
    for(auto& item : m_loadBalancerNames)
    {
      ss << "LoadBalancerNames.member." << loadBalancerNamesCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      loadBalancerNamesCount++;
    }
  }

  ss << "Version=2011-01-01";
  return ss.str();
}


void  DetachLoadBalancersRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
