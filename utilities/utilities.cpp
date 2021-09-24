
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

//int readFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char ){
int readFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char){

	allstudentData.clear();
	cout <<"**********************READFILE*******************" << endl;

		std::stringstream   lineStream;
		std::string         cell;






	KP::studentData student;


		ifstream myfile;
		myfile.open(file.c_str(),ios::in);

		std::string line;
			while (!myfile.eof()) {				//exits when reach end of file
				getline(myfile, line);

				for (int y=0;y< line.length();y++){
					cout << "LINE: "<<line[3]<< line[4]<<line[5]<<"$";
					if (line[y]==separator_char){
						cout << "HERE: " <<separator_char << " = "<<line[y];
					}
					student.name=line[2];
					student.midterm1 = line[y+1];
					student.midterm2 = line[y+2];
					student.finalgrade =line[y+3];
					allstudentData.push_back(student);			//exits when reach end of file
					cout << "NAME; "<<student.name;
					return 0;
				}
			}
			myfile.close();
			return 0;
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

