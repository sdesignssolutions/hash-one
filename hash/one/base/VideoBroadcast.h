/*
Copyright [2016] [sdesignssolutions - ssundaramp@rediffmail.com]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
  *
#################################################\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~################~~~~~########\n
##########~~~####~~~###############~~~~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~########~~~#~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~#######~~~##~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~##################~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~#############~~~~~~~~~~~~~###\n
##########~~~####~~~#############~~~~~~~~~~~~~###\n
#################################################\n
  *
  * Project: HASH::ONE (HbbTV Application SHrink OIPF Native Extension layer)
  *
  * Author(s): ssundaramp@rediffmail.com
  *
  * @file VideoBroadcast.h
  * @brief About VideoBroadcast class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.1(Page:189)
  *
  */
#ifndef _hash_one_oipfbase_videobroadcast_h_
#define _hash_one_oipfbase_videobroadcast_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/Channel.h"
#include "base/ChannelList.h"
#include "base/FavouriteList.h"
#include "base/FavouriteListCollection.h"
#include "base/ChannelScanParameters.h"
#include "base/ChannelScanOptions.h"

namespace HASH {
namespace ONE {

typedef class VideoBroadcastClass* VideoBroadcast;

namespace VideoBroadcastConstants {
   ///< \enum of ChannelChangeErrorState enumeration
   typedef enum {
      CHANNEL_ERROR_NOT_SUPPORTED_BY_TUNER                  = 0,   /// channel not supported by tuner
      CHANNEL_ERROR_CANNOT_TUNED_TO_GIVEN_TS                = 1,   /// cannot tune to given transport stream (e.g. no signal)
      CHANNEL_ERROR_TUNER_LOCKED_BY_OTHER_OBJECT            = 2,   /// tuner locked by other object.
      CHANNEL_ERROR_PARENTAL_LOCK_ON_CHANNEL                = 3,   /// parental lock on channel.
      CHANNEL_ERROR_ENCRYPTED_CHANNEL                       = 4,   /// encrypted channel, key/module missing.
      CHANNEL_ERROR_UNKNOWN_CHANNEL                         = 5,   /// unknown channel (e.g. can’t resolve DVB or ISDB triplet).
      CHANNEL_ERROR_CHANNEL_SWITCH_INTERRUPTED              = 6,   /// channel switch interrupted (e.g. because another channel switch was activated before the previous one completed).
      CHANNEL_ERROR_RECORDING_IS_GOING                      = 7,   /// channel cannot be changed, because it is currently being recorded.
      CHANNEL_ERROR_CANNOT_RESOLVE_URI                      = 8,   /// cannot resolve URI of referenced IP channel.
      CHANNEL_ERROR_INSUFFICIENT_BANDWIDTH                  = 9,   /// insufficient bandwidth.
      CHANNEL_ERROR_FAVOURITE_OR_CHANNEL_LIST_UNAVAILABLE   = 10,  /// channel cannot be changed by nextChannel()/prevChannel() methods either because the OITF does not maintain a favourites or channel list or because the video/broadcast object is in the Unrealized state
      CHANNEL_ERROR_INSUFFICIENT_RESOURCES                  = 11,  /// insufficient resources are available to present the given channel (e.g. a lack of available codec resources).
      CHANNEL_ERROR_SPECIFIED_CHANNEL_NOT_FOUND_IN_TS       = 12,  /// specified channel not found in transport stream.
      CHANNEL_ERROR_UNIDENTIFIED_ERROR                      = 100, /// unidentified error.
   }ChannelChangeErrorStateEnum;

