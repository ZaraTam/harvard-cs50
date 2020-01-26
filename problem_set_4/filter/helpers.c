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
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue, sepiaGreen, sepiaRed;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = round(0.272 * image[i][j].rgbtRed
                            + 0.534 * image[i][j].rgbtGreen
                            + 0.131 * image[i][j].rgbtBlue);

            sepiaGreen = round(0.349 * image[i][j].rgbtRed
                            + 0.686 * image[i][j].rgbtGreen
                            + 0.168 * image[i][j].rgbtBlue);

            sepiaRed = round(0.393 * image[i][j].rgbtRed
                            + 0.769 * image[i][j].rgbtGreen
                            + 0.189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepiaBlue < 255) ? sepiaBlue : 255;
            image[i][j].rgbtGreen = (sepiaGreen < 255) ? sepiaGreen : 255;
            image[i][j].rgbtRed = (sepiaRed < 255) ? sepiaRed : 255;
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

            average_blue = sum_blue / average_count;
            average_green = sum_green / average_count;
            average_red = sum_red / average_count;

            image[i][j].rgbtBlue = round(average_blue);
            image[i][j].rgbtGreen = round(average_green);
            image[i][j].rgbtRed = round(average_red);
        }
    }
    return;
}
