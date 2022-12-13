﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/s3-crt/model/ExistingObjectReplication.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace S3Crt
{
namespace Model
{

ExistingObjectReplication::ExistingObjectReplication() : 
    m_status(ExistingObjectReplicationStatus::NOT_SET),
    m_statusHasBeenSet(false)
{
}

ExistingObjectReplication::ExistingObjectReplication(const XmlNode& xmlNode) : 
    m_status(ExistingObjectReplicationStatus::NOT_SET),
    m_statusHasBeenSet(false)
{
  *this = xmlNode;
}

ExistingObjectReplication& ExistingObjectReplication::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode statusNode = resultNode.FirstChild("Status");
    if(!statusNode.IsNull())
    {
      m_status = ExistingObjectReplicationStatusMapper::GetExistingObjectReplicationStatusForName(StringUtils::Trim(Aws::Utils::Xml::DecodeEscapedXmlText(statusNode.GetText()).c_str()).c_str());
      m_statusHasBeenSet = true;
    }
  }

  return *this;
}

void ExistingObjectReplication::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  if(m_statusHasBeenSet)
  {
   XmlNode statusNode = parentNode.CreateChildElement("Status");
   statusNode.SetText(ExistingObjectReplicationStatusMapper::GetNameForExistingObjectReplicationStatus(m_status));
  }

}

} // namespace Model
} // namespace S3Crt
} // namespace Aws