   ///< \enum of PlayState enumeration
   typedef enum {
      VIDEO_BROADCAST_PLAY_STATE_UNREALIZED   = 0,   /// the application has not made a request to start presenting a channel or has stopped presenting a channel and released any resources. The content of the video/broadcast object should be transparent but if not shall be an opaque black rectangle. Control of media presentation is under the control of the OITF, as defined in section H.2.
      VIDEO_BROADCAST_PLAY_STATE_CONNECTING   = 1,   /// the terminal is connecting to the media source in order to begin playback. Objects in this state may be buffering data in order to start playback. Control of media presentation is under the control of the application, as defined in section H.2. The content of the video/broadcast object is implementation dependent
      VIDEO_BROADCAST_PLAY_STATE_PRESENTING   = 2,   /// the media is currently being presented to the user. The object is in this state regardless of whether the media is playing at normal speed, paused, or playing in a trick mode (e.g. at a speed other than normal speed). Control of media presentation is under the control of the application, as defined in section H.2. The video/broadcast object contains the video being presented.
      VIDEO_BROADCAST_PLAY_STATE_STOPPED      = 3,   /// the terminal is not presenting media, either inside the video/broadcast object or in the logical video plane. The logical video plane is disabled. The content of the video/broadcast object SHALL be an opaque black rectangle. Control of media presentation is under the control of the application, as defined in section H.2
   }PlayStateEnum;
};

/// @brief The function that is called when a request to switch a tuner to another channel resulted in an error preventing the broadcasted content 
/// from being rendered. The specified function is called with the arguments channel and errorState. This function may be called either in response 
/// to a channel change initiated by the application, or a channel change initiated by the OITF (see section 7.13.1.1). These arguments are defined 
/// as follows:\n\n
///  channel – the Channel object to which a channel switch was requested, but for which the error occurred. This object SHALL have the same 
///     properties as the channel that was requested, except that for channels of type ID_DVB_* the values for the onid and tsid properties SHALL 
///     be extracted from the transport stream when one was found (e.g. when errorState is 12)\n
///  errorState – error code detailing the type of error [Possible values are defined in VideoBroadcastConstants::ChannelChangeErrorState]\n
typedef void (*onChannelChangeError)(Channel channel, Number errorState);

/// @brief The function that is called when the play state of the video/broadcast object changes. This function may be called either in response 
/// to an action initiated by the application, an action initiated by the OITF or an error (see section 7.13.1.1).  The specified function is called with 
/// the arguments state and error. These arguments are defined as follows:\n\n
///  state – the new state of the video/broadcast object. Valid values are defined in VideoBroadcastConstants::PlayStateEnum.\n
///  error – error code detailing the type of error [Possible values are defined in VideoBroadcastConstants::ChannelChangeErrorState]\n
typedef void (*onPlayStateChange)(Number state, Number error);

/// @brief The function that is called when a request to switch a tuner to another channel has successfully completed. This function may be called 
/// either in response to a channel change initiated by the application, or a channel change initiated by the OITF (see section 7.13.1.1). The specified 
/// function is called with argument channel, which is defined as follows:\n\n
///  state – channel – the channel to which the tuner switched. This object SHALL have the same properties with the same values as the 
///     currentChannel object (see section 7.13.7).\n
typedef void (*onChannelChangeSucceeded)(Channel channel);

/// @brief The function that is called when the value of fullScreen changes\n
typedef void (*onFullScreenChange)();

/// @brief The function that is called when the programmes property has been updated with new programme information, e.g. when the current 
/// broadcast programme is finished and a new one has started. The specified function is called with no arguments\n
typedef void (*onProgrammesChanged)();

/// @class VideoBroadcastClass
/// @brief The VideoBroadcastClass class provides the entry point for applications to get information about the list of channels available
class VideoBroadcastClass {
   public:
     /// @brief To initialize all the properties of VideoBroadcastClass class
     virtual VideoBroadcastClass() {};

     /// @brief To deinitialize all the properties of VideoBroadcastClass class
     virtual ~VideoBroadcastClass() {};

     /// @brief The width of the area used for rendering the video object. This property is only writable if property fullScreen has value 
     /// false. Changing the width property corresponds to changing the width property through the HTMLObjectElement interface, and 
     /// must have the same effect as changing the width through the DOM Level 2 Style interfaces (i.e. CSS2Properties interface style.width), 
     /// at least for values specified in pixels.
     /// @return returns the width of broadcast video
     virtual Integer getWidth() { return 0; };

     /// @brief The width of the area used for rendering the video object. This property is only writable if property fullScreen has value 
     /// false. Changing the width property corresponds to changing the width property through the HTMLObjectElement interface, and 
     /// must have the same effect as changing the width through the DOM Level 2 Style interfaces (i.e. CSS2Properties interface style.width), 
     /// at least for values specified in pixels.
     /// @param width - Width of the broadcast video
     /// @return void
     virtual void setWidth(Integer width) { return; };

     /// @brief The height of the area used for rendering the video object. This property is only writable if property fullScreen has value 
     /// false. Changing the height property corresponds to changing the height property through the HTMLObjectElement interface, and 
     /// must have the same effect as changing the height through the DOM Level 2 Style interfaces (i.e. CSS2Properties interface style.height), 
     /// at least for values specified in pixels
     /// @return returns the height of broadcast video
     virtual Integer getHeight() { return 0; };

     /// @brief The height of the area used for rendering the video object. This property is only writable if property fullScreen has value 
     /// false. Changing the height property corresponds to changing the height property through the HTMLObjectElement interface, and 
     /// must have the same effect as changing the height through the DOM Level 2 Style interfaces (i.e. CSS2Properties interface style.height), 
     /// at least for values specified in pixels
     /// @param height - Height of the broadcast video
     /// @return void
     virtual void setHeight(Integer height) { return; };

     /// @brief Returns true if this video object is in full-screen mode, false otherwise. The default value is false
     /// @return returns either true or false
     virtual Boolean isFullScreen() { return false; };

