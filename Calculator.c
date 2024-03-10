//Date: 2024.01.19
//Purpose: Simple command line calculator with 4 basic operations
#include<stdio.h>
#pragma warning(disable: 4996) // Disable scanf unsafe warning

//TODO: scan for space, then start over, give error! do not let 2 numbers to be entered in 1 input!

//Function declarations
double addition(double a, double b);
double substraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
double get_user_input(void);
char get_user_operation(void);
double calculate_result(double a, double b, char operator);

int main() {

	while (1) {
		double a = 0;
		double b = 0;
		double result = 0;
		char operation;

		a = get_user_input(); //Get first input
		operation = get_user_operation(); // Get operation
		b = get_user_input(); //Get second input
		result = calculate_result(a, b, operation);
		printf("%.2lf\n\n", result);//display result
	}
	
	return 0;
}

//Function definitions
double addition(double a, double b) {
	return a + b;
}

double substraction(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

double division(double a, double b) {
	return a / b;
}

double get_user_input(void) {
	printf("Input the number: ");
	double input1 = 0;
	scanf("%lf", &input1);

	// Clear input buffer
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	return input1;
	//TODO: scan for space, then start over, give error! do not let 2 numbers to be entered in 1 input!
}
char get_user_operation(void) {
	char operator = ' ';

	while (1) {
		printf("Input the operator (+,-,*,/): ");
		scanf("%c", &operator);
		if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
			break; //valid operation 
		}
		printf("\nInput a valid operation!\n");
		// Clear input buffer, try again
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	}
	
	// Clear input buffer
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	return operator;
}

double calculate_result(double a, double b , char operator) {
	double result = 0;

	/*if (operator == '+') {
		result = addition(a, b);
	}
	else if (operator == '-') {
		result = substraction(a, b);
	}
	else if (operator == '*') {
		result = multiplication(a, b);
	}
	else if (operator == '/') {
		result = division(a, b);
	}
	*/

	//Same, but memory efficient
	switch (operator) {
	case '+':
		result = addition(a, b);
		break;
	case '-':
		result = substraction(a, b);
		break;
	case '*':
		result = multiplication(a, b);
		break;
	case '/':
		result = division(a, b);
		break;
	}

	return result;
}