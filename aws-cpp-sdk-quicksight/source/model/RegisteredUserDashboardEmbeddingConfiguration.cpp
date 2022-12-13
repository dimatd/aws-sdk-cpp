﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/quicksight/model/RegisteredUserDashboardEmbeddingConfiguration.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace QuickSight
{
namespace Model
{

RegisteredUserDashboardEmbeddingConfiguration::RegisteredUserDashboardEmbeddingConfiguration() : 
    m_initialDashboardIdHasBeenSet(false)
{
}

RegisteredUserDashboardEmbeddingConfiguration::RegisteredUserDashboardEmbeddingConfiguration(JsonView jsonValue) : 
    m_initialDashboardIdHasBeenSet(false)
{
  *this = jsonValue;
}

RegisteredUserDashboardEmbeddingConfiguration& RegisteredUserDashboardEmbeddingConfiguration::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("InitialDashboardId"))
  {
    m_initialDashboardId = jsonValue.GetString("InitialDashboardId");

    m_initialDashboardIdHasBeenSet = true;
  }

  return *this;
}

JsonValue RegisteredUserDashboardEmbeddingConfiguration::Jsonize() const
{
  JsonValue payload;

  if(m_initialDashboardIdHasBeenSet)
  {
   payload.WithString("InitialDashboardId", m_initialDashboardId);

  }

  return payload;
}

} // namespace Model
} // namespace QuickSight
} // namespace Aws
