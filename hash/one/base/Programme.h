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
  * @file Programme.h
  * @brief About Programme class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.16.2(Page:267)
  *
  */

#ifndef _hash_one_oipfbase_programme_h_
#define _hash_one_oipfbase_programme_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/ParentalRatingCollection.h"

namespace HASH {
namespace ONE {

typedef class ProgrammeClass* Programme;

namespace ProgrammeConstants {
   ///< \enum of ProgrammeType enumeration
   typedef enum {
      TYPE_ID_TVA_CRID       = 0,   /// Used in the programmeIDType property to indicate that the programme is identified by its TV-Anytime CRID (Content Reference Identifier)
      TYPE_ID_DVB_EVENT      = 1,   /// Used in the programmeIDType property to indicate that the programme is identified by a DVB URL referencing a DVB-SI event as enabled by section 4.1.3 of [OIPF_META2]. OPTIONAL
      TYPE_ID_TVA_GROUP_CRID = 2,   /// Used in the programmeIDType property to indicate that the Programme object represents a group of programmes identified by a TV-Anytime group CRID
   }ProgrammeIDTypeEnum;
};

/// @class ProgrammeClass
/// @brief The Programme class represents an entry in a programme schedule.
/// Note: as described in the record( Programme programme ) method of the application/oipfRecordingScheduler object, only the programmeID 
/// property of the programme object is used to determine the programme or series that will be recorded. The other properties are solely used 
/// for annotation of the (scheduled) recording with programme metadata. The use of these metadata properties is optional. If such programme 
/// metadata is provided, it is retained in the ScheduledRecording object that is returned if the recording of the programme was scheduled successfully.
class ProgrammeClass {
   private:
      /// a variable
      /// The short name of the programme, e.g. 'Star Trek: DS9'
      String m_name;

      /// a variable
      /// The long name of the programme, e.g. 'Star Trek: Deep Space Nine'. If the long name is not available, this property will be undefined
      String m_longName;

      /// a variable
      /// The description of the programme, e.g. an episode synopsis. If no description is available, this property will be undefined
      String m_description;

      /// a variable
      /// The long description of the programme. If no description is available, this property will be undefined
      String m_longDescription;

      /// a variable
      /// The start time of the programme, measured in seconds since midnight (GMT) on 1/1/1970
      Integer m_startTime;

      /// a variable
      /// The duration of the programme (in seconds)
      Integer m_duration;

      /// a variable
      /// The identifier of the channel from which the broadcasted content is to be recorded. Specifies either a ccid or 
      /// ipBroadcastID (as defined by the Channel object in section 7.13.11)
      String m_channelID;

      /// a variable
      /// The episode number for the programme if it is part of a series. This property is undefined when the programme is not part of a series or the 
      /// information is not available
      Integer m_episode;

      /// a variable
      /// If the programme is part of a series, the total number of episodes in the series. This property is undefined when the programme is not part 
      /// of a series or the information is not available
      Integer m_totalEpisodes;

      /// a private variable
      /// Flag indicating whether the programme has 3D video
      READONLY Boolean m_is3D;

      /// a variable
      /// The unique identifier of the programme or series, e.g., a TV-Anytime CRID (Content Reference Identifier)
      String m_programmeID;

      /// a private variable
      /// The name of the channel. Can be used for linking analog channels without CNI. Typically, it will contain the call sign of the station (e.g. 'HBO')
      String m_name;

      /// a variable
      /// The type of identification used to reference the programme, as indicated by one of the ID_* constants defined above\n
      /// Refer: ProgrammeConstants::ProgrammeIDTypeEnum
      Integer m_programmeIDType;

      /// a private variable
      /// The minor channel number, if assigned. Value undefined otherwise. Typically used for channels of type ID_ATSC_*
      READONLY Integer m_minorProgramme;

      /// a private variable
      /// The TV-Anytime Instance Metadata ID for this programme
      READONLY String m_IMI;

