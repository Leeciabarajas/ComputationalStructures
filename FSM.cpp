//     Leecia barajas 
//     CS 2130 – 11:30 am
//     Assignment #6
//     Dr. Huson
//     Due: 04/18/2019
//     Filename: FSM.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program checks if a string is valid using a FSM
// ---------------------------------------------------------------

// Compiler directives
#include<string>
#include <iostream>
using namespace std;


//
int nextState(int state, char symbol) {
	//"hard codded" state table that tells what the next state will be 
	int stateTable[4][3] = { {0,0,1}, {0,0,2}, {2,3,2},{2,3,2} };
	//check valid input is a,b, or c
	if (symbol == 'a' || symbol == 'b' || symbol == 'c') {
		//if so, call our stateTable and calcuatle nextstate 
		return stateTable[state][symbol - 'a'];
	}
	//invalid input do this 
	else return -1; 
}

bool accept(int state) {
	//our only acceptable final state is the last 
	bool acceptt[4] = { 0,0,0,1 };
	//return false(0) or true(1) for state 
	return acceptt[state];
}


//this function checks if we have a valid string 
//but uses the function accept & nextstate 
bool validString(string word) {

	int state = 0; 
	bool uh; //a temp to hold results 
	//loop through each char in our string 
	for (int i = 0; i < word.length(); i++) {
		//our current state is updated based off of 
		//previous state and what char is sent in
		state = nextState(state, word.at(i));
		//now check if we are in our final "acceptable" state 
		uh = accept(state);

		//when our nextState tells us that we have invalid input
		if (state == -1) {
			return false;
		}
	}
	//return if valid or not 
	return uh; 
}

//this prints out the string entered and if it valid 
void printresults(string string) {
	//call validstring and pass in a string 

	if (validString(string) == true) {//if valid tell us 
		cout << string << " is valid" << endl;
	}
	else {//otherwise it is invalid 
		cout << string <<" is invalid" << endl;
	}

}



int main() {
	//declare our strings 
	string test1 = "aaccbbabc";
	string test2 = "cacbcabbc";
	string test3 = "bcbcccbbb"; 

	//send each string to be printed if it is valid or invalid 
	printresults(test1); 
	printresults(test2); 
	printresults(test3); 

	system("pause"); 
	return 0;
}