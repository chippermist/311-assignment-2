/*
 The a2lib.c file containing the definitions of the functions based in a2lib.h file.

 Implementations of functions is in the file.

 */


#include<stdio.h>
#include "a2lib.h"

/*
 *This function takes in a integer array
 * and prints the array elemnts using a pointer reference
 * since all then arrays are pointers the array does not require
 *
 *Parameters: integer array and length of array
 *
 *Return value: none
 */
void print_array_int(int array[],int length)
{
	int i=0;
	printf("[ ");
	for(i=0; i<length; i++)
	{
		printf("%d",*array);
		if(i<length-1)
		{
			printf(", ");
			//conditional so that it does not print at 
			//the very last enement
		}
		array++;
	}
	printf(" ]\n");
}
// end of the function print_array_int()

/*
 *This function prints the elements of a double array. This takes in a double ar *ray only
 *
 *Parameters: double array and length of array
 *
 *Return Value: none
 */
void print_array_dbl(double array[],int length)
{
	int i=0;	
	printf("[ ");
	for(i=0; i<length; i++)
        {
                printf("%.2lf",*array);
		if(i<length-1)
		{
			printf(", ");
			//conditional to print ','
		}
		array++;
        }
	printf(" ]\n");

}
//end of the function print_array_dbl()

/*
 *This function calculates the average of a provided array. It can take a double *array and would also work with a integer array if required.
 *
 *Parameters: array and the length of the array
 *
 *Return Value: the average calculated
 */
double array_average(double array[],int length)
{

	double sum=0;
        float average;
	int i=0;
        for(i=0; i<length;i++)
        {
                sum += *array;
		array++;
        }
        average = sum/NUM_INPUTS;

        return average;
}
//end of the array_average() function

/*
 *This function reduced the value of the original array by substracting the aver *age value by each of the array elements
 *
 *Parameters: the original array value and the array average
 *
 *Return value: none
 */
void reduce_value_by(double array_orig_value[],double array_avg)
{
	//int i=0;
	double reduced_array_value=0.0;
        reduced_array_value = array_avg - *array_orig_value;
        *array_orig_value = reduced_array_value;
}
//End of the reduce_value_by() function

/*
 *This function rounds the double number by .75 such that if a number has decimal value less than 0.75 then it's gonna be the previous number else the next roun *ded number
 *
 *Parameters: array of the numbers
 *
 *Return value: 23.54 then 23, 24.78 then 25 etc.
 */
int round75(double array)
{
	int temp=0;
	array = array + 0.25;
	temp = array;

	return temp;
}
//end of the round75() function

/*
 *This function reverses the interger values. So 17 would become 71 and so on.
 *
 *Parameters: reference to integer value
 *
 *Return Value: 0 if success, 1 otherwise
 */
int reverse_int(int **integer_value)
{
	int reverse=0;
	if(**integer_value < 1)
	{
		return 1;
	}	
	else
	{	
		while(**integer_value!=0)
		{
			reverse = reverse*10;
			reverse = reverse + (**integer_value % 10);
			**integer_value = **integer_value/10;
		}
	}	
	**integer_value = reverse;
	return 0;
}
//end of the reverse_int function

/*
 *This fuction sorts the array such that there are even numbers at the front and *odd numbers at the end. But in even and odd number seperately doesnt change th *e order
 *
 *Parameters: array and it's length
 *
 *Return value: none
 */
void parity_sort(int array[], int length)
{
	int i=0, j=0,swap;
	int resume = 1;
	
	//using resume as  a flag variabble
	while(resume == 1)
	{
		resume = 0;
		//assuming the position of i to go from the first element
		//to the second last element
		for(i=0; i<=(length-2); i++)
		{
			j=i+1;
			//comparing the array element so that both are not even
			//or odd
			//if they are even and odd it swaps the elements
			if( (array[i] % 2 != 0) && (array[j] %2 == 0) )
			{

				// swap i and i+1
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				//modifies the original value of the array
				resume = 1;
			}
		}	
	}
}
//end of parity sort()

/*
 *This number takes in a integer number and returns the number of characters required to print this
 *
 *Parameters: Integer value
 *
 *Return Value: no of charcters required to print
 */
int get_num_length(int int_num)
{
	int num_length=0,neg=0;
	if(int_num<0)
	{
		int_num = -(int_num);
		neg=1;
	}

	while(int_num !=0)
	{
		int_num=int_num/10;
		num_length++;
	}

	return num_length+neg;
}
//end of get_num_length() function

/*
 *This function prints the sum of the array after printing the numbers in verti
 *cally. 
 *
 *Parameters: the array of integers and the length of the array
 *
 *Return value: none
 */
void print_sum(int array[], int length)
{
	int i=0,sum = 0;
	int *p = &array[0];
	for(i=0; i<length; i++)
	{
		sum = sum + *array;
		array++;
	}
//the %(num)d makes a block of 7 characters and then prints out the number using//
//the characters it reqired to print indenting

	for(i=0; i<(length-1); i++)
	{
		
		printf("\t%7d\n",*p);
		p++;

	}
	if(i==(length-1))
	{
	
	printf("+\t%7d\n",*p);
	}
	printf("----------------\n");
	printf("\t%7d\n",sum);
}
//end of print_sum() function
