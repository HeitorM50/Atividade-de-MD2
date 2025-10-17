/* 
  QUESTÃO 02 - MMC e MDC
  Aluno: Heitor Macêdo Ricardo
  Matrícula: 241039073
  Linguagem: C (compilador: gcc)
*/
#include <stdio.h>

int mdc(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int main() {
    int N, ciclos[10], resultado;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &ciclos[i]);

    resultado = ciclos[0];
    for (int i = 1; i < N; i++)
        resultado = mmc(resultado, ciclos[i]);

    if (resultado > 50)
        printf("Nao e possivel sincronizar todas as chaves dentro do limite.\n");
    else
        printf("%d\n", resultado);

    return 0;
}
