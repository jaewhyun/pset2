/**
 * After running the program, 
 * this program requires a user input of a number
 * to be used as a key to cipher a phrase also given by the user.
 * 
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // if the argc is not equal to 2, promt user for another integer
    if (argc != 2)
    {
        printf("give me an integer");
        // all is bad
        return 1;
    }
    
    // convert first string into an integer k
    int k = atoi(argv[1]);
    
    // get user input for plaintype
    string bcrypt = GetString();
    
    // assign variable for the string length of the plaintype
    int bcryptlen = strlen(bcrypt);

    // for every letter in bcrypt:
    for(int i = 0; i < bcryptlen; i++)
    {
        // check to see that the user input is an alphabet
        if(isalpha(bcrypt[i]))
        {
            // if the 'i'th character is an uppercase
            if(isupper(bcrypt[i]))
            {
                int letter = (bcrypt[i]);
                // compute for uppercase ASCII value and print
                int result = ((letter - 'A' + k)%26 +'A');
                printf("%c", result);
            }
            // if the 'i'th character is a lowercase
            else if(islower(bcrypt[i]))
            {
                int letter = (bcrypt[i]);
                // compute for lowercase ASCII value and print
                int result = ((letter - 'a' + k)%26 + 'a');
                printf("%c", result);
            }
        }
        // if the 'i'th character is not an alphabet, print original character
        else
        {
            printf("%c", bcrypt[i]);
        }
    }
    // print new line
    printf("\n");
    
    return 0;
}