      /// a private variable
      /// A collection of parental rating values for the programme for zero or more parental rating schemes supported by the OITF. 
      /// For instances of the Programme class created by the createProgramme() method defined in section 7.10.1.1, the initial value 
      /// of this property (upon creation of the Programme object) is an instance of the ParentalRatingCollection object (as defined in 
      /// section 7.9.5) with length 0. Parental rating values can be added to this empty readonly parental rating collection by using the 
      /// addParentalRating() method of the ParentalRatingCollection object. The ParentalRatingCollection is defined in section 7.9.5. 
      /// The related ParentalRating and ParentalRatingScheme objects are defined in section 7.9.4 and 7.9.2 respectively.  For instances 
      /// of the Programme class returned through the metadata APIs defined in section 7.12 or through the programmes property of the 
      /// video/broadcast object defined in section 7.13.3, the initial value of this property SHALL include the parental rating value(s) carried 
      /// in the metadata or DVB-SI entry describing the programme, if this information is included.\n
      /// Note that if the service provider specifies a certain parental rating (e.g. PG-13) through this property and the actual parental rating 
      /// extracted from the stream says that the content is rated PG-16, then the conflict resolution is implementation dependent
      READONLY ParentalRatingCollection m_parentalRatings;

      /// a private variable
      /// The group CRIDs associated with this programme
      READONLY StringCollection m_groupCRIDs;

      // @{ metadata extensions
      /// a private variable
      /// Reference to the broadcast channel where the programme is available.  The value of this field is derived from the serviceIDref attribute 
      /// of the Schedule element that refers to this programme
      READONLY Channel m_channel;

      /// a private variable
      /// Flag indicating whether the programme is blocked due to parental control settings or conditional access restrictions.  The blocked and 
      /// locked properties work together to provide a tri-state flag describing the status of a programme. This can best be described by the 
      /// following table:\n
      /// * if locked & blocked is false, then No parental control applies\n
      /// * if locked & blocked is true, then Item is above the parental rating threshold (or manually blocked); no PIN has been entered to view it 
      ///    and so the item cannot currently be viewed\n
      /// * if locked is true and blocked is false, then Item is above the parental rating threshold (or manually blocked); the PIN has been entered 
      ///    and so the item can be viewed\n
      /// * if locked is false and blocked is true, then Invalid combination – OITFs SHALL NOT support this combination
      READONLY Boolean m_blocked;

      /// a variable
      /// Flag indicating the type of show (live, first run, rerun, etc,).  The value of this property is determined by the child elements of the 
      /// programme’s BroadcastEvent or ScheduleEvent element from the Program Location Table. Values are determined as follows
      /// * 1 ==> The programme is live; indicated by the presence of a Live element with a value attribute set to true\n
      /// * 2 ==> The programme is a first-run show; indicated by the presence of a FirstShowing element with a value attribute set to true\n
      /// * 3 ==> The programme is a rerun; indicated by the presence of a Repeat element with a value attribute set to true.\n
      /// If none of the above conditions are met, the default value of this field SHALL be 2
      Integer m_showType;

      /// a variable
      /// Flag indicating whether subtitles or closed-caption information is available.  This flag SHALL be true if one or more BCG CaptionLanguage 
      /// elements are present in this programme’s description, false otherwise
      Boolean m_subtitles;

      /// a variable
      /// Flag indicating whether the programme has high-definition video.  This flag SHALL be true if a VerticalSize element is present in the 
      /// programme’s description and has a value greater than 576, false otherwise
      Boolean m_isHD;

      /// a variable
      /// Bitfield indicating the type of audio that is available for the programme.  The value of this field is determined by the NumOfChannels 
      /// elements in a programme’s A/V attributes. Values are determined as follows:\n
      /// * 1 ==> A mono audio stream is available (at least one AvAttributes.AudioAttributes element is present which has a child 
      ///    NumOfChannels element whose value is 1).\n
      /// * 2 ==> A stereo audio stream is available (at least one AvAttributes.AudioAttributes element is present which has a child 
      ///    NumOfChannels element whose value is 2)\n
      /// * 4 ==> A multi-channel audio stream is available (at least one AvAttributes.AudioAttributes element is present which has a child 
      ///    NumOfChannels element whose value is greater than 2)\n
      /// For programmes with multiple audio streams, these values may be ORed together
      Integer m_audioType;

      /// a variable
      /// Flag indicating whether more than one audio language is available for the programme.  This flag SHALL be true if more than one BCG 
      /// Language element is present in the programme’s description, false otherwise
      Boolean m_isMultilingual;

