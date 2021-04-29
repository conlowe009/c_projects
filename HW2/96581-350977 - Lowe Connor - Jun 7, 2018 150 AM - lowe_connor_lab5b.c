/* Included Libraries */ 
#include <stdio.h>
#include <math.h> 

/*------------------------------------------------------ 
 * Connor Lowe
 * CSCI 112, Lab5b 
 * 
 * A program that peforms a basic matrix multiplcation 
 * calculation by first checking the size of the 
 * matrices provided by the user and then reading in 
 * the actual matrices by the user provided input file. 
 *
 * 6 June, 2018
 *-----------------------------------------------------*/

/* Function Prototypes */ 
//User Input Menu
int user_prompt(); 

//Matrix Storing Function 
void store_matrix(int*, int, FILE*); 

//Matrix Multiplying Function 
void matrix_multiply(int*, int*, int*, int , int, int); 

//Function to print the two inputted matrices
void show(int*, int*, int, int, int, int); 

//Printing Function for Result Matrix 
void print(int*, int, int); 

//Functions for User Input 
int get_rows_matrixa(void); 
int get_columns_matrixa(void); 
int get_rows_matrixb(void); 
int get_columns_matrixb(void); 
/* End Function Prototypes */ 

/*---------------------------------------------------------------------------*/ 

/* Main Function */ 
int main(void) { 
	//Print Welcome Message 
	printf("Welcome to the MATRIX MULTIPLICATION CALCULATOR\n\n"); 
	//Variables declared with pointers for matrix dimensions that
	//get passes back to main by the user_prompt function below
	int ra, ca, rb, cb; 
	//Pointers to the above variables 
	int *ra_ptr = &ra; 
	int *ca_ptr = &ca; 
	int *rb_ptr = &rb; 
	int *cb_ptr = &cb; 
	//Prompts user for input and checks said user input,
	//gets the size of the matrices from the user and stores them 
	//here in main for later use
	user_prompt(ra_ptr, ca_ptr, rb_ptr, cb_ptr); 
	//Declares a variable to store the entire size of each matrix 
	int size_of_a = ra*ca; 
	int size_of_b = rb*cb; 
	int size_of_c = ra*cb;
	//Declares a matrix based on the user defined size of the array 
	int ma[size_of_a]; 
	int mb[size_of_b]; 
	int mc[size_of_c]; 

	/* SPECIFY THE FILE TO BE READ IN BELOW HERE */ 
	/*********************************************/
	FILE* file = fopen("matrix1.txt", "r"); /* <-------------------------- FILE NAME HERE */ 
	/*********************************************/
	/* ----------------------------------------- */ 

	//Takes in predefined matrix, the size of said matrix, and the file to read in 
	store_matrix(ma, size_of_a, file); 
	store_matrix(mb, size_of_b, file); 
	//Shows the Inputted Matrices
	show(ma, mb, ra, ca, rb, cb); 
	//Runs the matrix multiplication calculation 
	matrix_multiply(ma, mb, mc, ra, ca, cb); 
	//Print the new matrix 
	print(mc, ra, cb); 
	//Closes the file reader
	fclose(file); 
	//Exit without error 
	return 0; 
}
/* End Main */ 

/*---------------------------------------------------------------------------*/ 

/* Matrix Multiplication Function */ 
void matrix_multiply(int* a, int* b, int* c, int ra, int ca, int cb) { 
	//For loop indicies 
	int i, j, k;
	//Counter for place in resulting matrix 
	int r = 0;
	int sum = 0; 
	//Iterates through matrix A based on the columns of B
	for (i = 0; i < cb; i++) { 
		//Iterates through matrix B based on the rows of A
		for (j = 0; j < ra; j++) { 
			//Indexes into both A and B
			for (k = 0; k < ca; k++) { 
				sum += a[ca*i+k]*b[cb*k+j];
			}
			//Sets the sum of the above loop equal 
			//to the cells in the resulting matrix 
			c[r] = sum; 
			//Counter to properly iterate through 
			//the resulting array 
			r++; 
			//Resets the sum back to 0 so it
			//can properly do the addition for each cell 
			sum = 0; 
		}
	}
}
/* End Matrix Multiplication Function */ 

