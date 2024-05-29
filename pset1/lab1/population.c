// pt-br - en-us
#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int tamanhoInicial;
    int tamanhoFinal;
    int anos = 0;

    do
    {
        tamanhoInicial = get_int("Start Size: "); // populacao inicial
    }
    while (tamanhoInicial < 9);

    do
    {
        tamanhoFinal = get_int("End Size: "); // populcao que quero chegar
    }
    while (tamanhoFinal < tamanhoInicial);

    // ano atual
    int nasceram = tamanhoInicial / 3; // quantas nasceram
    int morreram = tamanhoInicial / 4; // quantas morreram
    int populacao = tamanhoInicial;    // populacao inicial

    while (populacao < tamanhoFinal)
    {
        populacao += nasceram - morreram; // atualiza a populacao de lhamas
        nasceram = populacao / 3;         // atualiza quantos nasceram em base na populacao atual
        morreram = populacao / 4;         // atualiza quantos morreram em base na populacao atual
        anos++;
    }

    printf("Years: %d\n", anos);

}
