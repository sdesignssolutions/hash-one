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
  * @file ChannelConfig.h
  * @brief About ChannelConfig class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.9(Page:218)
  *
  */
#ifndef _hash_one_oipfbase_channelconfig_h_
#define _hash_one_oipfbase_channelconfig_h_

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

typedef class ChannelConfigClass* ChannelConfig;

namespace ChannelConfigConstants {
   ///< \enum of ChannelScanEvent enumeration
   typedef enum {
      CHANNEL_SCAN_STARTED                = 0,   /// A channel scan has started
      CHANNEL_SCAN_INPROGRESS             = 1,   /// Indicates the current progress of the scan
      CHANNEL_SCAN_NEW_CHANNEL_FOUND      = 2,   /// A new channel has been found
      CHANNEL_SCAN_NEW_TRANSPONDER_FOUND  = 3, /// A new transponder has been found
      CHANNEL_SCAN_COMPLETED              = 4, /// A channel scan has completed
      CHANNEL_SCAN_ABORTED                = 5, /// A channel scan has aborted
   }ChannelScanEventEnum;
};

/// @brief This function is the DOM 0 event handler for events relating to channel scanning. On IP-only receivers, setting this property SHALL have no effect\n\n
///  scanEvent - The type of event.  Valid values are declared in ChannelConfigConstants::ChannelScanEventEnum\n
///  progress - the progress of the scan. Valid values are in the range 0 - 100, or -1 if the progress is unknown\n
///  frequency - The frequency of the transponder in kHz (for scans on RF sources only)\n
///  signalStrength - The signal strength for the current channel. Valid values are in the range 0 - 100, or -1 if the signal strength is unknown\n
///  channelNumber - The logical channel number of the channel that has been found\n
///  channelType - The type of channel that has been found. Valid values are the same as for Channel.channelType\n
///  channelCount - The total number of channels found so far during the scan\n
///  transponderCount - The total number of transponders found so far during the scan (RF sources only)\n
///  newChannel - When scanEvent equals 2, this argument provides a reference to the Channel object that represents the newly identified channel. 
///     For other scanEvent values this argument SHALL be NULL\n
typedef void (*onChannelScanEvent)(Integer scanEvent, Integer progress, Integer frequency, Integer signalStrength, Integer channelNumber, Integer channelType, Integer channelCount, Integer transponderCount, Channel newChannel);

/// @brief This function is the DOM 0 event handler for events relating to channel list updates. Upon receiving a ChannelListUpdate event, 
/// if an application has references to any Channel objects then it SHOULD dispose of them and rebuild its references. Where possible Channel 
/// objects are updated rather than removed, but their order in the ChannelConfig.all collection MAY have changed. Any lists created with 
/// ChannelConfig.createFilteredList() SHOULD be recreated in case channels have been removed
typedef void (*onChannelListUpdate)();

/// @class ChannelConfigClass
/// @brief The ChannelConfigClass class provides the entry point for applications to get information about the list of channels available
class ChannelConfigClass {
   public:
     /// @brief To initialize all the properties of ChannelConfigClass class
     virtual ChannelConfigClass() {};

     /// @brief To deinitialize all the properties of ChannelConfigClass class
     virtual ~ChannelConfigClass() {};

