# Copyright 2019-2020 CERN and copyright holders of ALICE O2.
# See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
# All rights not expressly granted are reserved.
#
# This software is distributed under the terms of the GNU General Public
# License v3 (GPL Version 3), copied verbatim in the file "COPYING".
#
# In applying this license CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization
# or submit itself to any jurisdiction.

o2_add_test_root_macro(CheckDigitsITS3.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckClustersITS3.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckTracksITS3.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckDCA.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                                             O2::Steer
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CreateDictionariesITS3.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(buildMatBudLUT.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckHits.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckDigitsDensity.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckClusterSize.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CompareClusterSize.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckSuperAlpideSegment.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckSuperAlpideSegmentTrans.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CompareClustersAndDigits.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)

o2_add_test_root_macro(CheckROFs.C
                       PUBLIC_LINK_LIBRARIES O2::ITSBase
                                             O2::ITS3Base
                                             O2::ITSMFTBase
                                             O2::ITSMFTSimulation
                                             O2::ITS3Simulation
                                             O2::ITS3Reconstruction
                                             O2::MathUtils
                                             O2::SimulationDataFormat
                                             O2::DetectorsBase
                       LABELS its3 COMPILE_ONLY)
