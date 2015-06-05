#ifndef A2LIB_H
#define A2LIB_H

/*
 * CMPSC 311 Assignment 2 constant and function definitions.  Complete the
 * definitions in this file and implement the functions in the file a2lib.c.
 * Wherever there is a ____, you need to fill in one or more things.
 */


/* Number of inputs */
#define NUM_INPUTS 15


// Hint: printf will round the value to 2 places for you if you ask it nicely */
void print_array_int(int array[],int length);

void print_array_dbl(double array[],int length);

double array_average(double array[],int length);

void reduce_value_by(double array_orig_value[],double array_avg);



// Hint: casting a double to an integer will always round it toward zero.  You
// may need separate cases for positive and negative numbers.
int round75(double array);


// Hint: what happens when you divide or multiply by 10?
int reverse_int(int **integer_value);


// Hint: start by implementing a bubble sort, and then modify it appropriately.
void parity_sort(int array[],int length);


// Hint: don't worry about doing this with logarithms.  Just divide by 10,
// count, and make sure your special cases are handled.
int get_num_length(int int_num);

// Hint: use your get_num_length function!
void print_sum(int array[],int length);



#endif
