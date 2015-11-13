# CardboardProfileDumper
Simple toString dumper for cardboard's profiles. 
Loads the current_device_params file stored on android devices after scanning/configuring a cardboard device.

## Building ##

The only dependencies are std and protobuf.
Google utilizes protobuf to save and load the profiles of Cardboard based devices.

I added a compile.sh file which is basically:

    g++ CardboardProfileDumper.cpp CardboardDevice.pb.cc -o CardboardProfileDumper -lprotobuf
  
## Using ##

After compiling, put your cardboard profile in the folder of the executable and run.
It should show all known variables of the config.

Test result with a Cardboard 2.0 file:

    Google Cardboard settings dumping tool 1.0
    Opening file: current_device_params-Cardboardv2
    --- Begin of dump ---
    
    Vendor: 			Unofficial Cardboard
    Model: 				v2.0
    Screen to lens distance: 	0.045
    Inter lens distance: 		0.062
    Left eye field of view angles: 	50, 50, 50, 50, 
    Vertical alignment: 		0
    Tray to lens distance: 		0.04
    Distortion coefficients: 	0, 0, 
    
    --- dump complete ---
