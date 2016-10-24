﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#pragma once
#include <aws/swf/SWF_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/swf/model/StartTimerFailedCause.h>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace SWF
{
namespace Model
{

  /**
   * <p>Provides details of the <code>StartTimerFailed</code> event.</p>
   */
  class AWS_SWF_API StartTimerFailedEventAttributes
  {
  public:
    StartTimerFailedEventAttributes();
    StartTimerFailedEventAttributes(const Aws::Utils::Json::JsonValue& jsonValue);
    StartTimerFailedEventAttributes& operator=(const Aws::Utils::Json::JsonValue& jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline const Aws::String& GetTimerId() const{ return m_timerId; }

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline void SetTimerId(const Aws::String& value) { m_timerIdHasBeenSet = true; m_timerId = value; }

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline void SetTimerId(Aws::String&& value) { m_timerIdHasBeenSet = true; m_timerId = value; }

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline void SetTimerId(const char* value) { m_timerIdHasBeenSet = true; m_timerId.assign(value); }

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline StartTimerFailedEventAttributes& WithTimerId(const Aws::String& value) { SetTimerId(value); return *this;}

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline StartTimerFailedEventAttributes& WithTimerId(Aws::String&& value) { SetTimerId(value); return *this;}

    /**
     * <p>The timerId provided in the <code>StartTimer</code> decision that failed.</p>
     */
    inline StartTimerFailedEventAttributes& WithTimerId(const char* value) { SetTimerId(value); return *this;}

    /**
     * <p>The cause of the failure. This information is generated by the system and can
     * be useful for diagnostic purposes.</p> <note>If <b>cause</b> is set to
     * OPERATION_NOT_PERMITTED, the decision failed because it lacked sufficient
     * permissions. For details and example IAM policies, see <a
     * href="http://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
     * IAM to Manage Access to Amazon SWF Workflows</a>.</note>
     */
    inline const StartTimerFailedCause& GetCause() const{ return m_cause; }

    /**
     * <p>The cause of the failure. This information is generated by the system and can
     * be useful for diagnostic purposes.</p> <note>If <b>cause</b> is set to
     * OPERATION_NOT_PERMITTED, the decision failed because it lacked sufficient
     * permissions. For details and example IAM policies, see <a
     * href="http://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
     * IAM to Manage Access to Amazon SWF Workflows</a>.</note>
     */
    inline void SetCause(const StartTimerFailedCause& value) { m_causeHasBeenSet = true; m_cause = value; }

    /**
     * <p>The cause of the failure. This information is generated by the system and can
     * be useful for diagnostic purposes.</p> <note>If <b>cause</b> is set to
     * OPERATION_NOT_PERMITTED, the decision failed because it lacked sufficient
     * permissions. For details and example IAM policies, see <a
     * href="http://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
     * IAM to Manage Access to Amazon SWF Workflows</a>.</note>
     */
    inline void SetCause(StartTimerFailedCause&& value) { m_causeHasBeenSet = true; m_cause = value; }

    /**
     * <p>The cause of the failure. This information is generated by the system and can
     * be useful for diagnostic purposes.</p> <note>If <b>cause</b> is set to
     * OPERATION_NOT_PERMITTED, the decision failed because it lacked sufficient
     * permissions. For details and example IAM policies, see <a
     * href="http://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
     * IAM to Manage Access to Amazon SWF Workflows</a>.</note>
     */
    inline StartTimerFailedEventAttributes& WithCause(const StartTimerFailedCause& value) { SetCause(value); return *this;}

    /**
     * <p>The cause of the failure. This information is generated by the system and can
     * be useful for diagnostic purposes.</p> <note>If <b>cause</b> is set to
     * OPERATION_NOT_PERMITTED, the decision failed because it lacked sufficient
     * permissions. For details and example IAM policies, see <a
     * href="http://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
     * IAM to Manage Access to Amazon SWF Workflows</a>.</note>
     */
    inline StartTimerFailedEventAttributes& WithCause(StartTimerFailedCause&& value) { SetCause(value); return *this;}

    /**
     * <p>The ID of the <code>DecisionTaskCompleted</code> event corresponding to the
     * decision task that resulted in the <code>StartTimer</code> decision for this
     * activity task. This information can be useful for diagnosing problems by tracing
     * back the chain of events leading up to this event.</p>
     */
    inline long long GetDecisionTaskCompletedEventId() const{ return m_decisionTaskCompletedEventId; }

    /**
     * <p>The ID of the <code>DecisionTaskCompleted</code> event corresponding to the
     * decision task that resulted in the <code>StartTimer</code> decision for this
     * activity task. This information can be useful for diagnosing problems by tracing
     * back the chain of events leading up to this event.</p>
     */
    inline void SetDecisionTaskCompletedEventId(long long value) { m_decisionTaskCompletedEventIdHasBeenSet = true; m_decisionTaskCompletedEventId = value; }

    /**
     * <p>The ID of the <code>DecisionTaskCompleted</code> event corresponding to the
     * decision task that resulted in the <code>StartTimer</code> decision for this
     * activity task. This information can be useful for diagnosing problems by tracing
     * back the chain of events leading up to this event.</p>
     */
    inline StartTimerFailedEventAttributes& WithDecisionTaskCompletedEventId(long long value) { SetDecisionTaskCompletedEventId(value); return *this;}

  private:
    Aws::String m_timerId;
    bool m_timerIdHasBeenSet;
    StartTimerFailedCause m_cause;
    bool m_causeHasBeenSet;
    long long m_decisionTaskCompletedEventId;
    bool m_decisionTaskCompletedEventIdHasBeenSet;
  };

} // namespace Model
} // namespace SWF
} // namespace Aws
