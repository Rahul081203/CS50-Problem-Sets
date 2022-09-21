#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Calculating the average value of graysacle for the pixel
            int avg_col = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtBlue = avg_col;
            image[i][j].rgbtGreen = avg_col;
            image[i][j].rgbtRed = avg_col;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Storing the RGB value of the pixel in the variables as given in the question
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            // Calculating the Sepia value of RGB using thegiven algorithm
            int sepiaRed = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            int sepiaGreen = round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            int sepiaBlue = round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));
            // Other Cases of Sepia if RGB value > 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Making a copy of the dimensions of the same image
    RGBTRIPLE copy[height][width];
    // Traversing the Pixel rows
    for (int i = 0 ; i < height ; i++)
    {
        // Traversing Individual Pixels
        for (int j = 0 ; j < width ; j++)
        {
            copy[i][j] = image[i][width - j - 1];
        }
    }
    // Copying the image from copy to original image
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Initiating Required Variables and a copy of similar image dimensions
    int sum_red, sum_blue, sum_green, avg_red, avg_green, avg_blue;
    float mem_count = 0;
    RGBTRIPLE copy[height][width];
    for (int row = 0 ; row < height ; row ++)
    {
        // Case of first row
        if (row == 0)
        {
            for (int col = 0 ; col < width ; col ++)
            {
                // Default values of RGB and averages as zero
                sum_red = 0, sum_blue = 0, sum_green = 0, avg_red = 0, avg_green = 0, avg_blue = 0, mem_count = 0;
                // Case of first column
                if (col == 0)
                {
                    for (int i = 0 ; i <= 1 ; i++)
                    {
                        for (int j = 0 ; j <= 1 ; j++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Case of Last Column
                else if (col == width - 1)
                {
                    for (int i = 0 ; i <= 1 ; i++)
                    {
                        for (int j = width - 1 ; j >= width - 2 ; j --)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Case of all others
                else
                {
                    for (int i = 0 ; i <= 1 ; i ++)
                    {
                        for (int j = (col - 1) ; j <= (col + 1) ; j ++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Calculating Averages
                avg_red = round(sum_red / mem_count);
                avg_blue = round(sum_blue / mem_count);
                avg_green = round(sum_green / mem_count);
                // Assigning values
                copy[row][col].rgbtRed = avg_red;
                copy[row][col].rgbtBlue = avg_blue;
                copy[row][col].rgbtGreen = avg_green;
            }
        }
        // Case of Last Row
        else if (row == (height - 1))
        {
            for (int col = 0 ; col < width ; col ++)
            {
                // Default values
                sum_red = 0, sum_blue = 0, sum_green = 0, avg_red = 0, avg_green = 0, avg_blue = 0, mem_count = 0;
                // Case of First column
                if (col == 0)
                {
                    for (int i = (height - 2) ; i <= (height - 1) ; i++)
                    {
                        for (int j = 0 ; j <= 1 ; j++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Case of Last Column
                else if (col == width - 1)
                {
                    for (int i = (height - 2) ; i <= (height - 1) ; i++)
                    {
                        for (int j = width - 1 ; j >= width - 2 ; j --)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                else
                {
                    for (int i = (height - 2) ; i <= (height - 1) ; i ++)
                    {
                        for (int j = (col - 1) ; j <= (col + 1) ; j ++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Calculating Averages
                avg_red = round(sum_red / mem_count);
                avg_blue = round(sum_blue / mem_count);
                avg_green = round(sum_green / mem_count);
                // Assigning the pixels to copy
                copy[row][col].rgbtRed = avg_red;
                copy[row][col].rgbtBlue = avg_blue;
                copy[row][col].rgbtGreen = avg_green;
            }
        }
        // All middle Rows
        else
        {
            for (int col = 0 ; col < width ; col ++)
            {
                // Default values
                sum_red = 0, sum_blue = 0, sum_green = 0, avg_red = 0, avg_green = 0, avg_blue = 0, mem_count = 0;
                // First column
                if (col == 0)
                {
                    for (int i = (row - 1) ; i <= (row + 1) ; i++)
                    {
                        for (int j = 0 ; j <= 1 ; j++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Last column
                else if (col == width - 1)
                {
                    for (int i = (row - 1) ; i <= (row + 1) ; i++)
                    {
                        for (int j = width - 1 ; j >= width - 2 ; j --)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // All others
                else
                {
                    for (int i = (row - 1) ; i <= (row + 1) ; i ++)
                    {
                        for (int j = (col - 1) ; j <= (col + 1) ; j ++)
                        {
                            sum_red += image[i][j].rgbtRed;
                            sum_blue += image[i][j].rgbtBlue;
                            sum_green += image[i][j].rgbtGreen;
                            mem_count += 1;
                        }
                    }
                }
                // Calculating Averages
                avg_red = round(sum_red / mem_count);
                avg_blue = round(sum_blue / mem_count);
                avg_green = round(sum_green / mem_count);
                // Assigning pixels to copy
                copy[row][col].rgbtRed = avg_red;
                copy[row][col].rgbtBlue = avg_blue;
                copy[row][col].rgbtGreen = avg_green;
            }
        }
// Copying the image from copy to original image
    }
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}
