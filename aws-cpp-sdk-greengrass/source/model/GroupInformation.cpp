﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/greengrass/model/GroupInformation.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Greengrass
{
namespace Model
{

GroupInformation::GroupInformation() : 
    m_arnHasBeenSet(false),
    m_creationTimestampHasBeenSet(false),
    m_idHasBeenSet(false),
    m_lastUpdatedTimestampHasBeenSet(false),
    m_latestVersionHasBeenSet(false),
    m_latestVersionArnHasBeenSet(false),
    m_nameHasBeenSet(false)
{
}

GroupInformation::GroupInformation(JsonView jsonValue) : 
    m_arnHasBeenSet(false),
    m_creationTimestampHasBeenSet(false),
    m_idHasBeenSet(false),
    m_lastUpdatedTimestampHasBeenSet(false),
    m_latestVersionHasBeenSet(false),
    m_latestVersionArnHasBeenSet(false),
    m_nameHasBeenSet(false)
{
  *this = jsonValue;
}

GroupInformation& GroupInformation::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Arn"))
  {
    m_arn = jsonValue.GetString("Arn");

    m_arnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CreationTimestamp"))
  {
    m_creationTimestamp = jsonValue.GetString("CreationTimestamp");

    m_creationTimestampHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Id"))
  {
    m_id = jsonValue.GetString("Id");

    m_idHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LastUpdatedTimestamp"))
  {
    m_lastUpdatedTimestamp = jsonValue.GetString("LastUpdatedTimestamp");

    m_lastUpdatedTimestampHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LatestVersion"))
  {
    m_latestVersion = jsonValue.GetString("LatestVersion");

    m_latestVersionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LatestVersionArn"))
  {
    m_latestVersionArn = jsonValue.GetString("LatestVersionArn");

    m_latestVersionArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  return *this;
}

JsonValue GroupInformation::Jsonize() const
{
  JsonValue payload;

  if(m_arnHasBeenSet)
  {
   payload.WithString("Arn", m_arn);

  }

  if(m_creationTimestampHasBeenSet)
  {
   payload.WithString("CreationTimestamp", m_creationTimestamp);

  }

  if(m_idHasBeenSet)
  {
   payload.WithString("Id", m_id);

  }

  if(m_lastUpdatedTimestampHasBeenSet)
  {
   payload.WithString("LastUpdatedTimestamp", m_lastUpdatedTimestamp);

  }

  if(m_latestVersionHasBeenSet)
  {
   payload.WithString("LatestVersion", m_latestVersion);

  }

  if(m_latestVersionArnHasBeenSet)
  {
   payload.WithString("LatestVersionArn", m_latestVersionArn);

  }

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  return payload;
}

} // namespace Model
} // namespace Greengrass
} // namespace Aws
