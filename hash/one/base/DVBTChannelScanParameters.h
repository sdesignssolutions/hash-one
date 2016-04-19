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
  * @file DVBTChannelScanParameters.h
  * @brief About DVBTChannelScanParameters class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.18(Page:235)
  *
  */
#ifndef _hash_one_oipfbase_dvbtchannelscanparameters_h_
#define _hash_one_oipfbase_dvbtchannelscanparameters_h_

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

typedef class DVBTChannelScanParametersClass* DVBTChannelScanParameters;

namespace DVBTChannelScanParametersConstants {
   ///< \enum of ModulationModes enumeration
   typedef enum {
      MODULATION_MODE_QPSK     = 1,
      MODULATION_MODE_QAM16    = 4,
      MODULATION_MODE_QAM32    = 8,
      MODULATION_MODE_QAM64    = 16,
      MODULATION_MODE_QAM128   = 32,
      MODULATION_MODE_QAM256   = 64,
   }ModulationModesEnum;

   ///< \enum of OFDM enumeration
   typedef enum {
      OFDM_MODE1K,  /// OFDM mode 1K
      OFDM_MODE2K,  /// OFDM mode 2K
      OFDM_MODE4K,  /// OFDM mode 4K
      OFDM_MODE8K,  /// OFDM mode 8K
      OFDM_MODE16K, /// OFDM mode 16K
      OFDM_MODE32K, /// OFDM mode 32K
   }OFDMEnum;

   ///< \enum of Bandwidth enumeration
   typedef enum {
      BAND_1_7MHZ,  /// 1.7 MHz bandwidth
      BAND_5MHz,    /// 5 MHz bandwidth
      BAND_6MHz,    /// 6 MHz bandwidth
      BAND_7MHz,    /// 7 MHz bandwidth
      BAND_8MHz,    /// 8 MHz bandwidth
      BAND_10MHz,   /// 10 MHz bandwidth
   }BandwidthEnum;
};

/// @class DVBTChannelScanParametersClass
/// @brief The DVBTChannelScanParametersClass class represents the parameters needed to perform a channel scan on a DVB-T or DVB-T2 network. 
/// This class implements the interface defined by ChannelScanParameters, with the following additions.   The properties that are undefined when 
/// performing startScan() are considered to be auto detected.
class DVBTChannelScanParametersClass : public ChannelScanParametersClass {
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
      /// The Orthogonal Frequency Division Multiplexing (OFDM) for the indicating frequency. Valid values are declared 
      /// in DVBTChannelScanParametersConstants::OFDMEnum\n
      String m_ofdm;

      /// a private variable
      /// The modulation modes to be scanned. Valid values are declared in DVBTChannelScanParametersConstants::ModulationModesEnum\n
      /// More than one of these values may be ORed together in order to indicate that more than one modulation mode should be scanned
      Integer m_modulationModes;

      /// a private variable
      /// The expected bandwidth. Valid values are declared in DVBTChannelScanParametersConstants::BandwidthEnum
      String m_bandwidth;

   public:
     /// @brief To initialize all the properties of DVBTChannelScanParametersClass class
     virtual DVBTChannelScanParametersClass() {
     };

     /// @brief To deinitialize all the properties of DVBTChannelScanParametersClass class
     virtual ~DVBTChannelScanParametersClass() {};
};

}
}

#endif //_hash_one_oipfbase_dvbtchannelscanparameters_h_

