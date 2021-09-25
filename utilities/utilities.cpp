
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

	allstudentData.clear();
	//cout <<"**********************READFILE*******************" << endl;



	KP::studentData student;


		ifstream myfile;
		myfile.open(file.c_str(),ios::in);

		std::string line;
			while (!myfile.eof()) {				//exits when reach end of file
				getline(myfile, line);
				//cout <<"LINE: "<<line<< " ";
				int counter =0;
				string name= "";
				string midterm= "";
				string tmidterm= "";
				string gradefinal= "";
				for (int y=0;y< line.length();y++){
					if (line[y]==separator_char){
						counter ++;
					}
					else if (counter ==0){
						name+=line[y];

					}
					else if (counter ==1){
						midterm+=line[y];


					}
					else if (counter ==2){
						tmidterm+=line[y];

					}
					else if (counter ==3){
						gradefinal+=line[y];

					}


					student.name=name;
									student.midterm1=stringToDouble(midterm.c_str());
									student.midterm2 = stringToDouble(tmidterm.c_str());
									student.finalgrade = stringToDouble(gradefinal.c_str());
									allstudentData.push_back(student);



								//exits when reach end of file


				}

				//cout<< name <<" MIDTERM 1: "<< stringToDouble(midterm.c_str()) << " MIDTERM 2: "<<stringToDouble(tmidterm.c_str()) <<"FINAL: "<<stringToDouble(gradefinal.c_str()) << " END\n";
			}


			myfile.close();
			return 0;
}






int calculateFinalGrade(std::vector<KP::studentData> &allstudentData){
	//cout << "*************************CALCULATE FINAL GRADE*********************";
	int sum =0;
	int total =0;
	std:vector<KP::studentData>::iterator itr = allstudentData.begin();
	while (itr != allstudentData.end()){
		//cout<<"M1: "<<(*itr).midterm1 <<" M2: "<< (*itr).midterm2;
		sum = (*itr).midterm1 +(*itr).midterm2;
		total = sum/2;
		++itr;
	}
	return total;

}

int writeFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char){
	std:vector<KP::studentData>::iterator itr;

	ofstream myOutputfile;
	myOutputfile.open(file.c_str());//could open with  flags myfile.open(MYFILE, ios::out)
	for (itr =  allstudentData.begin(); itr!= allstudentData.end();++itr){
		myOutputfile << (*itr).name << separator_char<<(*itr).midterm1<< separator_char<<(*itr).midterm2<< separator_char<<(*itr).finalgrade<< separator_char;
	}



	myOutputfile.close();
}

/**bool compareName(const x,std::vector<KP::studentData> &y)
{
	KP:: studentData x
		return x.name < y.name;
}

bool compareFinal(std::vector<KP::studentData> &x, std::vector<KP::studentData> &y)
{
	return x.finalgrade > y.finalgrade;
}**/

int sortStudentData(std::vector<KP::studentData> &allstudentData,KP::SORT_TYPE st){
	KP:: studentData student;


	if (st == KP::NAME){
		return student.name < student.name;

	}
	if (st == KP::FINAL_GRADE){
		return student.name < student.name;
	}
	return 7;
}

