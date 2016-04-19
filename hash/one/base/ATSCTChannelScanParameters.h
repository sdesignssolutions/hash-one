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
  * @file ATSCTChannelScanParameters.h
  * @brief About ATSCTChannelScanParameters class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.22(Page:241)
  *
  */
#ifndef _hash_one_oipfbase_atsctchannelscanparameters_h_
#define _hash_one_oipfbase_atsctchannelscanparameters_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"

namespace HASH {
namespace ONE {

typedef class ATSCTChannelScanParametersClass* ATSCTChannelScanParameters;

namespace ATSCTChannelScanParametersConstants {
   ///< \enum of ModulationModes enumeration
   typedef enum {
      MODULATION_MODE_2VSB    = 2,
      MODULATION_MODE_4VSB    = 4,
      MODULATION_MODE_8VSB    = 8,
      MODULATION_MODE_16VSB   = 16,
   }ModulationModesEnum;
};

/// @class ATSCTChannelScanParametersClass
/// @brief The ATSCTChannelScanParameters class represents the parameters needed to perform a channel scan on an ATSC-T network
/// This class implements the interface defined by ChannelScanParameters, with the following additions.   The properties that are undefined when 
/// performing startScan() are considered to be auto detected.
class ATSCTChannelScanParametersClass : public ChannelScanParametersClass {
   private:
      /// a private variable
      /// The start frequency of the scan, in kHz
      Integer m_startFrequency;

      /// a private variable
      /// The end frequency of the scan, in kHz
      Integer m_endFrequency;

      /// a private variable
      /// The raster size represented in kHz, typically 6000 as this is the ATSC channel separation
      Integer m_raster;

      /// a private variable
      /// The modulation modes to be scanned. Valid values are declared in ATSCTChannelScanParametersConstants::ModulationModesEnum\n
      /// More than one of these values may be ORed together in order to indicate that more than one modulation mode should be scanned
      Integer m_modulationModes;

   public:
     /// @brief To initialize all the properties of ATSCTChannelScanParametersClass class
     virtual ATSCTChannelScanParametersClass() {
     };

     /// @brief To deinitialize all the properties of ATSCTChannelScanParametersClass class
     virtual ~ATSCTChannelScanParametersClass() {};
};

}
}

#endif //_hash_one_oipfbase_atsctchannelscanparameters_h_

