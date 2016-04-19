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
  * @file Channel.h
  * @brief About Channel class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.11(Page:225)
  *
  */

#ifndef _hash_one_oipfbase_channel_h_
#define _hash_one_oipfbase_channel_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"

namespace HASH {
namespace ONE {

typedef class ChannelClass* Channel;

namespace ChannelConstants {
   ///< \enum of ChannelType enumeration
   typedef enum {
      TYPE_TV           = 0,   ///< Used in the channelType property to indicate a TV channel
      TYPE_RADIO        = 1,   ///< Used in the channelType property to indicate a radio channel
      TYPE_OTHER        = 2,   ///< Used in the channelType property to indicate that the type of the channel is unknown, or known but not of type TV or radio
      TYPE_ALL          = 128, ///< Used during channel scanning to indicate that all TV, radio and other channel types should scanned
      TYPE_HBBTV_DATA   = 256, ///< Reserved for data services defined by [TS 102 796]
   }ChannelTypeEnum;

   ///< \enum of ChannelID enumeration
   typedef enum {
      ID_ANALOG         = 0,   ///< Used in the idType property to indicate an analogue channel identified by the property ‘freq’ and optionally ‘cni’ or ‘name’
      ID_DVB_C          = 10,  ///< Used in the idType property to indicate a DVB-C channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_DVB_S          = 11,  ///< Used in the idType property to indicate a DVB-S channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_DVB_T          = 12,  ///< Used in the idType property to indicate a DVB-T channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_DVB_SI_DIRECT  = 13,  ///< Used in the idType property to indicate a channel that is identified through its delivery system descriptor as defined by DVB-SI [EN 300 468] section 6.2.13
      ID_DVB_C2         = 14,  ///< Used in the idType property to indicate a DVB-C or DVB-C2 channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_DVB_S2         = 15,  ///< Used in the idType property to indicate a DVB-S or DVB-S2 channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_DVB_T2         = 16,  ///< Used in the idType property to indicate a DVB-T or DVB-T2 channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_ISDB_C         = 20,  ///< Used in the idType property to indicate an ISDB-C channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_ISDB_S         = 21,  ///< Used in the idType property to indicate an ISDB-S channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_ISDB_T         = 22,  ///< Used in the idType property to indicate an ISDB-T channel identified by the three properties: ‘onid’, ‘tsid’, ‘sid’
      ID_ATSC_T         = 30,  ///< Used in the idType property to indicate a terrestrial ATSC channel identified by the property ‘sourceID’
      ID_IPTV_SDS       = 40,  ///< Used in the idType property to indicate an IP broadcast channel identified through SD&S by a DVB textual service identifier specified in the format “ServiceName.DomainName” as value for property ‘ipBroadcastID’, with ServiceName and DomainName as defined in [DVB-IPTV]. This idType SHALL be used to indicate Scheduled content service defined by [OIPF_PROT2]
      ID_IPTV_URI       = 41,  ///< Used in the idType property to indicate an IP broadcast channel identified by a DVB MCAST URI (i.e. dvb-mcast://) or by a URI referencing a HAS or MPEG DASH MPD (i.e. http:// or https://), as value for property ipBroadcastID
   }ChannelIdEnum;
};

/// @class ChannelClass
/// @brief ChannelClass objects typically represent channels stored in the channel list (see section 7.13.10). 
/// Channel objects may also represent locally defined channels created by an application using the 
/// createChannelObject() methods on the video/broadcast embedded object or the ChannelConfig 
/// class or the createChannelList() method on the ChannelConfig class. Accessing the channel property 
/// of a ScheduledRecording object or Recording object which is scheduled on a locally defined channel 
/// SHALL return a Channel object representing that locally defined channel.
/// Except for the hidden property, writing to the writable properties on a Channel object SHALL have no 
/// effect for Channel objects representing channels stored in the channel list. Applications SHOULD only 
/// change these writable properties of a locally defined channel before the Channel object is referenced by 
/// another object or passed to an API call as an input parameter. The effects of writing to these properties 
/// at any other time is implementation dependent.
class ChannelClass {
   private:
      /// a private variable
      /// The type of channel. The value MAY be indicated by one of the TYPE_* constants defined above. If the type of the channel 
      /// is unknown then the value SHALL be “undefined”.  NOTE: Values of this type between 256 and 511 are reserved for use by 
      /// related specifications on request by liaison
      READONLY Integer m_channelType;

