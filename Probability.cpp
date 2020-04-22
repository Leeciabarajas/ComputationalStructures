//     Leecia Barajas
//     CS 2130 – 11:20am
//     Assignment #4
//     Dr. Huson
//     Due:3/21/2019
//     Filename: probability 
//     Version: 1.0
// ---------------------------------------------------------------
// This program calculates permutations, combiniations and binomials 
// ---------------------------------------------------------------

#include <iostream>
#include <math.h>   
using namespace std; 

double factorial(double number)
{
	//start loop one less than number ex 5
	//loop through untill we reach 1  
	int uno = 1; 
	if (number == 1 || number==0) {
		return uno; 
	}
	else {
		for (int i = number - 1; i > 1; i--)
			number = number * i; //number is now itself * one less 
			//ex number= 5*4 
		return number;
	}
}

//Permutation function 
double Permutation(double a, double b) {
	return factorial(a) / (factorial(a - b));
}

//combination function 
 double Combination( double a, double b) {
	int uno = 1; 
	if (b == 0) { //this way we dont divide by zero
		return uno; //return value of 1
	}
	else {
		//return factorial(a) / (factorial(b)*factorial(a - b));

		double answer = 0;
		answer = (factorial(a)) / (factorial(b)*(factorial(a - b)));
		return answer;
	}

}

//binomial fucntion 
double Binomial(double k, double n, double p) {
	double answer = 0;
	int loop = k;
	//loop through k amount of times+1
	for (int i = 0; i < loop + 1; i++) { 
		//add together each result of the loop
		answer = answer + (Combination(n, k) * pow(p, k) *pow((1 - p), (n - k)));
		//decrement K
		k = k - 1; 
	}
	return answer;
}


int main() {

	//print out answer to #1
	cout << "1." << endl; 
	cout << "a.) Ways of presenting different prizes to 4 of 20 employees: " <<Permutation(20,4)<< endl; 
	cout << "b.) Ways of presenting same prizes to 4 of 20 employees: " <<Combination(20,4)<< endl; 
	cout << endl; 


	//print out answer #2
	cout << "2." << endl;
	cout << "The probability that the sample will contain at most 1 defective bomb is: " <<
		(Combination(47, 10) + (Combination(47, 9)*Combination(3, 1))) / (Combination(50, 10)) << endl;
	cout<< endl; 

	//print out answer #3
	cout << "3." << endl; 
	cout << "The probability that there will be at most 2 defective grenades is: " << Binomial(2,15,.075) << endl; 
	cout << endl;

	system("pause"); 
	return 0; 
}