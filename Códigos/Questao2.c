/* 
  QUESTÃO 02 - MMC e MDC
  Aluno: Heitor Macêdo Ricardo
  Matrícula: 241039073
  Linguagem: C (compilador: gcc)
*/
#include <stdio.h>

// Função MDC (máximo divisor comum)
int mdc(int a, int b) {
    while (b != 0) {                         // Loop até b ser 0        
        int t = b;                           // Swap       
        b = a % b;              
        a = t;
    }
    return a;
}

// Função MMC (mínimo múltiplo comum)
int mmc(int a, int b) {
    return (a * b) / mdc(a, b);             // MMC(a, b) = (a*b)/MDC(a,b)
}

int main() {
    int N, i, ciclos[10];
    int resultado;

    printf("Digite o número de chaves: ");
    scanf("%d", &N);

    printf("Digite os ciclos das chaves: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &ciclos[i]);
    }

    // MMC acumulado
    resultado = ciclos[0];
    for (i = 1; i < N; i++) {
        resultado = mmc(resultado, ciclos[i]);  // Atualiza resultado com o MMC atual       
    }

    if (resultado > 50) {
        printf("Não é possível sincronizar todas as chaves dentro do limite de 50 anos.\n");
    } else {
        printf("%d\n", resultado);
    }

    return 0;
}
