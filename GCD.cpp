//     Leecia Barajas
//     CS 2130 – 11:20am
//     Assignment #4 part 1
//     Dr. Huson
//     Due:3/21/2019
//     Filename: probability 
//     Version: 1.0
// ---------------------------------------------------------------
// This program calculates if a number is prime and GCD
// ---------------------------------------------------------------

#include <iostream> 
using namespace std; 

//function if prime number
void prime(int number) {
	bool check{true};
	//loop through
	for (int i = 2; i <= number/2; i++) {
		if (number % i == 0) { //if remainder 
			check = false;
			break;
		}
	}
	//print out results 
	if (check) {
		cout << number << " is a prime number." << endl;
	}
	else {
		cout << number << " is not a prime number."<<endl;
	}
}

//function for GCD using Euclidean 
int getGCD(int fint, int sint)
{
	if (sint == 0)
		return fint;
	return getGCD(sint, fint % sint);

}

int main() {
	//variables
	int fint{ 0 };
	int sint{ 0 }; 
	//get numbers
	cout << "Enter first integer: " << endl; 
	cin >> fint; 
	cout << "Enter second integer: " << endl; 
	cin >> sint; 

	//see if numbers are prime
	prime(fint); 
	prime(sint); 

	//print out GCD of numbers
	cout << "The GCD(" << fint << ", " << sint << ") is " << getGCD(fint, sint) << endl;

	system("pause"); 
	return 0;
}