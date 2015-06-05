/*
 * The main code file for CMPSC 311 assignment 2.
 *
 * Implement your main function here.  See the assignment for full instructions.
 * Wherever there is a ____, you need to fill in one or more things.
 */


#include <stdio.h>
#include "a2lib.h"
#include <time.h>


/*
 * Main function for the "assign2" program.  This function reads in an array of
 * numbers and does a variety of processing on it.
 *
 * Parameters: none
 *
 * Return value: 0 if successful, 1 otherwise
 */


int main(void)
{
	// Declare your variables here
	double inputs[NUM_INPUTS];
	int array_int[NUM_INPUTS];
	double array_avg;

	int i;
//	time_t ltime;
//	ltime=time(NULL);
	

	// Read double-precision values into an array from standard input
	for (i = 0; i < NUM_INPUTS; i++) {
		scanf("%lf", &inputs[i]);
	}
	

	// Display the inputs in a nice format
	printf("Input values:\n");
	print_array_dbl(inputs,NUM_INPUTS);

	// Calculate and display the average of the elements in the array
	array_avg = array_average(inputs,NUM_INPUTS);
	printf("The average of the inputs is %.2f.\n", array_avg);

	// Use the reduce_value_by function to subtract the average value from
	// each of the elements in the array (this will center the values around
	// zero).


	for (i = 0; i < NUM_INPUTS; i++) 
	{
		//centering the array by substracting the average
		//from each element
		reduce_value_by(inputs,array_avg);
		
	}

	// Display the recentered array
	printf("Recentered input values:\n");
	//printing the double array after recentering
	print_array_dbl(inputs,NUM_INPUTS);


	// Compute the integer array.  Round each element up (away from zero) if
	// its decimal part is >= .75, down otherwise.
	for (i = 0; i < NUM_INPUTS; i++) 
	{
		array_int[i] = round75(inputs[i]);
		//runs the round75 function and then rounds off the number
		//by adding 0.25 to the original number and taking
		//integer value
	} 


	// Display the rounded values
	printf("Rounded integers:\n");
	//printing the new integer array
	print_array_int(array_int,NUM_INPUTS);

//	fprintf(stderr, "%s \nRounded Integers:\n",asctime(localtime(&ltime)));
//	fprintf(stderr, "%s",asctime(localtime(&ltime)));
//	print_array_int(array_int,NUM_INPUTS);
//	printf("\n");

	// Attempt to reverse the digits of each value in the integer array
	int *p = &array_int[0];
	//creating a pointer referencing to the array_int[]
	for(i = 0; i < NUM_INPUTS; i++)
	{
		reverse_int(&p);
		//calling reverse_int function to reverse the referenced number
		p=p+1;
		//adding the pointer means stepping up in a array
		//array[i+1] = p+1
	}

	// And display the results
	printf("Reversed digits:\n");
	//printing out the original array with reversed digits
	print_array_int(array_int,NUM_INPUTS);

	// Move all the even numbers to the front of the integer array
	//using a variation of bubble sort
	//sorting the array from even to odd 
	parity_sort(array_int,NUM_INPUTS);


	// Display the reordered array
	printf("After parity sort:\n");
	//printing the original array after modifying it
	print_array_int(array_int,NUM_INPUTS);

	// Display a vertical sum
	printf("Sum of values:\n");
	//printing the original array vertically showing
	//a sum of the numbers
	print_sum(array_int,NUM_INPUTS);
	
	printf("%d",get_num_length(inputs[0]));

	
//	fprintf(stderr, "%s Rounded Integers:\n",asctime(localtime(&ltime)));
//	fprintf(stderr, "%s",asctime(localtime(&ltime)));
//	fprintf(stderr, "%s",asctime(localtime(&ltime)));
//	fprintf(stderr, "%s",asctime(localtime(&ltime)));

	// Program finished successfully
	return 0;
}
