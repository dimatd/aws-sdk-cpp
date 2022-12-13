﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/billingconductor/model/AssociatePricingRulesRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::BillingConductor::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

AssociatePricingRulesRequest::AssociatePricingRulesRequest() : 
    m_arnHasBeenSet(false),
    m_pricingRuleArnsHasBeenSet(false)
{
}

Aws::String AssociatePricingRulesRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_arnHasBeenSet)
  {
   payload.WithString("Arn", m_arn);

  }

  if(m_pricingRuleArnsHasBeenSet)
  {
   Array<JsonValue> pricingRuleArnsJsonList(m_pricingRuleArns.size());
   for(unsigned pricingRuleArnsIndex = 0; pricingRuleArnsIndex < pricingRuleArnsJsonList.GetLength(); ++pricingRuleArnsIndex)
   {
     pricingRuleArnsJsonList[pricingRuleArnsIndex].AsString(m_pricingRuleArns[pricingRuleArnsIndex]);
   }
   payload.WithArray("PricingRuleArns", std::move(pricingRuleArnsJsonList));

  }

  return payload.View().WriteReadable();
}




