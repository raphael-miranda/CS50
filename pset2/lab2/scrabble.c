// en-us
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);
void check_winner();

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    compute_score(word1);
    check_winner(score1, score2);

}

// Calculate the word points
int compute_score(string word)
{
    int total = 0;
    // Get chars of word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Get index of char in alphabet
        for (int j = 0; j < 26; j++)
        {
            // Change to lower and increase points
            if (tolower(word[i]) == alphabet[j])
            {
                total += POINTS[j];
            }
        }
    }

    return total;
}

// Get the winner between two scores
void check_winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
