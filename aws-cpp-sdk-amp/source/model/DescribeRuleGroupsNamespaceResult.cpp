﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/amp/model/DescribeRuleGroupsNamespaceResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::PrometheusService::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

DescribeRuleGroupsNamespaceResult::DescribeRuleGroupsNamespaceResult()
{
}

DescribeRuleGroupsNamespaceResult::DescribeRuleGroupsNamespaceResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

DescribeRuleGroupsNamespaceResult& DescribeRuleGroupsNamespaceResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ruleGroupsNamespace"))
  {
    m_ruleGroupsNamespace = jsonValue.GetObject("ruleGroupsNamespace");

  }



  return *this;
}
