// pt-br - en-us
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{

    long cardNumber;
    int cardLength = 0;
    int total = 0;
    long backupCardNumber;
    bool isSecondDigit = false;

    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber <= 0);

    backupCardNumber = cardNumber; // Armazena o número do cartão em uma váriavel que não é modificada

    while (cardNumber > 0) // Realiza o checksum no número do cartão.
    {
        int digit = cardNumber % 10;

        if (isSecondDigit && cardLength > 0)
        {
            int doubledDigit = digit * 2;

            do
            {
                total += doubledDigit % 10;
                doubledDigit /= 10;
            }
            while (doubledDigit % 10 > 0);
        }
        else
        {
            total += digit;
        }

        cardNumber /= 10;
        isSecondDigit = !isSecondDigit;
        cardLength++;
    }

    if ((total % 10 == 0)) // Verifica o modelo do cartão, caso seja válido!
    {

        int firstNumbers = backupCardNumber / pow(10, (cardLength - 2)); // Pega os dois primeiros dígitos
        int firstNumber = backupCardNumber / pow(10, (cardLength - 1)); // Pega o primeiro dígito

        if ((firstNumbers == 34 || firstNumbers == 37) && (cardLength == 15))
        {
            printf("AMEX\n");
        }
        else if ((firstNumbers >= 51 && firstNumbers <= 55) && (cardLength == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((firstNumber == 4) && (cardLength == 13 || cardLength == 16))
        {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
