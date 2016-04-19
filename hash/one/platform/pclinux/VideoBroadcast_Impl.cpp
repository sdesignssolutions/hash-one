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
  * @file VideoBroadcast_Impl.cpp
  * @brief Implementation of VideoBroadcast class
  *
  */

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "VideoBroadcast.h"

namespace HASH {
namespace ONE {

PCLinux_VideoBroadcastClass::PCLinux_VideoBroadcastClass()
{
   m_channelConfig  = new ChannelConfigClass();
   m_currentChannel = new ChannelClass();
   m_programmes     = new ProgrammeCollectionClass();
}

PCLinux_VideoBroadcastClass::~PCLinux_VideoBroadcastClass()
{
   delete m_channelConfig;
   delete m_currentChannel;
   delete m_programmes;
}

ChannelConfig PCLinux_VideoBroadcastClass::getChannelConfig()
{
   return m_channelConfig;
};

ProgrammeCollection PCLinux_VideoBroadcastClass::getProgrammeCollection()
{
   return m_programmes;
};

}
}

