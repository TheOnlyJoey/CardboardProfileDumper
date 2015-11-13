#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "CardboardDevice.pb.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Google Cardboard settings dumping tool 1.0\n";
	
	char* fileName;
	if ( argc > 1 ) // There are Command line parameters
	{
		fileName = argv[1];
		cout << "Opening file: " << fileName << endl;
	}
	else
	{
		fileName = "current_device_params";
		cout << "No input file defined, try to open: current_device_params" << endl;
	}
	fstream file(fileName, ios::in | ios::binary);
	file.seekg(8, ios_base::beg);
	
	DeviceParams devParams;
	
	if (!devParams.ParseFromIstream(&file))
	{
		cerr << "Failed to parse file" << endl;
		return -1;
	}
	
	cout << "--- Begin of dump ---" << endl << endl;

	if (devParams.has_vendor())
		cout << "Vendor: \t\t\t" << devParams.vendor() << endl;
	if (devParams.has_model())
		cout << "Model: \t\t\t\t" << devParams.model() << endl;
	if (devParams.has_screen_to_lens_distance())
		cout << "Screen to lens distance: \t" << devParams.screen_to_lens_distance() << endl;
	if (devParams.has_inter_lens_distance())
		cout << "Inter lens distance: \t\t" << devParams.inter_lens_distance() << endl;
	if (devParams.left_eye_field_of_view_angles().size() != 0) //repeated float
	{
		cout << "Left eye field of view angles: \t";
		for (size_t i = 0; i < devParams.left_eye_field_of_view_angles().size(); i++)
			cout << devParams.left_eye_field_of_view_angles(i) << ", ";

		cout << endl;
	}
	if (devParams.has_vertical_alignment())//enum
		cout << "Vertical alignment: \t\t" << devParams.vertical_alignment() << endl;
	if (devParams.has_tray_to_lens_distance())
		cout << "Tray to lens distance: \t\t" << devParams.tray_to_lens_distance() << endl;
	if (devParams.distortion_coefficients().size() != 0) //repeated float
	{
		cout << "Distortion coefficients: \t";
		for (size_t i = 0; i < devParams.distortion_coefficients().size(); i++)
			cout <<  devParams.distortion_coefficients(i) << ", ";
			
		cout << endl;
	}
	if (devParams.has_has_magnet())
		cout << "Magnet: \t\t" << devParams.has_magnet() << endl;
	if (devParams.has_primary_button())//enum
		cout << "Primary button: \t\t" << devParams.primary_button() << endl;
	
	cout << endl << "--- dump complete ---" << endl;

	google::protobuf::ShutdownProtobufLibrary();
	file.close();

	return 0;
}
