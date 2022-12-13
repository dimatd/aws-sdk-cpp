﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/m2/model/DatasetOrgAttributes.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MainframeModernization
{
namespace Model
{

DatasetOrgAttributes::DatasetOrgAttributes() : 
    m_gdgHasBeenSet(false),
    m_vsamHasBeenSet(false)
{
}

DatasetOrgAttributes::DatasetOrgAttributes(JsonView jsonValue) : 
    m_gdgHasBeenSet(false),
    m_vsamHasBeenSet(false)
{
  *this = jsonValue;
}

DatasetOrgAttributes& DatasetOrgAttributes::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("gdg"))
  {
    m_gdg = jsonValue.GetObject("gdg");

    m_gdgHasBeenSet = true;
  }

  if(jsonValue.ValueExists("vsam"))
  {
    m_vsam = jsonValue.GetObject("vsam");

    m_vsamHasBeenSet = true;
  }

  return *this;
}

JsonValue DatasetOrgAttributes::Jsonize() const
{
  JsonValue payload;

  if(m_gdgHasBeenSet)
  {
   payload.WithObject("gdg", m_gdg.Jsonize());

  }

  if(m_vsamHasBeenSet)
  {
   payload.WithObject("vsam", m_vsam.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace MainframeModernization
} // namespace Aws
