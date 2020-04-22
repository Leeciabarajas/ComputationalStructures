

//     Leecia
//     CS 2130 – 11:30
//     Assignment #3
//     Dr. Huson
//     Due: feb 282019
//     Filename: SumOfProducts
//     Version: 1.0
// ---------------------------------------------------------------
// This program read in a file and then outputs what was read in 
//followed by it's sum of products
// --------------------------------------------------------------//    


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream in;

	string file;
	//enter file name 
	cout << "Enter Name of File" << endl;
	getline(cin, file);
	in.open(file.c_str());


	//check file read in was good
	if (!in.good())
	{
		cerr << "Can't open file" << endl;
		exit(1);
	}

	//create array of bool to hold our table
	bool fileData[8][4];

	//print out formated stuff
	cout << "Truth Table :" << endl; 

	cout << "X" << " ";
	cout << "Y" << " ";
	cout << "Z" << "   ";
	cout << "F(X,Y,Z)";
	cout << endl; 

	//row so we keep track of row#
	int row = 0;
	//read in eveything in our file 
	while (row < 8) {
		//this is our array at x, y , z, f 
		in >> fileData[row][0] >> fileData[row][1] >> fileData[row][2] >> fileData[row][3];
		//print out our data 
		cout << fileData[row][0]<<" "; 
		cout << fileData[row][1] << " ";
		cout << fileData[row][2] << "    ";
		cout << fileData[row][3] << endl; 

		row++;//incrament row to get to next row 
	}

	row = 0; //reset row 

	cout << "Sum of Products Expansion :" << endl;

	bool firstOutput = true;//so we can add our + later
	while (row < 8) {//go through this process 8 times 
		

		if (fileData[row][3]) {//if f = 1 

			if (firstOutput) { 
				firstOutput = false;
			}
			else {
				cout << " + ";
			}
			//begin outputing "xyz" as needed 
			if (fileData[row][0]) {//if x is a 1 then print out x 
				cout << "(x";
			}
			else {//if x is a o then print out x'
				cout << "(x'";
			}
			if (fileData[row][1]) {
				//write out y
				cout << "y";
			}
			else {
				//write out y'
				cout << "y'";
			}
			if (fileData[row][2]) {
				//write out z
				cout << "z)";
			}
			else {
				//write out z'
				cout << "z')";
			}
			
		}
		row++;
	}


	system("pause");
	return 0;
}
