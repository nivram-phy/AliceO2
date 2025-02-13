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

#include "Mocking.h"
#include "../src/ComputingResourceHelpers.h"
#include "../src/DeviceSpecHelpers.h"
#include "../src/GraphvizHelpers.h"
#include "../src/SimpleResourceManager.h"
#include "Framework/DeviceSpec.h"
#include "Framework/WorkflowSpec.h"
#include "Headers/DataHeader.h"

#include <catch_amalgamated.hpp>
#include <sstream>

using namespace o2::framework;

// because comparing the whole thing is a pain.
void lineByLineComparision(const std::string& as, const std::string& bs)
{
  std::istringstream a(as);
  std::istringstream b(bs);

  char bufferA[1024];
  char bufferB[1024];
  while (a.good() && b.good()) {
    a.getline(bufferA, 1024);
    b.getline(bufferB, 1024);
    REQUIRE(std::string(bufferA) == std::string(bufferB));
  }
  REQUIRE(a.eof());
  REQUIRE(b.eof());
}

namespace
{
// This is how you can define your processing in a declarative way
WorkflowSpec defineDataProcessing()
{
  return {{"A", Inputs{},
           Outputs{OutputSpec{"TST", "A1"},
                   OutputSpec{"TST", "A2"}}},
          {"B",
           {InputSpec{"x", "TST", "A1"}},
           Outputs{OutputSpec{"TST", "B1"}}},
          {"C", Inputs{InputSpec{"x", "TST", "A2"}},
           Outputs{OutputSpec{"TST", "C1"}}},
          {"D",
           Inputs{InputSpec{"i1", "TST", "B1"},
                  InputSpec{"i2", "TST", "C1"}},
           Outputs{}}};
}
} // namespace

namespace
{

WorkflowSpec defineDataProcessing2()
{
  return {
    {"A",
     {},
     {
       OutputSpec{"TST", "A"},
     }},
    timePipeline({"B",
                  {InputSpec{"a", "TST", "A"}},
                  {OutputSpec{"TST", "B"}}},
                 3),
    timePipeline({"C",
                  {InputSpec{"b", "TST", "B"}},
                  {OutputSpec{"TST", "C"}}},
                 2),
  };
}
} // namespace

TEST_CASE("TestGraphviz")
{
  auto workflow = defineDataProcessing();
  std::ostringstream str;
  auto expectedResult = R"EXPECTED(digraph structs {
  node[shape=record]
  "A" [label="A"];
  "B" [label="B"];
  "C" [label="C"];
  "D" [label="D"];
}
)EXPECTED";
  GraphvizHelpers::dumpDataProcessorSpec2Graphviz(str, workflow);
  lineByLineComparision(str.str(), expectedResult);
  std::vector<DeviceSpec> devices;
  for (auto& device : devices) {
    REQUIRE(device.id != "");
  }
  auto configContext = makeEmptyConfigContext();
  auto channelPolicies = ChannelConfigurationPolicy::createDefaultPolicies(*configContext);
  auto completionPolicies = CompletionPolicy::createDefaultPolicies();
  auto callbacksPolicies = CallbacksPolicy::createDefaultPolicies();
  std::vector<ComputingResource> resources = {ComputingResourceHelpers::getLocalhostResource()};
  SimpleResourceManager rm(resources);
  DeviceSpecHelpers::dataProcessorSpecs2DeviceSpecs(workflow, channelPolicies, completionPolicies, callbacksPolicies, devices, rm, "workflow-id", *configContext);
  str.str("");
  GraphvizHelpers::dumpDeviceSpec2Graphviz(str, devices);
  lineByLineComparision(str.str(), R"EXPECTED(digraph structs {
  node[shape=record]
  "A" [label="{{}|A(2)|{<from_A_to_B>from_A_to_B|<from_A_to_C>from_A_to_C}}"];
  "B" [label="{{<from_A_to_B>from_A_to_B}|B(2)|{<from_B_to_D>from_B_to_D}}"];
  "C" [label="{{<from_A_to_C>from_A_to_C}|C(2)|{<from_C_to_D>from_C_to_D}}"];
  "D" [label="{{<from_B_to_D>from_B_to_D|<from_C_to_D>from_C_to_D}|D(2)|{}}"];
  "A":"from_A_to_B"-> "B":"from_A_to_B" [label="22000"]
  "A":"from_A_to_C"-> "C":"from_A_to_C" [label="22001"]
  "B":"from_B_to_D"-> "D":"from_B_to_D" [label="22002"]
  "C":"from_C_to_D"-> "D":"from_C_to_D" [label="22003"]
}
)EXPECTED");
}

