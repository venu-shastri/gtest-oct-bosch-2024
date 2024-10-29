#include "VehicleSpeedMonitor.h"
#include <gmock/gmock.h>
using testing::StrEq;

class MockLogger:public ILogger{
public:
 MOCK_METHOD(void, write,(const string& message));
    
};

class MockCommunicator:public IMessageCommunicator{
public:
    MOCK_METHOD(int, pushMessage,(const string& message));
};

class MockSpeedSensor:public ISpeedSensor{
public:
MOCK_METHOD( int ,getCurrentSpeed,())
};

TEST(VehicleSpeedMonitorTestSuite,LoggerInteractionTesting){
SpeedMonitor objUnderTest{150};
MockCommunicator communicator;
MockSpeedSensor speedSensor;
MockLogger logger;
EXPECT_CALL(logger,write(StrEq("_speedThreshold value must be in the ramge {1-100} 150")));
objUnderTest.monitor(&communicator,&speedSensor,&logger);
}
TEST(VehicleSpeedMonitorTestSuite,LoggerInteractionTesting){
SpeedMonitor objUnderTest{40};
MockCommunicator communicator;
MockSpeedSensor speedSensor;
MockLogger logger;
EXPECT_CALL(speedSensor,getCurrentSpeed()).WillOnce(Return(50));
EXPECT_CALL(communicator,pushMessage(StrEq(Current Speed in Miles 31.0686"))).WillOnce(Return(300));
objUnderTest.monitor(&communicator,&speedSensor,&logger);
}
