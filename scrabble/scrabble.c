#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initializing an array of characters i.e. a string of alphabets //
    char alphabet[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Initializing a variable 'score' as 0 //
    int score = 0;
    // Looping inside of the given word //
    for (int j = 0 ; j < strlen(word) ; j++)
    {
        // Looping inside the array of alphabets to match the letters from the word entered //
        for (int k = 0 ; k < 26 ; k++)
        {
            // Comparing the letters //
            if (toupper(word [j]) == alphabet [k])
            {
                score += POINTS [k];
            }
        }
    }
    return score;
}
