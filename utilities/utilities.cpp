
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
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


	//cout <<"**********************READFILE*******************" << endl;



		std:: string line;
		std:: string token;
		KP::studentData myStudentData;
		stringstream ss;
		int row=0;


		ifstream myfile;
		myfile.open(file.c_str(),ios::in);
		if (!myfile.is_open()){
				return KP::COULD_NOT_OPEN_FILE;
				}


			while (!myfile.eof()) {				//exits when reach end of file
				getline(myfile, line);

				myStudentData.clear();
				ss.str(line);


				cout <<"ROW: "<< row<<" LINE: "<<line<<"\n";

				getline(ss, myStudentData.name, separator_char);
				cout<<"BIG:   "<< myStudentData.name<<"\n";
				getline(ss, token,separator_char);
				myStudentData.midterm1 =stringToInt(token.c_str());
				getline(ss, token,separator_char);
				myStudentData.midterm2 = stringToInt(token.c_str());
				++row;

				//getline(ss, token,separator_char);
				//myStudentData.finalgrade= stringToInt(token.c_str());
				allstudentData.push_back(myStudentData);



				cout<< myStudentData.name <<" MIDTERM 1: "<< myStudentData.midterm1 << " MIDTERM 2: "<<  myStudentData.midterm2<<" FINAL: "<<myStudentData.finalgrade << " END\n";

			}
			myfile.close();



			return KP::SUCCESS;
}






int calculateFinalGrade(std::vector<KP::studentData> &allstudentData){
	//cout << "*************************CALCULATE FINAL GRADE*********************";
	int sum =0;
	int total =0;
	if (allstudentData.size()==0){
		return KP::VECTOR_CONTAINS_NO_STUDENTS;
	}

	std:vector<KP::studentData>::iterator itr = allstudentData.begin();
	for (itr =  allstudentData.begin(); itr!= allstudentData.end();++itr){
			sum = (*itr).midterm1 +(*itr).midterm2;
			total = sum/2;
			//cout <<"TOTAL: "<<total<<"\n";
	}
	//return 1;
	return KP::SUCCESS;

}

int writeFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char){
	if (allstudentData.size()==0){
			return KP::VECTOR_CONTAINS_NO_STUDENTS;
		}

	std:vector<KP::studentData>::iterator itr;

	ofstream myOutputfile;
	myOutputfile.open(file.c_str());//could open with  flags myfile.open(MYFILE, ios::out)
	if (!myOutputfile.is_open()){
					return KP::COULD_NOT_OPEN_FILE;
					}

	for (itr =  allstudentData.begin(); itr!= allstudentData.end();++itr){
		cout<< "CHECKING: "<<(*itr).name<<"\n";
		myOutputfile<< (*itr).name << separator_char<<(*itr).midterm1<< separator_char<<(*itr).midterm2<< separator_char<<(*itr).finalgrade<< separator_char;
	}



	myOutputfile.close();
	return KP::SUCCESS;
}


int sortStudentData(std::vector<KP::studentData> &allstudentData,KP::SORT_TYPE st){
	if (allstudentData.size()==0){
			return KP::VECTOR_CONTAINS_NO_STUDENTS;
		}

	KP:: studentData student;


	if (st == KP::NAME){
		return student.name < student.name;

	}
	if (st == KP::FINAL_GRADE){
		return student.name < student.name;
	}
	return KP::SUCCESS;
}

