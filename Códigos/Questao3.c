/* 
  QUESTÃO 03 - A Razão de Eficiência de um Número
  Aluno: Heitor Macêdo Ricardo
  Matrícula: 241039073
  Linguagem: C (compilador: gcc)
*/
#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    printf("Digite N: ");
    scanf("%lld", &n);

    if (n < 1 || n > 100000) {
        printf("Valor fora do intervalo.\n");
        return 0;
    }

    long long temp = n;
    long long primes[64];
    int exp[64];
    int k = 0;

    // fatoração
    if (temp % 2 == 0) {
        int c = 0;
        while (temp % 2 == 0) {
            temp /= 2;
            c++;
        }
        primes[k] = 2;
        exp[k++] = c;
    }

    for (long long p = 3; p * p <= temp; p += 2) {
        if (temp % p == 0) {
            int c = 0;
            while (temp % p == 0) {
                temp /= p;
                c++;
            }
            primes[k] = p;
            exp[k++] = c;
        }
    }

    if (temp > 1) {
        primes[k] = temp;
        exp[k++] = 1;
    }

    // tau e sigma
    unsigned long long tau = 1, sigma = 1;

    for (int i = 0; i < k; i++) {
        tau *= (exp[i] + 1);

        unsigned long long p = primes[i];
        unsigned long long pot = 1;
        for (int j = 0; j < exp[i] + 1; j++) pot *= p;

        unsigned long long termo = (pot - 1) / (p - 1);
        sigma *= termo;
    }

    if (n == 1) {
        tau = 1;
        sigma = 1;
    }

    double razao = (double)tau / (double)sigma;
    printf("%.2f\n", razao);

    return 0;
}