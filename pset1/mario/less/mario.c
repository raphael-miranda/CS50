//  en-us
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
        height = get_int("Height: "); // Get width by user input
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) { // Set Colums size by width
        // Draw Colums
        for (int j = (i+1); j < height; j++) {
            printf(" ");
        }
        // Draw hashes per line
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
