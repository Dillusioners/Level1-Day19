// for input and output
# include <iostream>

/*
	Author: LeeTuah
	Program: Factorial of a given number 
	Date: 07/05/23
	For SuperB League event
*/

// returns the factorial of a number through the process of recursion
// int n -> the number whose factorial is to be found
unsigned long long factorial(int n){
	// base case for the recursive approach
	// if number is 1 or below, return 1
	if(n < 2) return 1;
	
	// returns the number multiplied by the factorial of the number
	// one smaller than it
	return n * factorial(n - 1);	
}

// execution starts from here
// int argc -> total argument count from run
// char** argv -> all the provided arguments in a string array
int main(int argc, char** argv){
	// variable declaration
	int num;
	
	// asking user for the number
	std::cout << "Enter your number: ";
	std::cin >> num;
	
	// printing the factorial
	std::cout << "The factorial of number is " << factorial(num);	
	return 0;
}
