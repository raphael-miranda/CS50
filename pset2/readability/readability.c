// en-us
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{

    int words = 0;
    int letters = 0;
    int phrases = 0;

    // Get user input
    string text = get_string("Text: ");

    // Get letters, words & phrases.
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            phrases++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
    }

    words += 1;

    // Calculate the average of letters and phrases
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) phrases / (float) words) * 100;
    float subindex = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(subindex);

    // Output
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