      /// a variable
      /// A collection of genres that describe this programme.  The value of this field is the concatenation of the values of any Name elements 
      /// that are children of Genre elements in the programme’s description
      StringCollection m_genre;

      /// a private variable
      /// Flag indicating whether the Programme has a recording associated with it (either scheduled, in progress, or completed).
      READONLY Boolean m_hasRecording;

      /// a variable
      /// Supported audio languages, indicated by their ISO.639-2 language codes as defined in [ISO 639-2].
      StringCollection m_audioLanguages;

      /// a variable
      /// Supported subtitle languages, indicated by their ISO.639-2 language codes as defined in [ISO 639-2]
      StringCollection m_subtitleoLanguages;

      /// a private variable
      /// Flag indicating whether the current state of the parental control system prevents the programme from being viewed (e.g. a correct 
      /// parental control PIN has not been entered to allow the programme to be viewed)
      READONLY Boolean m_locked;
      // @} end of metadata extensions

      // @{ recording extensions
      /// a private variable
      /// If available, this property represents the recording associated with this programme (either scheduled, in-progress or completed). 
      /// Has value undefined if this programme has no scheduled recording associated with it.
      READONLY ScheduledRecording m_recording;
      // @} end of metadata extensions

   public:
     /// @brief To initialize all the properties of ProgrammeClass class
     virtual ProgrammeClass(){};

     /// @brief To deinitialize all the properties of ProgrammeClass class
     virtual ~ProgrammeClass(){};

     // @{ metadata extensions
     /// @brief Get the value of the field referred to by fieldId that is contained in the metadata for this programme. If the field does not exist, 
     /// this method SHALL return undefined
     /// @param fieldId - The name of the field whose value SHALL be retrieved
     /// @return returns the field of the respective given fieldId
     virtual String getField(String fieldId) { return ""; };
     // @} end of metadata extensions

     // @{ dvb-si extensions
     /// @brief Get the contents of the descriptor specified by descriptorTag from the DVB SI EIT programme's descriptor loop. If more than one 
     /// descriptor with the specified tag is available for the given programme, the contents of all matching descriptors SHALL be returned in the 
     /// order the descriptors are found in the stream.  The descriptor content bytes SHALL be encoded in a string whose characters shall be restricted 
     /// to the ISO Latin-1 character set. Each character in the string represents a byte of a DVB-SI descriptor, such that a byte at position "i" in the 
     /// descriptor is equal the Latin-1 character code of the character at position "i" in the string.  Described in the syntax of JavaScript: let desc[ ] 
     /// be the byte array of a descriptor, in which desc[0] is the descriptor_tag, then, the returned string (retval in the example below) is its 
     /// equivalent string, if :\n
     ///    desc.length==retval.length and\n
     ///    for each integer i : 0<=i<desc.length holds\n
     ///    desc[i] == retval.charCodeAt(i).\n
     /// If the descriptor specified by descriptorTag and (optionally) descriptorTagExtension and privateDataSpecifier does not exist, or if the metadata 
     /// for this programme was retrieved from a source other than DVB-SI, this method SHALL return null.  If metadata for this programme has not 
     /// yet been retrieved, this method SHALL return undefined. If the OITF supports the application/oipfSearchManager object as defined in 
     /// section 7.12.1, the OITF SHALL notify applications of the availability of additional metadata via MetadataSearch events targeted at the 
     /// application/oipfSearchManager object used to retrieve the programme metadata.
     /// @param descriptorTag - The descriptor tag as specified by [EN 300 468].
     /// @param descriptorTagExtension - An optional argument giving the descriptor tag extension as specified by [EN 300 468]. This argument is mandatory when descriptorTag is 0x7f and ignored in all other cases
     /// @param privateDataSpecifier - An optional argument giving the private_data_specifier as specified by [EN 300 468]. If this argument is present, only descriptors related to the identified specifier will be returned
     /// @return returns the collection of SIDescriptors
     virtual StringCollection getSIDescriptors(Integer descriptorTag, Integer descriptorTagExtension, Integer privateDataSpecifier ) { return NULL; };
     // @} end of dvb-si extensions
};

}
}

#endif //_hash_one_oipfbase_programme_h_

