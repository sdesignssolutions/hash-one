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
  * @file DVBSChannelScanParameters.h
  * @brief About DVBSChannelScanParameters class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.19(Page:236)
  *
  */
#ifndef _hash_one_oipfbase_dvbschannelscanparameters_h_
#define _hash_one_oipfbase_dvbschannelscanparameters_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/ChannelScanParameters.h"

namespace HASH {
namespace ONE {

typedef class DVBSChannelScanParametersClass* DVBSChannelScanParameters;

namespace DVBSChannelScanParametersConstants {
   ///< \enum of ModulationModes enumeration
   typedef enum {
      MODULATION_MODE_QPSK     = 1,
      MODULATION_MODE_8PSK     = 2,
      MODULATION_MODE_QAM16    = 4,
   }ModulationModesEnum;

   ///< \enum of OFDM enumeration
   typedef enum {
      POLARIZATION_HORIZONTAL    = 1, /// OFDM mode 1K
      POLARIZATION_VERTICAL      = 2, /// OFDM mode 2K
      POLARIZATION_RIGHT_HANDED  = 4, /// OFDM mode 4K
      POLARIZATION_LEFT_HANDED   = 8, /// OFDM mode 8K
   }PolarizationEnum;
};

/// @class DVBSChannelScanParametersClass
/// @brief The DVBSChannelScanParameters class represents the parameters needed to perform a channel scan on a DVB-S or DVB-S2 network. 
/// This class implements the interface defined by ChannelScanParameters, with the following additions.   The properties that are undefined when 
/// performing startScan() are considered to be auto detected.
class DVBSChannelScanParametersClass : public ChannelScanParametersClass {
   private:
      /// a private variable
      /// The start frequency of the scan, in kHz
      Integer m_startFrequency;

      /// a private variable
      /// The end frequency of the scan, in kHz
      Integer m_endFrequency;

      /// a private variable
      /// The modulation modes to be scanned. Valid values are declared in DVBSChannelScanParametersConstants::ModulationModesEnum\n
      /// More than one of these values may be ORed together in order to indicate that more than one modulation mode should be scanned
      Integer m_modulationModes;

      /// a private variable
      /// A comma-separated list of the symbol rates to be scanned, in symbols/sec
      String m_symbolRate;

      /// a private variable
      /// The modulation modes to be scanned. Valid values are declared in DVBSChannelScanParametersConstants::PolarizationEnum\n
      /// More than one of these values may be ORed together in order to indicate that more than one modulation mode should be scanned
      Integer m_polarization;

      /// a private variable
      /// The code rate, e.g. “3/4” or “5/6”
      String m_codeRate;

      /// a private variable
      /// The orbitalPosition property is used to resolve DiSEqC switch/motor. The value is the orbital position of the satellite, negative value 
      /// for west, positive value for east. For example, Astra 19.2 East would have orbitalPosition 19.2. Thor 0.8 West would have orbitalPosition -0.8
      Number m_orbitalPosition;

      /// a private variable
      /// The network ID of the network to be scanned, or undefined if all networks should be scanned
      Integer m_networkId;

   public:
     /// @brief To initialize all the properties of DVBSChannelScanParametersClass class
     virtual DVBSChannelScanParametersClass() {
     };

     /// @brief To deinitialize all the properties of DVBSChannelScanParametersClass class
     virtual ~DVBSChannelScanParametersClass() {};
};

}
}

#endif //_hash_one_oipfbase_dvbschannelscanparameters_h_

