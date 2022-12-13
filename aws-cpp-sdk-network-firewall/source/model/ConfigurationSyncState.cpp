﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/network-firewall/model/ConfigurationSyncState.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace NetworkFirewall
  {
    namespace Model
    {
      namespace ConfigurationSyncStateMapper
      {

        static const int PENDING_HASH = HashingUtils::HashString("PENDING");
        static const int IN_SYNC_HASH = HashingUtils::HashString("IN_SYNC");


        ConfigurationSyncState GetConfigurationSyncStateForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == PENDING_HASH)
          {
            return ConfigurationSyncState::PENDING;
          }
          else if (hashCode == IN_SYNC_HASH)
          {
            return ConfigurationSyncState::IN_SYNC;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<ConfigurationSyncState>(hashCode);
          }

          return ConfigurationSyncState::NOT_SET;
        }

        Aws::String GetNameForConfigurationSyncState(ConfigurationSyncState enumValue)
        {
          switch(enumValue)
          {
          case ConfigurationSyncState::PENDING:
            return "PENDING";
          case ConfigurationSyncState::IN_SYNC:
            return "IN_SYNC";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace ConfigurationSyncStateMapper
    } // namespace Model
  } // namespace NetworkFirewall
} // namespace Aws