     /// @brief The list of channels.  If an OITF includes a platform-specific application that enables the end-user to choose a channel 
     /// to be presented from a list then all the channels in the list offered to the user by that application SHALL be included in this ChannelList.
     /// The list of channels will be a subset of all those available to the OITF. The precise algorithm by which this subset is selected will be 
     /// market and/or implementation dependent. For example;
     /// (i) If an OITF with a DVB-T tuner receives multiple versions of the same channel, one would be included in the list and the duplicates discarded
     /// (ii) An OITF with a DVB tuner will often filter services based on service type to discard those which are obviously inappropriate or impossible for 
     /// that device to present to the end-user, e.g. firmware download services.
     /// The order of the channels in the list corresponds to the channel ordering as managed by the OITF. SHALL return the value null if the channel 
     /// list is not (partially) managed by the OITF (i.e., if the channel list information is managed entirely in the network).  The properties of channels 
     /// making up the channel list SHALL be set by the OITF to the appropriate values as determined by the tables in section 8.4.3. The OITF SHALL 
     /// store all these values as part of the channel list.  Some values are set according to the data carried in the broadcast stream. In this case, the 
     /// OITF MAY set these values to undefined until such time as the relevant data has been received by the OITF, for example after tuning to the 
     /// channel. Once the data has been received, the OITF SHALL update the properties of the channel in the channel list according to the received data
     /// Note: There is no requirement for the OITF to pro-actively tune to every channel to gather such data.
     /// @return returns the ChannelList object
     virtual ChannelList getChannelList() { return NULL; };

     /// @brief A list of favourite lists. SHALL return the value null if the favourite lists are not (partially) managed by the OITF (i.e., if the favourite lists 
     /// information is managed entirely in the network)
     /// @return returns the FavouriteListCollection object
     virtual FavouriteListCollection getFavouriteLists() { return NULL; };

     /// @brief Currently active Favourite channel list object. If currentFavouriteList is undefined, no favourite filter list is currently applied.
     /// The OITF SHALL return the value null if the favourite lists are not (partially) managed by the OITF (i.e. if the favourite lists information is 
     /// managed entirely in the network)
     /// @return returns the FavouriteList object
     virtual FavouriteList getCurrentFavouriteList() { return NULL; };

     /// @brief Register the event listener for onChannelScanEvent()
     /// @param listener - Listener of onChannelScanEvent()
     /// @return void
     virtual void addChannelScanEventListener(onChannelScanEvent listener) {};

     /// @brief Register the event listener for onChannelListUpdate()
     /// @param listener - Listener of onChannelListUpdate()
     /// @return void
     virtual void addChannelListUpdateListener(onChannelListUpdate listener) {};

     /// @brief Create a filtered list of channels. Returns a subset of ChannelConfig.channelList.  The blocked, favourite and hidden 
     /// flags indicate whether a channel is included in the returned list. These flags correspond to the properties on Channel with 
     /// the same names. Each flag MAY be set to one of three values (true, false, undefined).  A channel will only be added to the 
     /// list if the values of all three flags allow it to be added.  The favouriteListID attribute is used to select a particular favouriteList that the 
     /// createFilteredList method uses as a basis of the filtering process. If favouriteListID is the empty string (i.e. “”), then the 
     /// filtering is performed on all available channels as defined by ChannelConfig.channelList
     /// @param blocked - Flag indicating whether manually blocked channels SHALL be added to the list
     /// @param favourite - Flag indicating whether favourite channels SHALL be added to the list
     /// @param hidden - Flag indicating whether hidden channels SHALL be added to the list
     /// @param favouriteListID - If the value of the favourite flag is true, indicates which favourites list SHALL be filtered upon
     /// @return returns the ChannelList object
     virtual ChannelList createFilteredList(Boolean blocked, Boolean favourite, Boolean hidden, String favouriteListID) { return NULL; };

     /// @brief Start a scan for new channels on all available sources. When each source finishes scanning, an UpdateEvent 
     /// SHALL be raised with the type CHANNELS_INVALIDATED and any channel lists for that source SHALL have been updated.
     /// On IP-only receivers, this method SHALL have no effect
     /// @param options - The options to the channel scan operation
     /// @param scanParameters - The tuning parameters to be scanned. The value of this argument SHALL be one of the classes that 
     ///      implement the ChannelScanParameters interface and SHALL NOT be an instance of the ChannelScanParameters class
     /// @return void
     virtual void startScan(ChannelScanOptions options, ChannelScanParameters scanParameters) { return; };

     /// @brief Stop a channel scan, if one is in progress. Any sources that have not finished scanning SHALL have their scans 
     /// aborted and channel line-ups for SHALL NOT be changed.  On IP-only receivers, this method SHALL have no effect
     /// @return void
     virtual void stopScan() { return; };

