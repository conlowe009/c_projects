/* Preprocessor Directives */ 
#include <stdio.h>
#define A 2
#define B 3

/*
 * Connor Lowe
 * CSCI112, Lab2
 *
 * Sequences the Function: 
 * Xn = (Xn-2)/2 + 3*(Xn-1) 
 * for 5 iterations. 
 * 
 * 17 May, 2018 
 */

//gets the input from the user
double get_input(void) {
	double input; 

	printf("Please enter your numberical input> "); 
	scanf("%lf", &input);

	return input; 
}

//gets the next sequence from the function 
double get_next(double x1, double x2) {
	/* Xn = (Xn-2)/2 + 3*(Xn-1) */ 
	double xn; 

	//x1 represents Xn-2, x2 represent Xn-1,
	xn = (x1/A) + (B*x2); 

	return xn; 
}

//prints the result of the sequence based on the input
void print_result(double input) { 
	printf("The result is %.2lf\n", input); 

	return;
}

//main
int main(void) { 
	//gets user input and assigns it to variables
	double x1 = get_input(); 
	double x2 = get_input(); 

	//evaluates the sequence up to x5
	double x3 = get_next(x1, x2); 
	double x4 = get_next(x2, x3); 
	double x5 = get_next(x3, x4); 

	//prints the end of the resulting sequence
	print_result(x5); 

	return 0; 
}


