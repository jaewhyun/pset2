/**
 * After running the program, 
 * this program requires a user input of a key word
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
    // if argc is not equal to 2, promt user for a word
    if (argc != 2)
    {
        printf("give me a word");
        // all is bad
        return 1;
    }
    
    // assign user input to a string variable: 'keyword'
    string keyword = (argv[1]);
    
    // assign string length of keyword to a variable called 'keylen'
    int keylen = strlen(keyword);
    
    // for every 'i'th character in keyword:
    for(int i = 0; i < keylen; i++)
    {
        // check to see if 'i'th character of keyword is an alphabet
        if(isalpha(keyword[i]))
        {
            // if the 'i'th character is an uppercase, convert to alphabetical index
            if(isupper(keyword[i]))
            {
                int letter = (keyword[i]);
                keyword[i] = ((letter - 'A'));
            }
            // if the 'i'th charaacter is a lowercase, convert to alphabetical index
            else if(islower(keyword[i]))
            {
                int letter = (keyword[i]);
                keyword[i] = ((letter - 'a'));
            }
        }
        // if 'i'th character is not an alphabet, prompt user for a word
        else
        {
            printf("give me a word\n");
            // all is bad
            return 1;
        }
    }
    
    // prompt user for a phrase to be coded
    string plaintext = GetString();
    
    // assign variable 'ptlen' to the string length of the phrase
    int ptlen = strlen(plaintext);
    
    // assign variable j = 0 for the keyword wrap around itself
    int j = 0;
    // for every 'i'th character of plaintext
    for(int i = 0; i < ptlen; i++)
    {
        // if 'i'th character is an alphabet
        if(isalpha(plaintext[i]))
        {
            // if 'i'th character is an uppercase
            if(isupper(plaintext[i]))
            {
                // compute for uppercase ASCII value and print
                int letter = (plaintext[i]);
                int result = ((letter - 'A' + keyword[j%keylen])%26 +'A');
                printf("%c", result);
            }
            // if 'i'th character is a lower case
            else if(islower(plaintext[i]))
            {
                // compute for lowercase ASCII value and print
                int letter = (plaintext[i]);
                int result = ((letter - 'a' + keyword[j%keylen])%26 + 'a');
                printf("%c", result);
            }
            j++;
        }
        // if 'i'th character is not an alphabet, print original character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    // print new line
    printf("\n");

    // all is good
    return 0;
}

