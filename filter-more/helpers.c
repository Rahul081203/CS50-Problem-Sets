#include "helpers.h"
#include <math.h>

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
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Mx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int My[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE copy[height][width];
    int R[3][3], G[3][3], B[3][3];
    int gxr[3][3], gxg[3][3], gxb[3][3], gyr[3][3], gyg[3][3], gyb[3][3];
    int gxr_sum, gxg_sum, gxb_sum, gyr_sum, gyg_sum, gyb_sum;
    for (int row = 0 ; row < height ; row ++)
    {
        // Case of first row
        if (row == 0)
        {
            for (int col = 0 ; col < width ; col ++)
            {
                gxr_sum = 0, gxg_sum = 0, gxb_sum = 0, gyr_sum = 0, gyg_sum = 0, gyb_sum = 0;
                if (col == 0)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][0] = 0;
                        R[0][r] = 0;
                        G[r][0] = 0;
                        G[0][r] = 0;
                        B[r][0] = 0;
                        B[0][r] = 0;
                    }
                    for (int r = 0 ; r <= 1 ; r ++)
                    {
                        for (int c = 0 ; c <= 1; c ++)
                        {
                            R[r + 1][c + 1] = image[r][c].rgbtRed;
                            G[r + 1][c + 1] = image[r][c].rgbtGreen;
                            B[r + 1][c + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else if (col == width - 1)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][2] = 0;
                        R[0][r] = 0;
                        G[r][2] = 0;
                        G[0][r] = 0;
                        B[r][2] = 0;
                        B[0][r] = 0;
                    }
                    for (int r = 0 ; r <= 1 ; r ++)
                    {
                        for (int c = width - 2 ; c <= width -1 ; c ++)
                        {
                            R[r + 1][c + 2 - width] = image[r][c].rgbtRed;
                            G[r + 1][c + 2 - width] = image[r][c].rgbtGreen;
                            B[r + 1][c + 2 - width] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[0][r] = 0;
                        G[0][r] = 0;
                        B[0][r] = 0;
                    }
                    for (int r = 0 ; r <= 1 ; r ++)
                    {
                        for (int c = col - 1 ; c <= col + 1 ; c ++)
                        {
                            R[r + 1][c + 1 - col] = image[r][c].rgbtRed;
                            G[r + 1][c + 1 - col] = image[r][c].rgbtGreen;
                            B[r + 1][c + 1 - col] = image[r][c].rgbtBlue;
                        }
                    }
                }

                for (int i = 0 ; i <= 2 ; i ++)
                {
                    for (int j = 0 ; j <=2 ; j ++)
                    {
                        gxr[i][j] = (Mx[i][j])*(R[i][j]);
                        gxg[i][j] = (Mx[i][j])*(G[i][j]);
                        gxb[i][j] = (Mx[i][j])*(B[i][j]);
                        gyr[i][j] = (My[i][j])*(R[i][j]);
                        gyg[i][j] = (My[i][j])*(G[i][j]);
                        gyb[i][j] = (My[i][j])*(B[i][j]);
                    }
                }
                for (int x = 0 ; x <= 2 ; x ++)
                {
                    for (int y = 0 ; y <= 2 ; y ++)
                    {
                        gxr_sum += gxr[x][y];
                        gyr_sum += gyr[x][y];
                        gxg_sum += gxg[x][y];
                        gyg_sum += gyg[x][y];
                        gxb_sum += gxb[x][y];
                        gyb_sum += gyb[x][y];
                    }
                }
                if(gxr_sum > 255)
                {
                    gxr_sum = 255;
                }
                if(gyr_sum > 255)
                {
                    gyr_sum = 255;
                }
                if(gxg_sum > 255)
                {
                    gxg_sum = 255;
                }
                if(gyg_sum > 255)
                {
                    gyg_sum = 255;
                }
                if(gxb_sum > 255)
                {
                    gxb_sum = 255;
                }
                if(gyb_sum > 255)
                {
                    gyb_sum = 255;
                }
                copy[row][col].rgbtRed = round(sqrt(pow(gxr_sum, 2) + pow(gyr_sum, 2)));
                copy[row][col].rgbtGreen = round(sqrt(pow(gxg_sum, 2) + pow(gyg_sum, 2)));
                copy[row][col].rgbtBlue = round(sqrt(pow(gxb_sum, 2) + pow(gyb_sum, 2)));
            }
        }
        else if (row == (height -1))
        {
            for (int col = 0 ; col < width ; col ++)
            {
                gxr_sum = 0, gxg_sum = 0, gxb_sum = 0, gyr_sum = 0, gyg_sum = 0, gyb_sum = 0;
                if (col == 0)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][0] = 0;
                        G[r][0] = 0;
                        B[r][0] = 0;
                    }
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[2][r] = 0;
                        G[2][r] = 0;
                        B[2][r] = 0;
                    }
                    for (int r = height - 2 ; r <= height - 1 ; r ++)
                    {
                        for (int c = 0 ; c <= 1 ; c ++)
                        {
                            R[r - height + 2][c + 1] = image[r][c].rgbtRed;
                            G[r - height + 2][c + 1] = image[r][c].rgbtGreen;
                            B[r - height + 2][c + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else if (col == width - 1)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][2] = 0;
                        G[r][2] = 0;
                        B[r][2] = 0;
                        R[2][r] = 0;
                        G[2][r] = 0;
                        B[2][r] = 0;
                    }
                    for (int r = height - 2 ; r <= height - 1 ; r ++)
                    {
                        for (int c = width - 2 ; c <= width - 1 ; c ++)
                        {
                            R[r - height + 2][c + 2 - width] = image[r][c].rgbtRed;
                            G[r - height + 2][c + 2 - width] = image[r][c].rgbtGreen;
                            B[r - height + 2][c + 2 - width] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[2][r] = 0;
                        G[2][r] = 0;
                        B[2][r] = 0;
                    }
                    for (int r = height - 2 ; r <= height - 1 ; r ++)
                    {
                        for (int c = col - 1 ; c <= col + 1 ; c ++)
                        {
                            R[r - height + 2][c - col + 1] = image[r][c].rgbtRed;
                            G[r - height + 2][c - col + 1] = image[r][c].rgbtGreen;
                            B[r - height + 2][c - col + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                for (int i = 0 ; i <= 2 ; i ++)
                {
                    for (int j = 0 ; j <=2 ; j ++)
                    {
                        gxr[i][j] = (Mx[i][j])*(R[i][j]);
                        gxg[i][j] = (Mx[i][j])*(G[i][j]);
                        gxb[i][j] = (Mx[i][j])*(B[i][j]);
                        gyr[i][j] = (My[i][j])*(R[i][j]);
                        gyg[i][j] = (My[i][j])*(G[i][j]);
                        gyb[i][j] = (My[i][j])*(B[i][j]);
                    }
                }
                for (int x = 0 ; x <= 2 ; x ++)
                {
                    for (int y = 0 ; y <= 2 ; y ++)
                    {
                        gxr_sum += gxr[x][y];
                        gyr_sum += gyr[x][y];
                        gxg_sum += gxg[x][y];
                        gyg_sum += gyg[x][y];
                        gxb_sum += gxb[x][y];
                        gyb_sum += gyb[x][y];
                    }
                }
                if(gxr_sum > 255)
                {
                    gxr_sum = 255;
                }
                if(gyr_sum > 255)
                {
                    gyr_sum = 255;
                }
                if(gxg_sum > 255)
                {
                    gxg_sum = 255;
                }
                if(gyg_sum > 255)
                {
                    gyg_sum = 255;
                }
                if(gxb_sum > 255)
                {
                    gxb_sum = 255;
                }
                if(gyb_sum > 255)
                {
                    gyb_sum = 255;
                }
                copy[row][col].rgbtRed = round(sqrt(pow(gxr_sum, 2) + pow(gyr_sum, 2)));
                copy[row][col].rgbtGreen = round(sqrt(pow(gxg_sum, 2) + pow(gyg_sum, 2)));
                copy[row][col].rgbtBlue = round(sqrt(pow(gxb_sum, 2) + pow(gyb_sum, 2)));
            }
        }
        else
        {
            for (int col = 0 ; col < width ; col ++)
            {
                gxr_sum = 0, gxg_sum = 0, gxb_sum = 0, gyr_sum = 0, gyg_sum = 0, gyb_sum = 0;
                if (col == 0)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][0] = 0;
                        G[r][0] = 0;
                        B[r][0] = 0;
                    }
                    for (int r = row - 1 ; r <= row + 1 ; r ++)
                    {
                        for (int c = 0 ; c <= 1 ; c ++)
                        {
                            R[r - row + 1][c + 1] = image[r][c].rgbtRed;
                            G[r - row + 1][c + 1] = image[r][c].rgbtGreen;
                            B[r - row + 1][c + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else if (col == width - 1)
                {
                    for (int r = 0 ; r <= 2 ; r ++)
                    {
                        R[r][2] = 0;
                        G[r][2] = 0;
                        B[r][2] = 0;
                    }
                    for (int r = row - 1 ; r <= row + 1 ; r ++)
                    {
                        for (int c = width - 2 ; c <= width - 1 ; c ++)
                        {
                            R[r - row + 1][c - width + 1] = image[r][c].rgbtRed;
                            G[r - row + 1][c - width + 1] = image[r][c].rgbtGreen;
                            B[r - row + 1][c - width + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                else
                {
                    for (int r = row - 1 ; r <= row + 1 ; r ++)
                    {
                        for (int c = col - 1 ; c <= col + 1 ; c ++)
                        {
                            R[r - row + 1][c - col + 1] = image[r][c].rgbtRed;
                            G[r - row + 1][c - col + 1] = image[r][c].rgbtGreen;
                            B[r - row + 1][c - col + 1] = image[r][c].rgbtBlue;
                        }
                    }
                }
                for (int i = 0 ; i <= 2 ; i ++)
                {
                    for (int j = 0 ; j <=2 ; j ++)
                    {
                        gxr[i][j] = (Mx[i][j])*(R[i][j]);
                        gxg[i][j] = (Mx[i][j])*(G[i][j]);
                        gxb[i][j] = (Mx[i][j])*(B[i][j]);
                        gyr[i][j] = (My[i][j])*(R[i][j]);
                        gyg[i][j] = (My[i][j])*(G[i][j]);
                        gyb[i][j] = (My[i][j])*(B[i][j]);
                    }
                }

                for (int x = 0 ; x <= 2 ; x ++)
                {
                    for (int y = 0 ; y <= 2 ; y ++)
                    {
                        gxr_sum += gxr[x][y];
                        gyr_sum += gyr[x][y];
                        gxg_sum += gxg[x][y];
                        gyg_sum += gyg[x][y];
                        gxb_sum += gxb[x][y];
                        gyb_sum += gyb[x][y];
                    }
                }
                if(gxr_sum > 255)
                {
                    gxr_sum = 255;
                }
                if(gyr_sum > 255)
                {
                    gyr_sum = 255;
                }
                if(gxg_sum > 255)
                {
                    gxg_sum = 255;
                }
                if(gyg_sum > 255)
                {
                    gyg_sum = 255;
                }
                if(gxb_sum > 255)
                {
                    gxb_sum = 255;
                }
                if(gyb_sum > 255)
                {
                    gyb_sum = 255;
                }
                copy[row][col].rgbtRed = round(sqrt(pow(gxr_sum, 2) + pow(gyr_sum, 2)));
                copy[row][col].rgbtGreen = round(sqrt(pow(gxg_sum, 2) + pow(gyg_sum, 2)));
                copy[row][col].rgbtBlue = round(sqrt(pow(gxb_sum, 2) + pow(gyb_sum, 2)));
            }
        }

    }
    for (int i = 0 ; i < height ; i ++)
    {
        for (int j = 0 ; j < width ; j ++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