     /// @brief Creates a ChannelList object from the specified SD&S Broadcast Discovery Record. Channels in the returned 
     /// channel list will not be included in the channel list that can be retrieved via calls to getChannelConfig()
     /// @param bdr - An XML-encoded string containing an SD&S Broadcast Discovery Record as specified 
     /// in [OIPF_META2]. If the string is not a valid Broadcast Discovery Record, this method SHALL return null
     /// @return returns the ChannelList object
     virtual ChannelList createChannelList(String bdr) { return NULL; };

     /// @brief Creates a Channel object of the specified idType. The Channel object can subsequently be used by the 
     /// setChannel method to switch a tuner to a channel that is not part of the channel list which was conveyed by the 
     /// OITF to the server. The scope of the resulting Channel object is limited to the JavaScript environment (incl. 
     /// video/broadcast object) to which the Channel object is returned, i.e. it does not get added to the channellist available 
     /// through method getChannelConfig.  If the channel of the given idType cannot be created or the given (combination of) 
     /// arguments are not considered valid or complete, the method SHALL return null.  If the channel of the given type can be 
     /// created and arguments are considered valid and complete, the method SHALL return a Channel object whereby at a 
     /// minimum the properties with the same names are given the same value as the given arguments of the createChannelObject 
     // method. The values specified for the remaining properties of the Channel object are set to undefined
     /// @param idType - The type of channel, as indicated by one of the ID_* constants defined in section 7.13.11.1
     /// @param onid - The original network ID. Optional argument that SHALL be specified when the idType specifies a channel of type ID_DVB_* or ID_ISDB_*
     /// @param tsid - The transport stream ID. Optional argument that MAY be specified when the idType specifies a channel of type ID_DVB_* or ID_ISDB_*
     /// @param sid - The service ID. Optional argument that SHALL be specified when the idType specifies a channel of type ID_DVB_* or ID_ISDB_*
     /// @param sourceID - The source_ID. Optional argument that SHALL be specified when the idType specifies a channel of type ID_ATSC_T
     /// @param ipBroadcastID - The DVB textual service identifier of the IP broadcast service, specified in the format “ServiceName.DomainName”, or the URI of the IP broadcast service. Optional argument that SHALL be specified when the idType specifies a channel of type ID_IPTV_SDS or ID_IPTV_URI
     /// @return returns the Channel object
     virtual Channel createChannelObject(Integer idType, Integer onid, Integer tsid, Integer sid, Integer sourceID, String ipBroadcastID) { return NULL; };

     /// @brief Create an instance of one of the subclasses of the ChannelScanParameters class (or one of its subclasses). The exact 
     /// subclass that will be returned SHALL be determined by the value of the idType parameter.  Initial values of all properties on the 
     /// returned object SHALL be undefined
     /// @param idType - The type of object to be created. Valid values are given by the following constants on the Channel class (see section 7.13.11.1)\n
     /// ID_DVB_T or ID_DVB_T2 – returns an instance of the DVBTChannelScanParameters class\n
     /// ID_DVB_C or ID_DVB_C2 – returns an instance of the DVBCChannelScanParameters class\n
     /// ID_DVB_S or ID_DVB_S2 – returns an instance of the DVBSChannelScanParameters class\n
     /// ID_ATSC_T – returns an instance of the ATSCTChannelScanParameters class.\n
     /// All other values, or channel types which are not supported by the OITF, SHALL cause this method to return null
     /// @return returns the ChannelScanParameters object
     virtual ChannelScanParameters createChannelScanParametersObject(Integer idType) { return NULL; };

     /// @brief Create an instance of the ChannelScanOptions class. Initial values of all properties on the returned object SHALL be undefined
     /// @return returns the ChannelScanOptions object
     virtual ChannelScanOptions createChannelScanOptionsObject() { return NULL; };
};

}
}

#endif //_hash_one_oipfbase_channelconfig_h_

