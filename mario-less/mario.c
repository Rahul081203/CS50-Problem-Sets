#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    //User Input //
    bool input_height = false;
    while(input_height == false)
    {
        int height = get_int("Enter Height: ");
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
    // Looping for Height //
    for(int i = 0 ; i < height ; i++)
    {
        // Looping For Columns //
        for(int j = 1 ; j < (height-i) ; j++)
        {
            printf(" ");
        }
        for(int k = 0 ; k <= i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}