﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/glue/model/GetCrawlersResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Glue::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetCrawlersResult::GetCrawlersResult()
{
}

GetCrawlersResult::GetCrawlersResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

GetCrawlersResult& GetCrawlersResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("Crawlers"))
  {
    Array<JsonView> crawlersJsonList = jsonValue.GetArray("Crawlers");
    for(unsigned crawlersIndex = 0; crawlersIndex < crawlersJsonList.GetLength(); ++crawlersIndex)
    {
      m_crawlers.push_back(crawlersJsonList[crawlersIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }



  return *this;
}
