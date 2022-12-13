﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/ec2/EC2Request.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/Filter.h>
#include <utility>

namespace Aws
{
namespace EC2
{
namespace Model
{

  /**
   */
  class AWS_EC2_API DescribeTransitGatewayAttachmentsRequest : public EC2Request
  {
  public:
    DescribeTransitGatewayAttachmentsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeTransitGatewayAttachments"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline const Aws::Vector<Aws::String>& GetTransitGatewayAttachmentIds() const{ return m_transitGatewayAttachmentIds; }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline bool TransitGatewayAttachmentIdsHasBeenSet() const { return m_transitGatewayAttachmentIdsHasBeenSet; }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline void SetTransitGatewayAttachmentIds(const Aws::Vector<Aws::String>& value) { m_transitGatewayAttachmentIdsHasBeenSet = true; m_transitGatewayAttachmentIds = value; }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline void SetTransitGatewayAttachmentIds(Aws::Vector<Aws::String>&& value) { m_transitGatewayAttachmentIdsHasBeenSet = true; m_transitGatewayAttachmentIds = std::move(value); }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithTransitGatewayAttachmentIds(const Aws::Vector<Aws::String>& value) { SetTransitGatewayAttachmentIds(value); return *this;}

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithTransitGatewayAttachmentIds(Aws::Vector<Aws::String>&& value) { SetTransitGatewayAttachmentIds(std::move(value)); return *this;}

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& AddTransitGatewayAttachmentIds(const Aws::String& value) { m_transitGatewayAttachmentIdsHasBeenSet = true; m_transitGatewayAttachmentIds.push_back(value); return *this; }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& AddTransitGatewayAttachmentIds(Aws::String&& value) { m_transitGatewayAttachmentIdsHasBeenSet = true; m_transitGatewayAttachmentIds.push_back(std::move(value)); return *this; }

    /**
     * <p>The IDs of the attachments.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& AddTransitGatewayAttachmentIds(const char* value) { m_transitGatewayAttachmentIdsHasBeenSet = true; m_transitGatewayAttachmentIds.push_back(value); return *this; }


    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline const Aws::Vector<Filter>& GetFilters() const{ return m_filters; }

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline bool FiltersHasBeenSet() const { return m_filtersHasBeenSet; }

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline void SetFilters(const Aws::Vector<Filter>& value) { m_filtersHasBeenSet = true; m_filters = value; }

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline void SetFilters(Aws::Vector<Filter>&& value) { m_filtersHasBeenSet = true; m_filters = std::move(value); }

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithFilters(const Aws::Vector<Filter>& value) { SetFilters(value); return *this;}

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithFilters(Aws::Vector<Filter>&& value) { SetFilters(std::move(value)); return *this;}

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline DescribeTransitGatewayAttachmentsRequest& AddFilters(const Filter& value) { m_filtersHasBeenSet = true; m_filters.push_back(value); return *this; }

    /**
     * <p>One or more filters. The possible values are:</p> <ul> <li> <p>
     * <code>association.state</code> - The state of the association
     * (<code>associating</code> | <code>associated</code> |
     * <code>disassociating</code>).</p> </li> <li> <p>
     * <code>association.transit-gateway-route-table-id</code> - The ID of the route
     * table for the transit gateway.</p> </li> <li> <p> <code>resource-id</code> - The
     * ID of the resource.</p> </li> <li> <p> <code>resource-owner-id</code> - The ID
     * of the Amazon Web Services account that owns the resource.</p> </li> <li> <p>
     * <code>resource-type</code> - The resource type. Valid values are
     * <code>vpc</code> | <code>vpn</code> | <code>direct-connect-gateway</code> |
     * <code>peering</code> | <code>connect</code>.</p> </li> <li> <p>
     * <code>state</code> - The state of the attachment. Valid values are
     * <code>available</code> | <code>deleted</code> | <code>deleting</code> |
     * <code>failed</code> | <code>failing</code> | <code>initiatingRequest</code> |
     * <code>modifying</code> | <code>pendingAcceptance</code> | <code>pending</code> |
     * <code>rollingBack</code> | <code>rejected</code> | <code>rejecting</code>.</p>
     * </li> <li> <p> <code>transit-gateway-attachment-id</code> - The ID of the
     * attachment.</p> </li> <li> <p> <code>transit-gateway-id</code> - The ID of the
     * transit gateway.</p> </li> <li> <p> <code>transit-gateway-owner-id</code> - The
     * ID of the Amazon Web Services account that owns the transit gateway.</p> </li>
     * </ul>
     */
    inline DescribeTransitGatewayAttachmentsRequest& AddFilters(Filter&& value) { m_filtersHasBeenSet = true; m_filters.push_back(std::move(value)); return *this; }


    /**
     * <p>The maximum number of results to return with a single call. To retrieve the
     * remaining results, make another call with the returned <code>nextToken</code>
     * value.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>The maximum number of results to return with a single call. To retrieve the
     * remaining results, make another call with the returned <code>nextToken</code>
     * value.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>The maximum number of results to return with a single call. To retrieve the
     * remaining results, make another call with the returned <code>nextToken</code>
     * value.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>The maximum number of results to return with a single call. To retrieve the
     * remaining results, make another call with the returned <code>nextToken</code>
     * value.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>The token for the next page of results.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The token for the next page of results.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>The token for the next page of results.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>The token for the next page of results.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>The token for the next page of results.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>The token for the next page of results.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token for the next page of results.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The token for the next page of results.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline bool GetDryRun() const{ return m_dryRun; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline bool DryRunHasBeenSet() const { return m_dryRunHasBeenSet; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline void SetDryRun(bool value) { m_dryRunHasBeenSet = true; m_dryRun = value; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline DescribeTransitGatewayAttachmentsRequest& WithDryRun(bool value) { SetDryRun(value); return *this;}

  private:

    Aws::Vector<Aws::String> m_transitGatewayAttachmentIds;
    bool m_transitGatewayAttachmentIdsHasBeenSet;

    Aws::Vector<Filter> m_filters;
    bool m_filtersHasBeenSet;

    int m_maxResults;
    bool m_maxResultsHasBeenSet;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet;

    bool m_dryRun;
    bool m_dryRunHasBeenSet;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
