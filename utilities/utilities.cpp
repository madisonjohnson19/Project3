#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>


#include "../includes/constants.h"
#include "../includes/utilities.h"
using namespace std;

//if you are debugging the file must be in the project parent directory
std::string DoubleToString(double Number) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

//if myString does not contain a string rep of number returns 0
//if int not large enough has undefined behaviour, 
//this is a very fragile function
//ex. string a="3";
//    int i = stringToInt(a.c_str()); //i contains 3
//    a="s";
//    i = stringToInt(a.c_str()); //i receives 0
int stringToInt(const char *myString) {
	return atoi(myString);
}

//if myString does not contain a string rep of number returns 0
//this is a very fragile function
//ex. string b="4.5";
//    double d = stringToDouble(b.c_str()); //d receives 4.5
double stringToDouble(const char *myString) {
	return atof(myString);
}

int readFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char ){



	allstudentData.clear();

		ifstream myfile;
		myfile.open(file.c_str(),ios::in);

		std::string line;
			while (!myfile.eof()) {				//exits when reach end of file
				getline(myfile, line);				//gets a line up to '/n' char allstudentData += line;
				cout << line;
				//
			}
			myfile.close();
}




int calculateFinalGrade(std::vector<KP::studentData> &allstudentData){
	return 7;

}

int writeFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char){


	ofstream myOutputfile;
	myOutputfile.open(file.c_str());//could open with  flags myfile.open(MYFILE, ios::out)
										  //note the .c_str() call on MYFILE  allstudentData << file;
		if (!myOutputfile.is_open())
				return false;


		myOutputfile.close();
		return true;
}

int sortStudentData(std::vector<KP::studentData> &allstudentData,KP::SORT_TYPE st){
	return 7;
}

