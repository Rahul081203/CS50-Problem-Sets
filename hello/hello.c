#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Getting User Input
    string name = get_string("Your name: ");
    // Printing the string using placeholder for string - %s
    printf("Hello, %s\n", name);
    return 0;
}