TEST_CASE("TestGraphvizWithPipeline")
{
  auto workflow = defineDataProcessing2();
  std::ostringstream str;
  auto expectedResult = R"EXPECTED(digraph structs {
  node[shape=record]
  "A" [label="A"];
  "B" [label="B"];
  "C" [label="C"];
}
)EXPECTED";
  GraphvizHelpers::dumpDataProcessorSpec2Graphviz(str, workflow);
  lineByLineComparision(str.str(), expectedResult);
  std::vector<DeviceSpec> devices;
  for (auto& device : devices) {
    REQUIRE(device.id != "");
  }
  auto configContext = makeEmptyConfigContext();
  auto channelPolicies = ChannelConfigurationPolicy::createDefaultPolicies(*configContext);
  auto completionPolicies = CompletionPolicy::createDefaultPolicies();
  auto callbacksPolicies = CallbacksPolicy::createDefaultPolicies();
  std::vector<ComputingResource> resources = {ComputingResourceHelpers::getLocalhostResource()};
  SimpleResourceManager rm(resources);
  DeviceSpecHelpers::dataProcessorSpecs2DeviceSpecs(workflow, channelPolicies, completionPolicies, callbacksPolicies, devices, rm, "workflow-id", *configContext);
  str.str("");
  GraphvizHelpers::dumpDeviceSpec2Graphviz(str, devices);
  lineByLineComparision(str.str(), R"EXPECTED(digraph structs {
  node[shape=record]
  "A" [label="{{}|A(3)|{<from_A_to_B_t0>from_A_to_B_t0|<from_A_to_B_t1>from_A_to_B_t1|<from_A_to_B_t2>from_A_to_B_t2}}"];
  "B_t0" [label="{{<from_A_to_B_t0>from_A_to_B_t0}|B_t0(3)|{<from_B_t0_to_C_t0>from_B_t0_to_C_t0|<from_B_t0_to_C_t1>from_B_t0_to_C_t1}}"];
  "B_t1" [label="{{<from_A_to_B_t1>from_A_to_B_t1}|B_t1(3)|{<from_B_t1_to_C_t0>from_B_t1_to_C_t0|<from_B_t1_to_C_t1>from_B_t1_to_C_t1}}"];
  "B_t2" [label="{{<from_A_to_B_t2>from_A_to_B_t2}|B_t2(3)|{<from_B_t2_to_C_t0>from_B_t2_to_C_t0|<from_B_t2_to_C_t1>from_B_t2_to_C_t1}}"];
  "C_t0" [label="{{<from_B_t0_to_C_t0>from_B_t0_to_C_t0|<from_B_t1_to_C_t0>from_B_t1_to_C_t0|<from_B_t2_to_C_t0>from_B_t2_to_C_t0}|C_t0(3)|{}}"];
  "C_t1" [label="{{<from_B_t0_to_C_t1>from_B_t0_to_C_t1|<from_B_t1_to_C_t1>from_B_t1_to_C_t1|<from_B_t2_to_C_t1>from_B_t2_to_C_t1}|C_t1(3)|{}}"];
  "A":"from_A_to_B_t0"-> "B_t0":"from_A_to_B_t0" [label="22000"]
  "A":"from_A_to_B_t1"-> "B_t1":"from_A_to_B_t1" [label="22001"]
  "A":"from_A_to_B_t2"-> "B_t2":"from_A_to_B_t2" [label="22002"]
  "B_t0":"from_B_t0_to_C_t0"-> "C_t0":"from_B_t0_to_C_t0" [label="22003"]
  "B_t1":"from_B_t1_to_C_t0"-> "C_t0":"from_B_t1_to_C_t0" [label="22005"]
  "B_t2":"from_B_t2_to_C_t0"-> "C_t0":"from_B_t2_to_C_t0" [label="22007"]
  "B_t0":"from_B_t0_to_C_t1"-> "C_t1":"from_B_t0_to_C_t1" [label="22004"]
  "B_t1":"from_B_t1_to_C_t1"-> "C_t1":"from_B_t1_to_C_t1" [label="22006"]
  "B_t2":"from_B_t2_to_C_t1"-> "C_t1":"from_B_t2_to_C_t1" [label="22008"]
}
)EXPECTED");
}
