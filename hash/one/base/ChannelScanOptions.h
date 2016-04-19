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
  * @file ChannelScanOptions.h
  * @brief About ChannelScanOptions class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.16(Page:234)
  *
  */
#ifndef _hash_one_oipfbase_channelscanoptions_h_
#define _hash_one_oipfbase_channelscanoptions_h_

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

typedef class ChannelScanOptionsClass* ChannelScanOptions;

/// @class ChannelScanOptionsClass
/// @brief The ChannelScanOptionsClass class represents a list of favourite channels. See Annex K for the definition of the collection template
class ChannelScanOptionsClass {
   private:
      /// The types of channel that should be discovered during the scan. Valid values are TYPE_RADIO, TYPE_TV, or TYPE_OTHER or 
      /// TYPE_ALL as defined in section 7.13.11.1\n
      /// Refer: ChannelConstants::ChannelTypeEnum
      Integer m_channelType;

      /// If true, any existing channels in the channel list managed by the OITF SHALL be removed and the new channel list SHALL 
      /// consist only of channels found during the channel scan operation. If false, any channels discovered during the channel scan 
      /// SHALL be added to the existing channel list
      Boolean m_replaceExisting;

   public:
     /// @brief To initialize all the properties of ChannelScanOptionsClass class
     virtual ChannelScanOptionsClass() {
        this->m_channelType   = static_cast<int>(ChannelConstants::TYPE_ALL);
        this->replaceExisting = false;
     };

     /// @brief To initialize all the properties of ChannelScanOptionsClass class
     virtual ChannelScanOptionsClass(Integer channelType, Boolean replaceExisting) {
        this->m_channelType   = channelType;
        this->replaceExisting = replaceExisting;
     };

     /// @brief To deinitialize all the properties of ChannelScanOptionsClass class
     virtual ~ChannelScanOptionsClass() {};
};

}
}

#endif //_hash_one_oipfbase_channelscanoptions_h_

