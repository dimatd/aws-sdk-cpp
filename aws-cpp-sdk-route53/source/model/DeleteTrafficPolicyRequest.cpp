﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/route53/model/DeleteTrafficPolicyRequest.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Route53::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

DeleteTrafficPolicyRequest::DeleteTrafficPolicyRequest() : 
    m_idHasBeenSet(false),
    m_version(0),
    m_versionHasBeenSet(false)
{
}

Aws::String DeleteTrafficPolicyRequest::SerializePayload() const
{
  return {};
}