/*---------------------------------------------------------------------------*/ 

/* Print Function */ 
void print(int* result, int row, int col) { 
	int i, j;
	printf("*********************\n"); 
	printf("Result:\n"); 
	//Prints the result matrix from the multiplication of a and b
	for (i = 0; i < row; i++) { 
		for (j = 0; j < col; j++) { 
			printf("\t%d ", result[i*col+j]); 
		}
		printf("\n"); 
	}
}
/* End Print Function */ 

/*---------------------------------------------------------------------------*/ 

/* Show Function */ 
void show(int* a, int* b, int ra, int ca, int rb, int cb) { 
	int i, j;
	printf("Reading Matrices from File...\n\n"); 
	printf("Inputted Matrices:\n"); 
	printf("\nMatrix A:\n"); 
	//For loop to print matrix a 
	for (i = 0; i < ra; i++) { 
		for (j = 0; j < ca; j++) { 
			printf("\t%d ", a[i*ca+j]); 
		}
		printf("\n"); 
	}
	printf("Matrix B:\n");
	//For loop to print matrix b
	for (i = 0; i < rb; i++) { 
		for (j = 0; j < cb; j++) { 
			printf("\t%d ", b[i*cb+j]); 
		}
		printf("\n"); 
	}
}
/* End Show Function */ 

/*---------------------------------------------------------------------------*/ 

/* Prompts User, Grabs Input, Checks Input */ 
int is_valid(int ra, int ca, int rb, int cb) { 
	if (ca == rb) { 
		printf("\nInput indicates that matrices are compatible.\n"); 
		printf("*********************\n\n"); 
		return 1; 
	}
	else {
		printf("User defined input indicates that matrices are incompatible\n");
		printf("Please provide matrices that can be multiplied.\n\n"); 
		return 0; 
	}
}
int user_prompt(int *a, int *b, int *c, int *d) { 
	int inputa, inputb, inputc, inputd;
	do { //Menu input 
		printf("Please enter the size of your matrices.\n"); 
		inputa = get_rows_matrixa(); 
		*a = inputa; 
		inputb = get_columns_matrixa(); 
		*b = inputb; 
		inputc = get_rows_matrixb();
		*c = inputc; 
		inputd = get_columns_matrixb(); 
		*d = inputd;
	} 
	//Input comes back as valid
	while (is_valid(inputa, inputb, inputc, inputd) != 1);
	return 0; 
}
/* End Prompt and Input Grabber/Checker */ 

/*---------------------------------------------------------------------------*/ 

/* File Reader and Storer */
void store_matrix(int* m, int s, FILE* f) {
	//Declare ints for loops 
	int i, j; 
	//Read from file and store in matrix
	for (i = 0; i < s; i++) {
		fscanf(f, "%d", &m[i]); 
	}
}
/* End File Reader and Storer */ 

/*---------------------------------------------------------------------------*/ 

/* Get functions for the respective rows and columns of each matrix */ 
int get_rows_matrixa(void) { 
	int rows; 
	printf("\tEnter the number of rows for the first matrix >> "); 
	scanf("%d", &rows); 
	return rows;
}
int get_columns_matrixa(void) { 
	int columns; 
	printf("\tEnter the number of columns for the first matrix >> "); 
	scanf("%d", &columns); 
	return columns;
}
int get_rows_matrixb(void) { 
	int rows; 
	printf("\tEnter the number of rows for the second matrix >> "); 
	scanf("%d", &rows); 
	return rows;
}
int get_columns_matrixb(void) { 
	int columns; 
	printf("\tEnter the number of columns for the second matrix >> "); 
	scanf("%d", &columns); 
	return columns;
}
/* End get functions */ 
