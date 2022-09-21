#include <stdio.h>
#include "cs50.h"

void pyramid(int height);

int main(void)
{
    // Taking User Input //
    bool input_height = false;;
    while(input_height == false)
    {
        int height = get_int("Input the height of the pyramids(1-8): ");
        if(height >= 1 && height <= 8)
        {
            pyramid(height);
            input_height = true;
        }
        else
        {
            input_height = false;
        }
    }
    return 0;
}
void pyramid(int height)
{
    // Looping For Height //
    for(int i = 0 ; i < height ; i++)
    {
        // Looping for Columns/Width //
        // Looping for Spaces //
        for(int j = 1 ; j < (height-i) ; j++)
        {
            printf(" ");
        }
        // Looping for Hashes //
        for(int k = 0 ; k <= i ; k++)
        {
            printf("#");
        }
        // Looping For Spaces //
        for(int l = 0 ; l <= 1 ; l++)
        {
            printf(" ");
        }
        // Looping For Hashes //
        for(int m = 0 ; m <= i ; m++)
        {
            printf("#");
        }
        // Newline //
        printf("\n");
    }
}
