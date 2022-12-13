﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/opensearch/model/OutboundConnection.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace OpenSearchService
{
namespace Model
{

OutboundConnection::OutboundConnection() : 
    m_localDomainInfoHasBeenSet(false),
    m_remoteDomainInfoHasBeenSet(false),
    m_connectionIdHasBeenSet(false),
    m_connectionAliasHasBeenSet(false),
    m_connectionStatusHasBeenSet(false)
{
}

OutboundConnection::OutboundConnection(JsonView jsonValue) : 
    m_localDomainInfoHasBeenSet(false),
    m_remoteDomainInfoHasBeenSet(false),
    m_connectionIdHasBeenSet(false),
    m_connectionAliasHasBeenSet(false),
    m_connectionStatusHasBeenSet(false)
{
  *this = jsonValue;
}

OutboundConnection& OutboundConnection::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("LocalDomainInfo"))
  {
    m_localDomainInfo = jsonValue.GetObject("LocalDomainInfo");

    m_localDomainInfoHasBeenSet = true;
  }

  if(jsonValue.ValueExists("RemoteDomainInfo"))
  {
    m_remoteDomainInfo = jsonValue.GetObject("RemoteDomainInfo");

    m_remoteDomainInfoHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ConnectionId"))
  {
    m_connectionId = jsonValue.GetString("ConnectionId");

    m_connectionIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ConnectionAlias"))
  {
    m_connectionAlias = jsonValue.GetString("ConnectionAlias");

    m_connectionAliasHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ConnectionStatus"))
  {
    m_connectionStatus = jsonValue.GetObject("ConnectionStatus");

    m_connectionStatusHasBeenSet = true;
  }

  return *this;
}

JsonValue OutboundConnection::Jsonize() const
{
  JsonValue payload;

  if(m_localDomainInfoHasBeenSet)
  {
   payload.WithObject("LocalDomainInfo", m_localDomainInfo.Jsonize());

  }

  if(m_remoteDomainInfoHasBeenSet)
  {
   payload.WithObject("RemoteDomainInfo", m_remoteDomainInfo.Jsonize());

  }

  if(m_connectionIdHasBeenSet)
  {
   payload.WithString("ConnectionId", m_connectionId);

  }

  if(m_connectionAliasHasBeenSet)
  {
   payload.WithString("ConnectionAlias", m_connectionAlias);

  }

  if(m_connectionStatusHasBeenSet)
  {
   payload.WithObject("ConnectionStatus", m_connectionStatus.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace OpenSearchService
} // namespace Aws
