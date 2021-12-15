// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "behavior/plugin/life_time.hpp"
#include "api_conformance_helpers.hpp"

using namespace BehaviorTestsDefinitions;
using namespace ov::test::conformance;
namespace {
    const std::vector<std::vector<int >> orders = {
            // 0 - plugin
            // 1 - executable_network
            // 2 - infer_request
            // 3 - variable state
            {3, 0, 1, 2},
            {3, 0, 2, 1},
            {3, 1, 0, 2},
            {3, 1, 2, 0},
            {3, 2, 0, 1},
            {3, 2, 1, 0},
            {0, 3, 1, 2},
            {0, 1, 3, 2}
    };

    INSTANTIATE_TEST_SUITE_P(smoke_BehaviorTests, HoldersTest,
            ::testing::Combine(
            ::testing::Values(ConformanceTests::targetDevice),
            ::testing::ValuesIn(orders)),
            HoldersTest::getTestCaseName);

}  // namespace