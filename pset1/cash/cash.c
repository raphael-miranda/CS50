// pt-br - en-us
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main()
{

    int troco = 0;
    float valor;

    do
    {
        valor = get_float("Troca devida: ");
    }
    while (valor <= 0);

    int centavos = round(valor * 100);

    while (centavos >= 25) { centavos -= 25; troco++; }
    while (centavos >= 10) { centavos -= 10; troco++; }
    while (centavos >= 5) { centavos -= 5; troco++; }
    while (centavos >= 1) { centavos -= 1; troco++; }

    printf("%i\n", troco);
}