     /// @brief Setting the value of the data property SHALL have no effect on the video/broadcast object. If this property is read, the value 
     /// returned SHALL always be the empty string
     /// @return returns the height of broadcast video
     virtual String getData() { return ""; };

     /// @brief Setting the value of the data property SHALL have no effect on the video/broadcast object. If this property is read, the value 
     /// returned SHALL always be the empty string
     /// @param data - data value
     /// @return returns the height of broadcast video
     virtual void setData(String data) { return ""; };

     /// @brief The current play state of the video/broadcast object. Valid values are defined in VideoBroadcastConstants::PlayStateEnum
     /// @return returns the state of broadcast video
     virtual Integer getPlayState() { return 0; };

     /// @brief Returns the channel line-up of the tuner in the form of a ChannelConfig object as defined in section 7.13.9. The method SHALL 
     /// return the value null if the channel list is not (partially) managed by the OITF (i.e., if the channel list information is managed entirely in 
     /// the network)
     /// @return returns the ChannelConfig object
     virtual ChannelConfig getChannelConfig() { return NULL; };

     /// @brief If the video/broadcast object is in the unrealized state and video from exactly one channel is currently being presented by the 
     /// OITF then this binds the video/broadcast object to that video.  If the video/broadcast object is in the stopped state then this restarts 
     /// presentation of video and audio from the current channel under the control of the video/broadcast object. If video from more than one 
     /// channel is currently being presented by the OITF then this binds the video/broadcast object to the channel whose audio is being presented.
     /// If there is no channel currently being presented, or binding to the necessary resources to play the channel through the video/broadcast 
     /// object fails for whichever reason, the OITF SHALL dispatch an event to the onPlayStateChange listener(s) whereby the state parameter 
     /// is given value 0 (“unrealized”) and the error parameter is given the appropriate error code.  Calling this method from any other states than 
     /// the unrealized or stopped states SHALL have no effect.  See section 7.13.1.1 for more information of its usage.  NOTE: Returning a Channel 
     /// object from this method does not guarantee that video or audio from that channel is being presented. Applications should listen for the 
     /// video/broadcast object entering state 2 (“presenting”) in order to determine when audio or video is being presented.
     /// @return returns the Channel object
     virtual Channel bindToCurrentChannel() { return NULL; };

     /// @brief Creates a Channel object of the specified idType. This method is typically used to create a Channel object of type ID_DVB_SI_DIRECT. 
     /// The Channel object can subsequently be used by the setChannel() method to switch a tuner to this channel, which may or may not be part 
     /// of the channel list in the OITF. The resulting Channel object represents a locally defined channel which, if not already present there, does not 
     /// get added to the channel list accessed through the ChannelConfig class (see section 7.13.9).  Valid value for idType include: ID_DVB_SI_DIRECT. 
     /// For other values this behaviour is not specified.  If the channel of the given type cannot be created or the delivery system descriptor is not valid, 
     /// the method SHALL return null.  If the channel of the given type can be created and the delivery system descriptor is valid, the method SHALL 
     /// return a Channel object whereby at a minimum the properties with the same names (i.e. idType, dsd and sid) are given the same value as 
     /// argument idType, dsd and sid of the createChannelObject method.
     /// @param idType - The type of channel, as indicated by one of the ID_* constants defined in section 7.13.11.1. Valid values for idType 
     /// include: ID_DVB_SI_DIRECT. For other values this behaviour is not specified
     /// @param dsd - The delivery system descriptor (tuning parameters) represented as a string whose characters shall be restricted to the 
     /// ISO Latin-1 character set. Each character in the dsd represents a byte of a delivery system descriptor as defined by DVB-SI [EN 300 468] 
     /// section 6.2.13, such that a byte at position "i" in the delivery system descriptor is equal the Latin-1 character code of the character at position "i" 
     /// in the dsd
     /// @param sid - The service ID, which must be within the range of 1 to 65535
     /// @return returns the Channel object
     virtual Channel createChannelObject(Integer idType, String dsd, Integer sid) { return NULL; };

     /// @brief Requests the OITF to switch a (logical or physical) tuner to the channel specified by channel and render the received broadcast content 
     /// in the area of the browser allocated for the video/broadcast object
     /// @param channel - The channel to which a switched is requested
     /// @param trickplay - Optional flag indicating whether resources SHOULD be allocated to support trick play
     /// @param contentAccessDescriptorURL - Optional argument containing a Content Access Streaming descriptor
     /// @return void
     virtual void setChannel(Channel channel, Boolean trickplay, String contentAccessDescriptorURL) { return ; };

     /// @brief Requests the OITF to switch the tuner that is currently in use by the video/broadcast object to the channel that precedes the current 
     /// channel in the active favourite list, or, if no favourite list is currently selected, to the previous channel in the channel list. If it has reached the start 
     /// of the favourite/channel list, it SHALL cycle to the last channel in the list.
     /// @return void
     virtual void prevChannel() { return ; };