      /// a private variable
      /// The type of identification for the channel, as indicated by one of the ID_* constants defined above
      READONLY Integer m_idType;

      /// a private variable
      /// Unique identifier of a channel within the scope of the OITF. The ccid is defined by the OITF and SHALL have prefix ‘ccid’: 
      /// e.g. ‘ccid:{tunerID.}majorChannel{.minorChannel}’.  Note: the format of this string is platform-dependent
      READONLY String m_ccid;

      /// a private variable
      /// Optional unique identifier of the tuner within the scope of the OITF that is able to receive the given channel
      READONLY String m_tunerID;

      /// a private variable
      /// DVB or ISDB original network ID
      READONLY Integer m_onid;

      /// a private variable
      /// The DVB or ISDB network ID
      READONLY Integer m_nid;

      /// a private variable
      /// DVB or ISDB transport stream ID
      READONLY Integer m_tsid;

      /// a private variable
      /// DVB or ISDB service ID
      READONLY Integer m_sid;

      /// a private variable
      /// ATSC source_ID value
      READONLY Integer m_sourceID;

      /// a private variable
      /// For analogue channels, the frequency of the video carrier in kHz
      READONLY Integer m_freq;

      /// a private variable
      /// For analogue channels, the VPS/PDC confirmed network identifier
      READONLY Integer m_cni;

      /// a private variable
      /// The name of the channel. Can be used for linking analog channels without CNI. Typically, it will contain the call sign of the station (e.g. 'HBO')
      String m_name;

      /// a private variable
      /// The major channel number, if assigned. Value undefined otherwise. Typically used for channels of type ID_ATSC_* or for channels of type 
      /// ID_DVB_* or ID_IPTV_SDS in markets where logical channel numbers are used
      READONLY Integer m_majorChannel;

      /// a private variable
      /// The minor channel number, if assigned. Value undefined otherwise. Typically used for channels of type ID_ATSC_*
      READONLY Integer m_minorChannel;

      /// a private variable
      /// For channels of type ID_DVB_SI_DIRECT created through createChannelObject(), this property defines the delivery system 
      /// descriptor (tuning parameters) as defined by DVB-SI [EN 300 468] section 6.2.13.  The dsd property provides a string whose 
      /// characters shall be restricted to the ISO Latin-1 character set. Each character in the dsd represents a byte of a delivery system 
      /// descriptor as defined by DVB-SI [EN 300 468] section 6.2.13, such that a byte at position "i" in the delivery system descriptor 
      /// is equal the Latin-1 character code of the character at position "i" in the dsd.  Described in the syntax of JavaScript: let sdd[] be 
      /// the byte array of a system delivery descriptor, in which sdd[0] is the descriptor_tag, then, dsd is its equivalent string, if :
      ///    dsd.length==sdd.length and
      ///    for each integer i : 0<=i<dsd.length holds: sdd[i] == dsd.charCodeAt(i)
      READONLY String m_dsd;

      /// a private variable
      /// Flag indicating whether the channel is marked as a favourite channel or not in one of the favourite lists as defined by the property favIDs
      READONLY Boolean m_favourite;

      /// a private variable
      /// The names of the favourite lists to which this channel belongs (see the favouriteLists property on the ChannelConfig class)
      READONLY StringCollection m_favIDs;

      /// a private variable
      /// Flag indicating whether the current state of the parental control system prevents the channel from being viewed (e.g. a correct 
      /// parental control pin has not been entered).  Note that this property supports the option of client-based management of parental 
      /// control without excluding server-side implementation of parental control
      READONLY Boolean m_locked;

      /// a private variable
      /// Flag indicating whether the user has manually blocked viewing of this channel. Manual blocking of a channel will treat the channel 
      /// as if its parental rating value always exceeded the system threshold.  Note that this property supports the option of client-based 
      /// management of manual blocking without excluding server-side management of blocked channels
      READONLY Boolean m_manualBlock;

