// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file GPUTrackingLinkDef_Standalone.h
/// \author David Rohr

#ifdef __CLING__

#include "GPUTrackingLinkDef_O2.h"
#include "GPUTrackingLinkDef_O2_DataTypes.h"

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class o2::tpc::ClusterNative + ;
#pragma link C++ class o2::tpc::TrackTPC + ;
#pragma link C++ class o2::track::TrackParametrization < float> + ;
#pragma link C++ class o2::track::TrackParametrizationWithError < float> + ;
#pragma link C++ class o2::dataformats::RangeReference < unsigned int, unsigned short> + ;
#pragma link C++ class o2::tpc::dEdxInfo + ;
#pragma link C++ class o2::track::PID + ;

#endif
