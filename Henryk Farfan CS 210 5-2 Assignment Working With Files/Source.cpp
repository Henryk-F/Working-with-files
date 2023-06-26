/*
[Author]: Henryk Farfan
[Date]: 6/11/2023
[Purpose]: To convert the .txt file Fahrenheit temperatures into Celsius temperatures and 
           maintain the names of the cities.

*/

#include <iostream>
#include <fstream> //To allow the program to read files.
#include <string>
using namespace std;


double fahrenheitToCelsius(double fahrenheit) { 
	return (fahrenheit - 32) * 5 / 9;
}
//Creating a user-defined funciton so I may call it to easily calculate Fahrenheit to Celsius.

int main() {
	ifstream inFS;	//Input file to read.
	ofstream outFS; //Output new file.
	string cityName;
	double fahrenheitTemp = 0.0;
	double celsiusTemp = 0.0;
	
	inFS.open("FahrenheitTemperature.txt"); //Opens the FahrenheitTemperature.txt file.

	if (!inFS.is_open()) { //To check if the file fails to open and terminate the program if it fails to open.
		cout << "Could not open file: FahrenheitTemperature.txt." << endl;
		return 1;
	}

		outFS.open("CelsiusTemperature.txt"); //To create the output file.
		if (!outFS.is_open()) {
			cout << "Could not create CelsiusTemperature.txt." << endl; //In the event that the file cannot be created and terminate early.
			return 1;
		}

		while (inFS >> cityName >> fahrenheitTemp) { //Loops to read the FahrenheitTemperature.txt's city name and temp number.
			celsiusTemp = fahrenheitToCelsius(fahrenheitTemp); //Applies the fahrenheit function to each number value.
			outFS << cityName << " " << celsiusTemp << endl; //Outputs the city name, a space, and the newly calcualted temperature.
		}

	inFS.close(); //Securely closes the FahrenheitTemperature file.
	outFS.close(); //Securely closes the newly created CelsiusTemperature file.

	cout << "File calculations conversion was a success. CelsiusTemperature.txt created." << endl; //Confirmation in the debugging window.

	return 0; //Close program.
}