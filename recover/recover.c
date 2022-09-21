#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Defining a unsigned integer as type BYTE
    typedef uint8_t BYTE;
    // Declaring a buffer variable to store the blocks
    BYTE buffer[512];
    // Defining count of output file starting from 0
    int out_count = 0;
    // Declaring a filename of 32 bytes (at most)
    char filename[32];
    // Initialising an output file pointer as img
    FILE *img = NULL;
    // Checking if the size of blocks read is equal to the size of buffer
    while (fread(buffer, 1, sizeof(buffer), file) == sizeof(buffer))
    {
        // Checking for Start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not the first image, then first close the file
            if (out_count >= 1)
            {
                fclose(img);
            }
            // Assigning new file name
            sprintf(filename, "%03i.jpg", out_count);
            // Opening output file
            img = fopen(filename, "w");
            // Increasing count for the next file
            out_count ++;
        }
        // Check if Output image is blank right now
        if (img)
        {
            fwrite(buffer, 1, sizeof(buffer), img);
        }
    }

    // Close files
    fclose(file);
    fclose(img);
}