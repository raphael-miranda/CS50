// en-us
#include <cs50.h>
#include <stdio.h>

void generatePiramyd();

int main()
{
    generatePiramyd();
}

void generatePiramyd() {
    int height;

    do
    {
        height = get_int("Height: "); // Get height by user input
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) { // Set Colums size by height

        // Draw whitespaces before hashes
        for (int j = (i+1); j < height; j++) {
            printf(" ");
        }

        // Draw Hashes
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        printf("  "); // Draw whitespaces between the colums

        // Draw right hashes
        for (int k = 0; k <= i; k++) {
            printf("#");
        }

        printf("\n");
    }
}
