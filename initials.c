/**
 * After running the program
 * the program outputs the user initials in upper case letters
 * after user inputs his/her name.
 * 
*/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    // get user input for name
    string s = GetString();
    
    // print upper case initials
    printf("%c", toupper(s[0]));
    
    // for every letter of the string
    for(int i = 0; i < strlen(s)-1; i++)
    {
        // if the 'i'th character is a space
        if (isspace(s[i]))
        {
            // print the next character in an upper case
            printf("%c", toupper(s[i+1]));
        }
    }
    // print new line
    printf("\n");
}