     /// @brief Requests the OITF to switch the tuner that is currently in use by the video/broadcast object to the channel that succeeds the current channel 
     /// in the active favourites list, or, if no favourite list is currently selected, to the next channel in the channel list. If it has reached the end of the 
     /// favourite/channel list, it SHALL cycle to the first channel in the list.
     /// @return void
     virtual void nextChannel() { return ; };

     /// @brief Sets the rendering of the video content to full-screen (fullscreen = true) or windowed (fullscreen = false) mode (as per [Req. 5.7.1.c] 
     /// of [CEA-2014-A]). If this indicates a change in mode, this SHALL result in a change of the value of property fullScreen. Changing the mode 
     /// SHALL NOT affect the z-index of the video object
     /// @param fullscreen - Boolean to indicate whether video content should be rendered full-screen or not
     /// @return void
     virtual void setFullScreen(Boolean fullscreen) { return ; };

     /// @brief Adjusts the volume of the currently playing media to the volume as indicated by volume. Allowed values for the volume argument are 
     /// all the integer values starting with 0 up to and including 100. A value of 0 means the sound will be muted. A value of 100 means that the 
     /// volume will become equal to current “master” volume of the device, whereby the “master” volume of the device is the volume currently 
     /// set for the main audio output mixer of the device. All values between 0 and 100 define a linear increase of the volume as a percentage of the 
     /// current master volume, whereby the OITF SHALL map it to the closest volume level supported by the platform.  The method returns true if 
     /// the volume has changed. Returns false if the volume has not changed. Applications MAY use the getVolume() method to retrieve the actual 
     /// volume set
     /// @param volume - Integer value between 0 up to and including 100 to indicate volume level
     /// @return The method returns true if the volume has changed. Returns false if the volume has not changed
     virtual Boolean setVolume( Integer volume ) { return false; };

     /// @brief Returns the actual volume level set; for systems that do not support individual volume control of players, this method will have no 
     /// effect and will always return 100
     /// @return returns the volume level
     virtual Integer getVolume() { return 0; };

     /// @brief Releases the decoder/tuner used for displaying the video broadcast inside the video/broadcast object, stopping any form of visualization 
     /// of the video inside the video/broadcast object and releasing any other associated resources.  If the object was created with an allocationMethod 
     /// of STATIC_ALLOCATION, the releasing of resources shall change this to DYNAMIC_ALLOCATION
     /// @return void
     virtual void release() { return ; };

     /// @brief Stop presenting broadcast video. If the video/broadcast object is in any state other than the unrealized state, it SHALL transition to the 
     /// stopped state and stop video and audio presentation. This SHALL have no effect on access to non-media broadcast resources such as EIT 
     /// information.  Calling this method from the unrealized state SHALL have no effect
     /// @return void
     virtual void stop() { return ; };

     /// @brief The collection of programmes available on the currently tuned channel. This list is a ProgrammeCollection as defined in section 7.16.3 
     /// and is ordered by start time, so index 0 will always refer to the present programme
     /// @return returns the ProgrammeCollection object
     virtual ProgrammeCollection getProgrammeCollection() { return NULL; };

     /// @brief The channel currently being presented by this embedded object if the user has given permission to share this information, possibly 
     /// through a mechanism outside the scope of this specification. If no channel is being presented, or if this information is not visible to the caller, 
     /// the value of this property SHALL be null.  The value of this property is not affected during timeshift operations and SHALL reflect the value 
     /// prior to the start of a timeshift operation, for both local and network timeshift resources
     /// @return returns the Channel object
     virtual Channel getCurrentChannel() { return NULL; };

     /// @brief Register the event listener for onChannelChangeError()
     /// @param listener - Listener of onChannelChangeError()
     /// @return void
     virtual void addChannelChangeErrorListener(onChannelChangeError listener) {};

     /// @brief Register the event listener for onPlayStateChange()
     /// @param listener - Listener of onPlayStateChange()
     /// @return void
     virtual void addPlayStateChangeListener(onPlayStateChange listener) {};

     /// @brief Register the event listener for onChannelChangeSucceeded()
     /// @param listener - Listener of onChannelChangeSucceeded()
     /// @return void
     virtual void addChannelChangeSucceededListener(onChannelChangeSucceeded listener) {};

     /// @brief Register the event listener for onFullScreenChange()
     /// @param listener - Listener of onFullScreenChange()
     /// @return void
     virtual void addFullScreenChangeListener(onFullScreenChange listener) {};

     /// @brief Register the event listener for onProgrammesChanged()
     /// @param listener - Listener of onProgrammesChanged()
     /// @return void
     virtual void addProgrammesChangedListener(onProgrammesChanged listener) {};
};

}
}

#endif //_hash_one_oipfbase_videobroadcast_h_

