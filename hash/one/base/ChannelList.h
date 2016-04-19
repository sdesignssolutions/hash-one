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
  * @file ChannelList.h
  * @brief About ChannelList class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.10(Page:224)
  *
  */
#ifndef _hash_one_oipfbase_channellist_h_
#define _hash_one_oipfbase_channellist_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/Channel.h"

namespace HASH {
namespace ONE {

typedef class ChannelListClass* ChannelList;

/// @class ChannelListClass
/// @brief A ChannelListClass represents a collection of Channel objects.  The ChannelListClass class supports the additional properties and methods defined below 
class ChannelListClass {
   public:
     /// @brief To initialize all the properties of ChannelListClass class
     virtual ChannelListClass() {};

     /// @brief To deinitialize all the properties of ChannelListClass class
     virtual ~ChannelListClass() {};

     /// @brief To get the number available channels in the list
     /// @return returns the number of channels available in the list
     virtual Integer length() { return 0 };

     /// @brief Return the item at position index in the collection, or null if no item is present at that position
     /// @param channelID - The index of the item that SHALL be returned
     /// @return returns the channel in the list that matches the given index, otherwise null
     virtual Channel item(Integer index) { return NULL };

     /// @brief Return the first channel in the list with the specified channel identifier. Returns null if no corresponding channel can be found
     /// @param channelID - The channel identifier of the channel to be retrieved, which is a value as defined for the ccid and ipBroadcastID properties of the Channel object as defined in section 7.13.11
     /// @return returns the first channel in the list that matches the given id, otherwise null
     virtual Channel getChannel(String channelID) { return NULL };

     /// @brief Return the first (IPTV or non-IPTV) channel in the list that matches the specified DVB or ISDB triplet (original network ID, transport stream ID, service ID).
     /// Where no channels of type ID_ISDB_* or ID_DVB_* are available, or no channel identified by this triplet are found, this method SHALL return null
     /// @param onid - The original network ID of the channel to be retrieved
     /// @param tsid - The transport stream ID of the channel to be retrieved. If set to null the client SHALL retrieve the channel defined by the combination of onid and sid. This makes it possible to retrieve the correct channel also in case a remultiplexing took place which led to a changed tsid
     /// @param sid - The service ID of the channel to be retrieved
     /// @param nid - An optional argument, indicating the network id to be used select the channel when the channel list contains more than one entry with the same onid, tsid and sid
     /// @return returns the first channel in the list that matches the given triplet, otherwise null
     virtual Channel getChannelByTriplet(Integer onid, Integer tsid, Integer sid, Integer nid) { return NULL };

     /// @brief Return the first channel in the list with the specified ATSC source ID.  Where no channels of type ID_ATSC_* are available, or no channel with the specified source ID is found in the channel list, this method SHALL return null
     /// @param sourceID - The ATSC source_ID of the channel to be returned
     /// @return returns the first channel in the list that matches with the specified ATSC source ID, otherwise null
     virtual Channel getChannelBySourceID(Integer sourceID) { return NULL };
};

}
}

#endif //_hash_one_oipfbase_channellist_h_

