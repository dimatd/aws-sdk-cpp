﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/codecommit/model/UpdateApprovalRuleTemplateDescriptionResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::CodeCommit::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

UpdateApprovalRuleTemplateDescriptionResult::UpdateApprovalRuleTemplateDescriptionResult()
{
}

UpdateApprovalRuleTemplateDescriptionResult::UpdateApprovalRuleTemplateDescriptionResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

UpdateApprovalRuleTemplateDescriptionResult& UpdateApprovalRuleTemplateDescriptionResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("approvalRuleTemplate"))
  {
    m_approvalRuleTemplate = jsonValue.GetObject("approvalRuleTemplate");

  }



  return *this;
}
