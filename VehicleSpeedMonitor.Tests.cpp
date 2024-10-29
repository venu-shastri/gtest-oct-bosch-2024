#include "VehicleSpeedMonitor.h"
#include <gtest/gtest.h>

TEST(VehicleSpeedMonitorTestSuite,AssertValidInstanceWithSpeedThreshold){

    int speedThreshold = 70;  // Sample threshold
    SpeedMonitor monitor{speedThreshold};
     EXPECT_EQ(monitor.getSpeedThreshold(), speedThreshold);
}
