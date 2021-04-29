/* Included Libraries */ 
#include <stdio.h>
#include <math.h>

/*-------------------------------------------------------------
 * Connor Lowe
 * CSCI 112, Lab5a
 *
 * A program that calculates the physics motion equations by 
 * first waiting for a user select the desired equation 
 * and then waits for the user to input the required
 * values to calculate the choosen equation. 
 *
 * 31 May 2018
 *-----------------------------------------------------------*/ 

/* List of all function declarations (prototypes) */
//Displays user menu, reads input, and validates the input 
int user_menu(); 

//Equation functions are passed by reference 
void equation1(float *);	//Calculate motion equation 1
void equation2(float *);	//Calculate motion equation 2
void equation3(float *);	//Calculate motion equation 3
void equation4(float *);	//Calculate motion equation 4 

//User input functions return a value from the user 
float get_position_initial(void);	//Prompts user for x0 
float get_position_final(void);		//Prompts user for xf
float get_velocity_initial(void);	//Prompts user for v0 
float get_velocity_final(void);		//Prompts user for vf 
float get_acceleration(void);		//Prompts user for a
float get_time(void);			//Prompts user for t
/* End function delcations (prototypes) */ 

/*-------------------------------------------------------------*/ 

/* Main Function and Menu */ 
int main(void) { 
	//Print welcome message 
	printf("Welcome to the MOTION EQUATION CALCULATOR\n\n"); 
	//Variable for the user choice from menu
	int user_choice; 
	do { 
		user_choice = user_menu(); //Print menu, validate choice is between 1 and 5 
		//You will pass the address of this variable to your equation functions
		float result; //Variable to hold calculated result 
		float *result_ptr = &result; 
		//Handle menu choice selected by user 
		switch (user_choice) { 
			case 1 : 
				equation1(result_ptr); 
				break; 
			case 2 : 
				equation2(result_ptr); 
				break; 
			case 3 : 
				equation3(result_ptr); 
				break; 
			case 4 : 
				equation4(result_ptr); 
				break; 
			case 5 : 
				//Exit program if user selects quit 
				printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n"); 
				return 0; 
				break; 
		}
		//Print out the calculated result within four digits after the decimal point 
		printf("\nYour result is %.4f.\n\n", result); 
	} while (user_choice != 5); //Repeat until user chooses QUIT 
	return 0; //Return without error
}
/* End Main Function and Menu */ 

/*-------------------------------------------------------------*/ 

/* Input grabber and valid input checker */ 
int is_valid(int input) { 
	if (input > 5) { 
		printf("%d is an invalid option. Please try again.\n\n", input); 
		return 0; 
	}
	else if (input < 1) { 
		printf("%d is an invalid option. Please try again.\n\n", input); 
		return 0; 
	} 
	return 1; 
}
int user_menu(void) { 
	int input; 
	do { //menu input 
		printf("Choose a motion equation 1-4 or choose 5 to QUIT >> "); 
		scanf("%d", &input); 
	} while (is_valid(input) != 1); //checks to see if user input is valid
	return input; 
}
/* End grabber and checker */ 

/*-------------------------------------------------------------*/ 

/* Motions Equations */ 
void equation1(float *result) { //vf = v0 + at
	float v0 = get_velocity_initial(); 
	float a = get_acceleration(); 
	float t = get_time(); 
	float x = (v0 + a*t); 
	*result = (v0 + a*t); 
}
void equation2(float *result) { //xf = x0 + v0t + 1/2at^2
	float x0 = get_position_initial(); 
	float v0 = get_velocity_initial(); 
	float t = get_time(); 
	float a = get_acceleration(); 
	*result = (x0 + v0*t + .5*a*pow(t, 2)); 
}
void equation3(float *result) { //vf = sqrt(v0^2 + 2a(xf-x0)) 
	float v0 = get_velocity_initial(); 
	float a = get_acceleration(); 
	float xf = get_position_final(); 
	float x0 = get_position_initial(); 
	*result = sqrt(pow(v0, 2) + 2*a*(xf-x0)); 
}
void equation4(float *result) { //xf = x0 + 1/2(vf + v0)t 
	float x0 = get_position_initial(); 
	float vf = get_velocity_final(); 
	float v0 = get_velocity_initial(); 
	float t = get_time(); 
	*result = (x0 + .5*(vf + v0)*t); 
}
/* End Motion Equations */ 

/*-------------------------------------------------------------*/ 

/* Get functions for variables in motion equations */ 
float get_position_initial(void) { 
	float x0; 
	printf("\tEnter initial position >> "); 
	scanf("%f", &x0); 
	return x0; 
}
float get_position_final(void) { 
	float xf; 
	printf("\tEnter final position >> "); 
	scanf("%f", &xf); 
	return xf; 
}
float get_velocity_initial(void) { 
	float v0; 
	printf("\tEnter initial velocity >> "); 
	scanf("%f", &v0); 
	return v0; 
}
float get_velocity_final(void) { 
	float vf; 
	printf("\tEnter final velocity >> "); 
	scanf("%f", &vf); 
	return vf; 
}
float get_acceleration(void) {
	float a; 
	printf("\tEnter acceleration >> "); 
	scanf("%f", &a); 
	return a; 
}
float get_time(void) { 
	float t; 
	printf("\tEnter time >> "); 
	scanf("%f", &t); 
	return t; 
}
/* End get functions */ 
