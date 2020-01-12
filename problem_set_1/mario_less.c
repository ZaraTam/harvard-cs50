#include <stdio.h>
#include <cs50.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("What's the height?\n");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
