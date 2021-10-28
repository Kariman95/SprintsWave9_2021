#include <stdio.h>
#include <stdlib.h>

//Software Engineer Name:   Kariman Karam

//All inputs are unsigned character

/*
- Define your global variables if needed here:
actual_result
expected_result
- Please concider the memoery optimization.
*/

/*
- Define your functional prototypes used here:
sum
unittest
- Please concider optimum Misra C when writing your functions.
*/

//Prototype of the sum function
int sum(unsigned char, unsigned char);

//Prototype of the unittest function
void unittest(int, int);



int main()
{
//Please declare your initializations here.
    int num1, num2;
    int expected, actual;


//Please define your infinite loop here.
    while(1)
    {


//Please insert your screen visualization here.


//Please write an expression that takes 2 numbers from the user here (concider screen readability).
        printf("\n\nPlease enter the first number to be added:");
        scanf("%d",&num1);

        printf("Please enter the second number to be added:");
        scanf("%d",&num2);

        printf("Please enter the Expected result:");
        scanf("%d",&expected);

//Please write an expression that calls the two function, the activation logic function and the unit test function in sequence.
        actual = sum(num1, num2);
        unittest(actual, expected);
    }
    return 0;
}


//Please write the functional description of the sum function here:
int sum(unsigned char num1, unsigned char num2)
{
    int result = (unsigned char)num1 + (unsigned char)num2;
    return result;
}

//Pleas write the functional description of the unittest function here:
void unittest(int actual, int expected)
{
    if(actual == expected)
    {
        printf("Test Case Passed\n");
    }
    else
    {
        printf("Test Case Failed\n");
    }
}
