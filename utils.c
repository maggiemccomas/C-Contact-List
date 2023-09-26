
# include <stdio.h>
# include "utils.h"

/*
* A C program that includes a helper functions to change any lowercase character to uppercase
* Maggie McComas
*/

/*
* Purpose: changes any lowercase character to uppercase using char arithmetic
* Input: char str []
* Output: none
*/
void upper (char str []){
    int index = 0;

    while (str[index] != '\0') {

        if (str[index] >= 'a' && str[index] <= 'z'){
            str[index] = str[index] - 32;
        }
        
        index = index + 1;
    }
}