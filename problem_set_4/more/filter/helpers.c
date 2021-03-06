#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue
                            + image[i][j].rgbtGreen
                            + image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp_image[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp_image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = temp_image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = temp_image[i][width - 1 - j].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    float sum_blue, sum_green, sum_red;
    float average_blue, average_green, average_red;
    int average_count;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp_image[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum_blue = 0;
            sum_green = 0;
            sum_red = 0;
            average_count = 0;

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x < 0 || x >= height || y < 0 || y >= width)
                    {
                        continue;
                    }
                    else
                    {
                        sum_blue += temp_image[x][y].rgbtBlue;
                        sum_green += temp_image[x][y].rgbtGreen;
                        sum_red += temp_image[x][y].rgbtRed;
                        average_count++;
                    }
                }
            }

            average_blue = round(sum_blue / average_count);
            average_green = round(sum_green / average_count);
            average_red = round(sum_red / average_count);

            image[i][j].rgbtBlue = average_blue;
            image[i][j].rgbtGreen = average_green;
            image[i][j].rgbtRed = average_red;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height + 2][width + 2];
    const int Gx[3][3] = { {-1, 0, 1},
                            {-2, 0, 2},
                            {-1, 0, 1} };
    const int Gy[3][3] = { {-1, -2, -1},
                            {0, 0, 0},
                            {1, 2, 1} };
    float blue_gx, blue_gy, green_gx, green_gy, red_gx, red_gy;
    float sum_blue, sum_green, sum_red;

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == height + 1)
            {
                temp_image[i][j].rgbtBlue = 0;
                temp_image[i][j].rgbtGreen = 0;
                temp_image[i][j].rgbtRed = 0;
            }
            else if (j == 0 || j == width + 1)
            {
                temp_image[i][j].rgbtBlue = 0;
                temp_image[i][j].rgbtGreen = 0;
                temp_image[i][j].rgbtRed = 0;
            }
            else
            {
                temp_image[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
                temp_image[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
                temp_image[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            }
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            blue_gx = 0;
            blue_gy = 0;
            green_gx = 0;
            green_gy = 0;
            red_gx = 0;
            red_gy = 0;

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        for (int n = 0; n < 3; n++)
                        {
                            blue_gx += Gx[m][n] * temp_image[x][y].rgbtBlue;
                            blue_gy += Gy[m][n] * temp_image[x][y].rgbtBlue;
                            green_gx += Gx[m][n] * temp_image[x][y].rgbtGreen;
                            green_gy += Gy[m][n] * temp_image[x][y].rgbtGreen;
                            red_gx += Gx[m][n] * temp_image[x][y].rgbtRed;
                            red_gy += Gy[m][n] * temp_image[x][y].rgbtRed;
                        }
                    }
                }
            }

            sum_blue = round(sqrt(pow(blue_gx, 2) + pow(blue_gy, 2)));
            sum_green = round(sqrt(pow(green_gx, 2) + pow(green_gy, 2)));
            sum_red = round(sqrt(pow(red_gx, 2) + pow(red_gy, 2)));

            image[i - 1][j - 1].rgbtBlue = (sum_blue < 255) ? sum_blue : 255;
            image[i - 1][j - 1].rgbtGreen = (sum_green < 255) ? sum_green : 255;
            image[i - 1][j - 1].rgbtRed = (sum_red < 255) ? sum_red : 255;
        }
    }
    return;
}