      /// a private variable
      /// If the channel has an idType of ID_IPTV_SDS, this property denotes the DVB textual service identifier of the IP broadcast service, 
      /// specified in the format “ServiceName.DomainName” with the ServiceName and DomainName as defined in [DVB-IPTV].  If the 
      /// Channel has an idType of ID_IPTV_URI, this element denotes a URI of the IP broadcast service
      READONLY String m_ipBroadcastID;

      /// a private variable
      /// If the channel has an idType of ID_IPTV_SDS, this property denotes the maximum bitrate associated to the channel
      READONLY Integer m_channelMaxBitRate;

      /// a private variable
      /// If the channel has idType ID_IPTV_SDS, this property denotes the TimeToRenegotiate associated to the channel
      READONLY Integer m_channelTTR;

      /// a private variable
      /// Flag indicating whether the channel is available to the recording functionality of the OITF. If the value of the pvrSupport property 
      /// on the application/oipfConfiguration object as defined in section 7.3.3.2 is 0, this property SHALL be false for all Channel objects
      READONLY Boolean m_recordable;

      // @{ metadata extensions
      /// a private variable
      /// The long name of the channel. If both short and long names are being transmitted, this property SHALL contain the long name of 
      /// the station (e.g. 'Home Box Office'). If the long name is not available, this property SHALL be undefined.  The value of this property 
      /// may be derived from the Name element that is a child of the BCG ServiceInformation element describing the channel, where the 
      /// length attribute of the Name element has the value ‘long’
      String m_longName;

      /// a private variable
      /// The description of the channel. If no description is available, this property SHALL be undefined.  The value of this field may be taken 
      /// from the ServiceDescription element that is a child of the BCG ServiceInformation element describing this channel
      String m_description;

      /// a private variable
      /// Flag indicating whether the receiver is currently authorised to view the channel. This describes the conditional access restrictions that 
      /// may be imposed on the channel, rather than parental control restrictions
      READONLY Boolean m_authorised;

      /// a private variable
      /// A collection of genres that describe the channel.  The value of this field may be taken from the ServiceGenre elements that are children 
      /// of the BCG ServiceInformation element describing the channel
      StringCollection m_genre;

      /// a private variable
      /// Flag indicating whether the channel SHALL be included in the default channel list
      Boolean m_hidden;

      /// a private variable
      /// Flag indicating whether the channel is a 3D channel
      READONLY Boolean m_is3D;

      /// a private variable
      /// Flag indicating whether the channel is an HD channel
      READONLY Boolean m_isHD;

      /// a private variable
      /// The URL for the default logo image for this channel.  The value of this field may be derived from the value of the first Logo element 
      /// that is a child of the BCG ServiceInformation element describing the channel. If this element specifies anything other than the URL of 
      /// an image, the value of this filed SHALL be undefined
      String m_logoURL;
      // @} end of metadata extensions

   public:
     /// @brief To initialize all the properties of ChannelClass class
     virtual ChannelClass(){};

     /// @brief To deinitialize all the properties of ChannelClass class
     virtual ~ChannelClass(){};

     /// @brief Get the value of the field referred to by fieldId that is contained in the BCG metadata for this channel. If the field does not exist, 
     /// this method SHALL return undefined
     /// @param fieldId - The name of the field whose value SHALL be retrieved
     /// @return returns the field of the respective given fieldId
     virtual String getField(String fieldId) { return "" };

     /// @brief Get the URI for the logo image for this channel. The width and height parameters specify the desired width and height of the image; 
     /// if an image of that size is not available, the URI of the logo with the closest available size not exceeding the specified dimensions SHALL 
     /// be returned. If no image matches these criteria, this method SHALL return null.  The URI returned SHALL be suitable for use as the SRC 
     /// attribute in an HTML IMG element or as a background image.  The URIs returned by this method will be derived from the values of the 
     /// Logo elements that are children of the BCG ServiceInformation element describing the channel
     /// @param width - The desired width of the image
     /// @param height - The desired height of the image
     /// @return returns the URI of the image w.r.t the given width and height
     virtual String getLogo( Integer width, Integer height ) { return "" };
};

}
}

#endif //_hash_one_oipfbase_channel_h_

