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
