﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/sagemaker/model/DisassociateTrialComponentRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::SageMaker::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DisassociateTrialComponentRequest::DisassociateTrialComponentRequest() : 
    m_trialComponentNameHasBeenSet(false),
    m_trialNameHasBeenSet(false)
{
}

Aws::String DisassociateTrialComponentRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_trialComponentNameHasBeenSet)
  {
   payload.WithString("TrialComponentName", m_trialComponentName);

  }

  if(m_trialNameHasBeenSet)
  {
   payload.WithString("TrialName", m_trialName);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection DisassociateTrialComponentRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "SageMaker.DisassociateTrialComponent"));
  return headers;

}




