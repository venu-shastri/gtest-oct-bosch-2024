# Vehicle Speed Monitor Features

- Instatiate SpeedMonitor with thresholdspeed
- Validates SpeedThrehold Value is in Range (1-100)
	- Log message 
- Instatiate Dependencies 
	- BNFSpeedSensor 
	- IOTCloudCommunicator 
- Communicate / interact with BNFSpeedSensor and expecting currentSpeed in kmph from speedsensor
  - Log currentSpeed
- Validate Currentspeed 
     - Not Valid
	     - Convert Speed from KMPH  to MPH
		   - Format message
		   - interact/communicate with IOTCloudCommunicator to push the message and expecting statusCode from communicator
		   - Verify Status  Code 
		      -if value exceeds (>) 400
			      -log statusCode


	
