﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/medialive/MediaLive_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace MediaLive
{
namespace Model
{

  /**
   * An IPv4 CIDR to whitelist.<p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/medialive-2017-10-14/InputWhitelistRuleCidr">AWS
   * API Reference</a></p>
   */
  class AWS_MEDIALIVE_API InputWhitelistRuleCidr
  {
  public:
    InputWhitelistRuleCidr();
    InputWhitelistRuleCidr(Aws::Utils::Json::JsonView jsonValue);
    InputWhitelistRuleCidr& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * The IPv4 CIDR to whitelist.
     */
    inline const Aws::String& GetCidr() const{ return m_cidr; }

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline bool CidrHasBeenSet() const { return m_cidrHasBeenSet; }

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline void SetCidr(const Aws::String& value) { m_cidrHasBeenSet = true; m_cidr = value; }

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline void SetCidr(Aws::String&& value) { m_cidrHasBeenSet = true; m_cidr = std::move(value); }

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline void SetCidr(const char* value) { m_cidrHasBeenSet = true; m_cidr.assign(value); }

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline InputWhitelistRuleCidr& WithCidr(const Aws::String& value) { SetCidr(value); return *this;}

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline InputWhitelistRuleCidr& WithCidr(Aws::String&& value) { SetCidr(std::move(value)); return *this;}

    /**
     * The IPv4 CIDR to whitelist.
     */
    inline InputWhitelistRuleCidr& WithCidr(const char* value) { SetCidr(value); return *this;}

  private:

    Aws::String m_cidr;
    bool m_cidrHasBeenSet;
  };

} // namespace Model
} // namespace MediaLive
} // namespace Aws
