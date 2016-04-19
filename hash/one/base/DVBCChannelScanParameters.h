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
  * @file DVBCChannelScanParameters.h
  * @brief About DVBCChannelScanParameters class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.20(Page:238)
  *
  */
#ifndef _hash_one_oipfbase_dvbcchannelscanparameters_h_
#define _hash_one_oipfbase_dvbcchannelscanparameters_h_

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

typedef class DVBCChannelScanParametersClass* DVBCChannelScanParameters;

namespace DVBCChannelScanParametersConstants {
   ///< \enum of ModulationModes enumeration
   typedef enum {
      MODULATION_MODE_QAM16     = 4,
      MODULATION_MODE_QAM32     = 8,
      MODULATION_MODE_QAM64     = 16,
      MODULATION_MODE_QAM128    = 32,
      MODULATION_MODE_QAM256    = 64,
      MODULATION_MODE_QAM1024   = 128,
      MODULATION_MODE_QAM4096   = 256,
   }ModulationModesEnum;
};

/// @class DVBCChannelScanParametersClass
/// @brief The DVBCChannelScanParameters class represents the parameters needed to perform a channel scan on a DVB-C or DVB-C2 network
/// This class implements the interface defined by ChannelScanParameters, with the following additions.   The properties that are undefined when 
/// performing startScan() are considered to be auto detected.
class DVBCChannelScanParametersClass : public ChannelScanParametersClass {
   private:
      /// a private variable
      /// The start frequency of the scan, in kHz
      Integer m_startFrequency;

      /// a private variable
      /// The end frequency of the scan, in kHz
      Integer m_endFrequency;

      /// a private variable
      /// The raster size represented in kHz (typically 7000 or 8000)
      Integer m_raster;

      /// a private variable
      /// The scan mode for scanning. A false value indicates to scan complete range, a true value indicates scan terminates when a valid 
      /// NIT is found. The frequency scan is replaced by a scan based on NIT. If networkId is set and the value of this property is set to 
      /// true the scan continues until there is a match on both
      Boolean m_startNetworkScanOnNIT;

      /// a private variable
      /// The modulation modes to be scanned. Valid values are declared in DVBCChannelScanParametersConstants::ModulationModesEnum\n
      /// More than one of these values may be ORed together in order to indicate that more than one modulation mode should be scanned
      Integer m_modulationModes;

      /// a private variable
      /// A comma-separated list of the symbol rates to be scanned, in symbols/sec
      String m_symbolRate;

      /// a private variable
      /// The network ID of the network to be scanned, or undefined if all networks should be scanned
      Integer m_networkId;

   public:
     /// @brief To initialize all the properties of DVBCChannelScanParametersClass class
     virtual DVBCChannelScanParametersClass() {
     };

     /// @brief To deinitialize all the properties of DVBCChannelScanParametersClass class
     virtual ~DVBCChannelScanParametersClass() {};
};

}
}

#endif //_hash_one_oipfbase_dvbcchannelscanparameters_h_

