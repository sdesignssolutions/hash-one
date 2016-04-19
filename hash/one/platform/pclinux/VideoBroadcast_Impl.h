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
  * @file VideoBroadcast_Impl.h
  * @brief Platform Implementation of VideoBroadcast class in PC-Linux
  *
  */
#ifndef _hash_one_pclinux_platform_videobroadcast_h_
#define _hash_one_pclinux_platform_videobroadcast_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/VideoBroadcast.h"

namespace HASH {
namespace ONE {

/// @class PCLinux_VideoBroadcastClass
/// @brief The PCLinux_VideoBroadcastClass class provides the entry point for applications to get information about the list of channels available
class PCLinux_VideoBroadcastClass : VideoBroadcastClass {
   public:
     /// @brief To initialize all the properties of PCLinux_VideoBroadcastClass class
     virtual PCLinux_VideoBroadcastClass() {};

     /// @brief To deinitialize all the properties of PCLinux_VideoBroadcastClass class
     virtual ~PCLinux_VideoBroadcastClass() {};

     /// @brief Returns the channel line-up of the tuner in the form of a ChannelConfig object as defined in section 7.13.9. The method SHALL 
     /// return the value null if the channel list is not (partially) managed by the OITF (i.e., if the channel list information is managed entirely in 
     /// the network)
     /// @return returns the ChannelConfig object
     ChannelConfig getChannelConfig();

     /// @brief The collection of programmes available on the currently tuned channel. This list is a ProgrammeCollection as defined in section 7.16.3 
     /// and is ordered by start time, so index 0 will always refer to the present programme
     /// @return returns the ProgrammeCollection object
     ProgrammeCollection getProgrammeCollection();

     /// @brief The channel currently being presented by this embedded object if the user has given permission to share this information, possibly 
     /// through a mechanism outside the scope of this specification. If no channel is being presented, or if this information is not visible to the caller, 
     /// the value of this property SHALL be null.  The value of this property is not affected during timeshift operations and SHALL reflect the value 
     /// prior to the start of a timeshift operation, for both local and network timeshift resources
     /// @return returns the Channel object
     Channel getCurrentChannel();

   private:
      ChannelConfig        m_channelConfig;
      Channel              m_currentChannel;
      ProgrammeCollection  m_programmes;
};

}
}

#endif //_hash_one_pclinux_platform_videobroadcast_h_

