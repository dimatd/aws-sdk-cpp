﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/datasync/DataSync_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace DataSync
{
namespace Model
{
  enum class HdfsAuthenticationType
  {
    NOT_SET,
    SIMPLE,
    KERBEROS
  };

namespace HdfsAuthenticationTypeMapper
{
AWS_DATASYNC_API HdfsAuthenticationType GetHdfsAuthenticationTypeForName(const Aws::String& name);

AWS_DATASYNC_API Aws::String GetNameForHdfsAuthenticationType(HdfsAuthenticationType value);
} // namespace HdfsAuthenticationTypeMapper
} // namespace Model
} // namespace DataSync
} // namespace Aws
