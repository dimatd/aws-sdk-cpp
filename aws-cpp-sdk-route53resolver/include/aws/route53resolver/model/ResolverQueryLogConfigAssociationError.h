﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/route53resolver/Route53Resolver_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Route53Resolver
{
namespace Model
{
  enum class ResolverQueryLogConfigAssociationError
  {
    NOT_SET,
    NONE,
    DESTINATION_NOT_FOUND,
    ACCESS_DENIED,
    INTERNAL_SERVICE_ERROR
  };

namespace ResolverQueryLogConfigAssociationErrorMapper
{
AWS_ROUTE53RESOLVER_API ResolverQueryLogConfigAssociationError GetResolverQueryLogConfigAssociationErrorForName(const Aws::String& name);

AWS_ROUTE53RESOLVER_API Aws::String GetNameForResolverQueryLogConfigAssociationError(ResolverQueryLogConfigAssociationError value);
} // namespace ResolverQueryLogConfigAssociationErrorMapper
} // namespace Model
} // namespace Route53Resolver
} // namespace Aws
