//     Leecia Barajas
//     CS 2130 – 11:30 am
//     Assignment #1
//     Dr. Huson
//     Due: 1/24/19
//     Filename: assignment1.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program works with bitstrings to help you find a Complement
//,union,intersection, difference and symetric difference with two 
//sets of data 
// ---------------------------------------------------------------

// Compiler directives
#include<iostream>
using namespace std;


//function to print sets entered 
void print_set(int setX) {

	int uhPrinted = 0; 

	cout << "{"; 

	for (int i = 0; i <= 9; i++) {

		if ((1 << i)& setX) {
			if (uhPrinted) {
				cout << ", ";
			}//if2

			cout << i;
			uhPrinted = 1;
		}//if1
	}//for

	cout << "}"<<endl; 
 
}//print set


//function to read in numbers within set 
int afun(int countA) {
	int SetA = 0; 
	int valueA = 0; 
	
	while (countA > 0) {
		cout << "Enter a number within this set: ";
		cin >> valueA;

		//check to see if number is out of bounds
		if (valueA > 9 || valueA < 0) {
			cout << "Please enter a number between 0 and 9" << endl;
			continue;
		}

		SetA = SetA | (1 << valueA);

		countA--;

	}

	return SetA; 
}


int main()

{
	//Variables 
	int countA = 0; 
	int countB = 0;
	int SetA=0;
	int SetB=0;
	//int valueA = 0; 
	//int valueB = 0; 

	//get length of set
	cout << "please enter length of set A" << endl; 
	cin >> countA; 

	//read in numbers for setA
	SetA = afun(countA);

	//get length of set B
	cout << "please enter length of set B" << endl; 
	cin >> countB; 

	//read in numbers for SetB
	SetB = afun(countB); 



	//call functions for sets to print
	cout << "Set A = "; 
	print_set(SetA);

	cout << "Set B = "; 
	print_set(SetB); 

	cout << "Complement of A: ";
	print_set(~SetA);

	cout << "Union of A and B ";
	print_set(SetA | SetB);

	cout << "Intersection of A and B "; 
	print_set(SetA&SetB);

	cout << "Difference of A and B: "; 
	print_set(SetA & (SetA ^SetB)); 

	cout << "Symmetric Difference of A and B"; 
	print_set ( ((SetA & (SetA ^SetB))) | ((SetB & (SetB ^SetA))) ) ;

	system("pause"); 
}//main 

