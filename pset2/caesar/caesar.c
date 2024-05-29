// en-us
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) // argument count - argument values
{
    // check if argc is equals two
    if (argc == 2)
    {
        // check if char by char is a digit
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // convert argv[1] to integer

        int k = atoi(argv[1]);

        printf("plaintext: ");
        string plaintext = get_string("");

        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++) // Change char by key value
        {
            if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'a') + k) % 26) + 'a');
            }
            else if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'A') + k) % 26) + 'A');
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }

        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
