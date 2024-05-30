// en-us - pt-br
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Arrays para pegar a index do elemento no alfabeto
    int min[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int mai[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string key = argv[1];

    // Checa se a quantidade de argumentos é igual a 2 e se a chave possui 26 digitos
    if (argc == 2 && strlen(key) == 26)
    {
        // Verificando se todos os digitos sao alfabéticos
        for (int i = 0; i < 26; i++) {
            if (!isalpha(key[i]))
            {
                printf("Usage: ./caesar [26 letters key]\n");
                return 1;
            }
        }

        // Verificando se não há letras repetidas
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            for (int j = (i+1); j < n; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Dont repeat letters!\n");
                    return 1;
                }
            }
        }

        printf("plaintext: ");
        string plaintext = get_string("");

        printf("ciphertext: ");

        // Pega caractere por caractere do texto e cifra
        for (int i = 0, n = strlen(plaintext); i < n; i++) {
            for (int j = 0, k = strlen(key); j < k; j++)
            {

                if (isupper(plaintext[i]))
                {
                    if (plaintext[i] == mai[j])
                    {
                        printf("%c", toupper(key[j]));
                    }
                }

                if (islower(plaintext[i]))
                {
                    if (plaintext[i] == min[j])
                    {
                        printf("%c", tolower(key[j]));
                    }
                }
            }

            // Caso não seja um caractere alfabético apenas imprima na tela
            if (!islower(plaintext[i]) && !isupper(plaintext[i])) {
                printf("%c", plaintext[i]);
            }
        }

        printf("\n");
        return 0;
    }
    // Retorna um erro se os argumentos forem mais do que um ou o argumento
    // tiver mais do que 26 caracteres
    else
    {
        printf("Usage: ./caesar [26 digits key]\n");
        return 1;
    }

}
