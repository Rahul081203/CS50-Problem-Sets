#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Checking for any more argv arguments //
    if (argv[2] != NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checking if the entered argument is NULL //
    else if (argv[1] == NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checking if the length of key entered is not equal to 26 //
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // If no problem then continue //
    else
    {
        printf("");
    }
    // Storing the argument entered in string s1 //
    string s1 = argv[1];
    // Declaring an array of all the alphabets in the lower case //
    char s2[26] = "abcdefghijklmnopqrstuvwxyz";

    // Loop to check that no letter is entered twice in the key //
    int repeat = 0;
    for (int i = 0 ; i < strlen(s1) ; i++)
    {
        for (int j = i + 1 ; j < strlen(s1) ; j++)
        {
            if (s1[i] == s1[j])
            {
                repeat = 1;
                break;
            }
        }
        if (repeat != 0)
            break;
    }
    if (repeat != 0)
    {
        printf("Can't assign same cipher letter to different alphabets !\n");
        return 1;
    }

    // Loop to check that all the letters in the key are alphabets //
    for (int k = 0 ; k < strlen(s1) ; k++)
    {
        int alpha = 1;
        for (int l = 0 ; l < strlen(s2) ; l++)
        {
            if (tolower(s1[k]) == s2[l])
            {
                alpha = 1;
                break;
            }
            else
            {
                alpha = 0;
            }
        }
        if (alpha == 0)
        {
            printf("Key should only consist of alphabets.\n");
            return 1;
        }
    }
    // User Input //
    string plaintext = get_string("plaintext: ");

    // Looping through the entered word //
    for (int m = 0 ; m < strlen(plaintext) ; m++)
    {
        // Storing each alphabet one-by-one in variable 'letter' //
        char letter = plaintext[m];
        for (int x = 0 ; x < 26 ; x++)
        {
            // Storing uppercase and lowercase alphabets in separate variables chr1 and chr2 //
            char chr1 = x + 65;
            char chr2 = x + 97;
            // Comparing using Conditional statements //
            if (letter == chr1)
            {
                plaintext[m] = toupper(s1[x]);
            }
            else if (letter == chr2)
            {
                plaintext[m] = tolower(s1[x]);
            }
            else
            {
                plaintext[m] = plaintext[m];
            }
        }
    }
    // Printing the output ciphertext //
    printf("ciphertext: %s\n", plaintext);

    return 0;
}