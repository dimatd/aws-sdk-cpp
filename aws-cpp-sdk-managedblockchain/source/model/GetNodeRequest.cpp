﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/managedblockchain/model/GetNodeRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::ManagedBlockchain::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws::Http;

GetNodeRequest::GetNodeRequest() : 
    m_networkIdHasBeenSet(false),
    m_memberIdHasBeenSet(false),
    m_nodeIdHasBeenSet(false)
{
}

Aws::String GetNodeRequest::SerializePayload() const
{
  return {};
}

void GetNodeRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_memberIdHasBeenSet)
    {
      ss << m_memberId;
      uri.AddQueryStringParameter("memberId", ss.str());
      ss.str("");
    }

}



