#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototype declaration of User-Defined Functions //
int count_letters(string word);
int count_words(string word);
int count_sentences(string word);

int main(void)
{
    // User input as text using get_string() //
    string text = get_string("Text: ");
    // Catching the values returned by the functions //
    int c_letter = count_letters(text);
    int c_word = count_words(text);
    int c_sentence = count_sentences(text);
    printf("Letter Count: %i\nWord Count: %i\nSentence Count: %i\n",c_letter,c_word,c_sentence);

    // Calculating the average count for 100 words //
    float L = (c_letter * 100.0) / c_word;
    float S = (c_sentence * 100.0) / c_word;
    printf("Average per 100 words:\nLetters: %lf\nSentences: %lf\n",L,S);
    // Coleman-Liau index Formula //
    float index1=(0.0588 * L) - (0.296 * S) - 15.8;
    float mid=(ceil(index1)+floor(index1))/2;
    int index;
    if(index1 >= mid)
    {
        index=ceil(index1);
    }
    else
    {
        index=floor(index1);
    }

    // Special Cases //
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string word)
{
    int i, c_letter = 0;
    // Declaring a string of all uppercase alphabets //
    char alphabet [26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Comparing each character/bit for finding alphabets //
    for (i = 0 ; i < strlen(word) ; i++)
    {
        for (int x = 0 ; x < strlen(alphabet) ; x++)
        {
            if (toupper(word [i]) == alphabet [x])
            {
                c_letter += 1;
            }
        }
    }
    return c_letter;
}
int count_words(string word)
{
    int j, c_word = 1;
    for (j = 0 ; j < strlen(word) ; j++)
    {
        if (word [j] == ' ')
        {
            c_word += 1;
        }
    }
    return c_word;
}
int count_sentences(string word)
{
    int k, c_sentences = 0;
    for (k = 0 ; k < strlen(word) ; k++)
    {
        if (word [k] == '.' || word [k] == '?' || word [k] == '!')
        {
            c_sentences += 1;
        }
    }
    return c_sentences;
}