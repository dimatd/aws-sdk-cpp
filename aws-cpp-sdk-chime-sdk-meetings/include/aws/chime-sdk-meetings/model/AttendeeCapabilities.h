﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/chime-sdk-meetings/ChimeSDKMeetings_EXPORTS.h>
#include <aws/chime-sdk-meetings/model/MediaCapabilities.h>
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
namespace ChimeSDKMeetings
{
namespace Model
{

  /**
   * <p>The media capabilities of an attendee, including audio, video and content.
   * </p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/chime-sdk-meetings-2021-07-15/AttendeeCapabilities">AWS
   * API Reference</a></p>
   */
  class AWS_CHIMESDKMEETINGS_API AttendeeCapabilities
  {
  public:
    AttendeeCapabilities();
    AttendeeCapabilities(Aws::Utils::Json::JsonView jsonValue);
    AttendeeCapabilities& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline const MediaCapabilities& GetAudio() const{ return m_audio; }

    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline bool AudioHasBeenSet() const { return m_audioHasBeenSet; }

    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline void SetAudio(const MediaCapabilities& value) { m_audioHasBeenSet = true; m_audio = value; }

    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline void SetAudio(MediaCapabilities&& value) { m_audioHasBeenSet = true; m_audio = std::move(value); }

    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithAudio(const MediaCapabilities& value) { SetAudio(value); return *this;}

    /**
     * <p>The audio capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithAudio(MediaCapabilities&& value) { SetAudio(std::move(value)); return *this;}


    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline const MediaCapabilities& GetVideo() const{ return m_video; }

    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline bool VideoHasBeenSet() const { return m_videoHasBeenSet; }

    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline void SetVideo(const MediaCapabilities& value) { m_videoHasBeenSet = true; m_video = value; }

    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline void SetVideo(MediaCapabilities&& value) { m_videoHasBeenSet = true; m_video = std::move(value); }

    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithVideo(const MediaCapabilities& value) { SetVideo(value); return *this;}

    /**
     * <p>The video capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithVideo(MediaCapabilities&& value) { SetVideo(std::move(value)); return *this;}


    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline const MediaCapabilities& GetContent() const{ return m_content; }

    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline bool ContentHasBeenSet() const { return m_contentHasBeenSet; }

    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline void SetContent(const MediaCapabilities& value) { m_contentHasBeenSet = true; m_content = value; }

    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline void SetContent(MediaCapabilities&& value) { m_contentHasBeenSet = true; m_content = std::move(value); }

    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithContent(const MediaCapabilities& value) { SetContent(value); return *this;}

    /**
     * <p>The content capability assigned to an attendee.</p>
     */
    inline AttendeeCapabilities& WithContent(MediaCapabilities&& value) { SetContent(std::move(value)); return *this;}

  private:

    MediaCapabilities m_audio;
    bool m_audioHasBeenSet;

    MediaCapabilities m_video;
    bool m_videoHasBeenSet;

    MediaCapabilities m_content;
    bool m_contentHasBeenSet;
  };

} // namespace Model
} // namespace ChimeSDKMeetings
} // namespace Aws
