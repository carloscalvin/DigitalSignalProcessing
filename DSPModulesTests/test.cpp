// SignalReaderTests.cpp

#include <gtest/gtest.h>
#include "../DSPModules/SignalReader.h"

TEST(SignalReaderTests, HelloWorldTest) {
    ASSERT_TRUE(true);  
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
