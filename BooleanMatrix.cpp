//     Leecia Barajas
//     CS 2130 – 11:30 am
//     Assignment #5
//     Dr. Huson
//     Due: 04/4/19
//     Filename: BooleanMatrix.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// C++ code to implement unary and binary operations on square Boolean
//matrices of order 3.  These Boolean matrix library functions include : 
//Meet , join, compliment, boolean prodcuct, transpose 
// ---------------------------------------------------------------

// Compiler directives
#include <iostream>
using namespace std;

//Function that allows us to read in values
void readvalues(bool matrix[3][3]) {
	int  x = 100; 
	int y = 100; 
	//bail if enter 0 0
	while ((x != 0) && (y != 0)) {
		//read in 
		cout << "Please enter the ordered pair ";
		cin >> x >> y; 
		//add a 1 to proper coordinate if it is range 
		if ((x <=3 && x >=1) && (y <= 3 && y >=1 )) {
			matrix[x - 1][y - 1] = 1; 
		}
	}
}
//loop throug each row and print out  
void printout(bool matrix[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl; 
	}
}

void meet(bool aMatrix[3][3], bool bMatrix[3][3]) {
	bool temp[3][3] = { 0 }; //temp filled with zeros
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//add to temp matrix when matrix A & B==1 
			if (aMatrix[i][j] ==true && bMatrix[i][j] ==true) {
				temp[i][j] = true; 
			}
		}
	}
	printout(temp); 
}

//
void join(bool aMatrix[3][3], bool bMatrix[3][3]) {
	bool temp[3][3] = { 0 };//temp filled with zeros
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{//if A or B have a 1 then so will temp
			if (aMatrix[i][j] == true || bMatrix[i][j] == true) {
				temp[i][j] = true;
			}
		}
	}
	printout(temp);
}

void product(bool aMatrix[3][3], bool bMatrix[3][3]) {
	bool temp[3][3] = { 0 }; //temp filled with zeros
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for(int k=0; k<3; k++){
				//If A and B have a 1 at [][] then temp will as well
				temp[i][j] = temp[i][j] || (aMatrix[i][k] && bMatrix[k][j]); 
			}
		}
	}
	printout(temp);
}

//compliment: "opposite matrix" 
//all 0's = 1
//all 1's equal 0's 
void compliment(bool aMatrix[3][3]) {
	bool temp[3][3] = { 0 }; //temp filled with zeros
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//temp coordinate= opposite of what matrix ='s 
			temp[i][j] = !aMatrix[i][j]; 
		}
	}
	printout(temp); 
}

//transpose 
void transpose(bool matrix[3][3]) {
	bool temp[3][3] = { 0 }; //temp filled with zeros
//loop to get to each row/column 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//temp (x,y) = (y,x) switch x y 
			temp[i][j]= matrix[j][i];
		}
	}
	printout(temp); 
}

void reflexive(bool matrix[3][3]) {

	//load in data and make temp=matrix
	bool temp[3][3] = { matrix[3][3] };//create temp
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = matrix[i][j];
		}
	}

	//loop through and everytime diagonal coordinate=0
	//turn it into a 1 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (temp[i][i] == false)
				temp[i][i] = true;
		}
		
	}
	printout(temp); 
}

void symmetric(bool matrix[3][3]) {
	//load in data and make temp=matrix
	bool temp[3][3] = { matrix[3][3] };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = matrix[i][j];
		}
	}

	//go through each coordinate 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//reflect based off of coordinates
			if (temp[i][j] == true) {
				temp[j][i] = true;
			}

		}
	}
	printout(temp);
}

void transitive(bool matrix[3][3]) {
	//load in data and make temp=matrix
	bool temp[3][3] = { matrix[3][3] };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = matrix[i][j];
		}
	}

	//go through each coordinate 
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//Warshall's algorithm 
				temp[i][j] = temp[i][j] || temp[i][k] && temp[k][j]; 
			}
		}
	}
	printout(temp); 
}






int main() {
	//I messed up on submitting
	cout << "I had this done on time and even submitted early" << endl; 
	cout << "(I showed you in class, if you remember). I just now" << endl; 
	cout<<"realized I uploaded the wrong file. Please don't dock" <<endl; 
	cout<< "too many points..." << endl; 
	cout << endl; 


	//our variables
	bool aMatrix[3][3] = { 0 }; 
	bool bMatrix[3][3] = { 0 }; 

	//read in/print A
	cout << "Enter Matrix A: " << endl; 
	readvalues(aMatrix); 
	cout << "A= " << endl;
	printout(aMatrix); 
	cout << endl; 

	//read in/print B
	cout << "Enter Matrix B: " << endl;
	readvalues(bMatrix);
	cout << "B=" << endl;
	printout(bMatrix); 
	cout << endl;

	cout << "A meet B = " << endl; 
	meet(aMatrix, bMatrix); 
	cout << endl;

	cout << "A join B =" << endl; 
	join(aMatrix, bMatrix);
	cout << endl;	

	cout << "A product B = " << endl; 
	product(aMatrix, bMatrix); 
	cout << endl;

	cout << "Complement of A =" << endl; 
	compliment(aMatrix); 
	cout << endl; 

	cout << "Transpose of A= " << endl; 
	transpose(aMatrix); 
	cout << endl;
	
	cout << "Smallest Reflexive of A=  " << endl; 
	reflexive(aMatrix); 
	cout << endl;

	cout << "smallest symmetric of A=  " << endl; 
	symmetric(bMatrix); 
	cout << endl;

	cout << "Transitive of A= " << endl; 
	transitive(aMatrix); 
	cout << endl; 

	cout << "Transitive of B=  " << endl;
	transitive(bMatrix);
	cout << endl;

	system("pause"); 
	return 1; 
}