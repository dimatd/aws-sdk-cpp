﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/waf-regional/model/SqlInjectionMatchSetSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace WAFRegional
{
namespace Model
{

SqlInjectionMatchSetSummary::SqlInjectionMatchSetSummary() : 
    m_sqlInjectionMatchSetIdHasBeenSet(false),
    m_nameHasBeenSet(false)
{
}

SqlInjectionMatchSetSummary::SqlInjectionMatchSetSummary(JsonView jsonValue) : 
    m_sqlInjectionMatchSetIdHasBeenSet(false),
    m_nameHasBeenSet(false)
{
  *this = jsonValue;
}

SqlInjectionMatchSetSummary& SqlInjectionMatchSetSummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("SqlInjectionMatchSetId"))
  {
    m_sqlInjectionMatchSetId = jsonValue.GetString("SqlInjectionMatchSetId");

    m_sqlInjectionMatchSetIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  return *this;
}

JsonValue SqlInjectionMatchSetSummary::Jsonize() const
{
  JsonValue payload;

  if(m_sqlInjectionMatchSetIdHasBeenSet)
  {
   payload.WithString("SqlInjectionMatchSetId", m_sqlInjectionMatchSetId);

  }

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  return payload;
}

} // namespace Model
} // namespace WAFRegional
} // namespace Aws
