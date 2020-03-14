#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }

    // Check JPEG signature in each block of 512 bytes
    int block_size = 512;
    unsigned char buffer[block_size];
    int byte_count = fread(buffer, 1, block_size, file);

    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        if ((buffer[3] & 0xf0) == 0xe0)
        {
            printf("jpg\n");
        }
        
    }
    else
    {
        printf("Not jpg\n");
    }
}
