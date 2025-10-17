#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_phi_n = -1;

int mdc(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int pollard_rho(int N) {
    int x = 2, y = 2, d = 1;
    while(d == 1) {
        x = (x*x + 1) % N;
        y = (y*y + 1) % N;
        y = (y*y + 1) % N;
        d = mdc(abs(x - y), N);
        if(d == N) return -1;
    }
    return d;
}

int euclides_estendido(int a, int b, int* x, int* y) {
    if(a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = euclides_estendido(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int mod_inverse(int e, int z) {
    int x, y;
    int g = euclides_estendido(e, z, &x, &y);
    if(g != 1) return -1;
    return (x % z + z) % z;
}

int is_prime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}

int totiente(int p, int q) {
    return (p-1)*(q-1);
}

void gera_chaves(int p, int q, int* n, int* z, int* e, int* d) {
    *n = p * q;
    *z = totiente(p, q);
    g_phi_n = *z;
    for(*e = 2; *e < *n; (*e)++)
        if(mdc(*e, *z) == 1) break;
    *d = mod_inverse(*e, *z);
}

int exponenciacao_modular(int base, int exp, int mod, int *teorema) {
    int result = 1;
    int reduced_exp = exp;

    if(is_prime(mod)) {
        *teorema = 1;
        if(base % mod != 0)
            reduced_exp = exp % (mod - 1);
    } else if(mdc(base, mod) == 1) {
        *teorema = 2;
        if(g_phi_n > 0)
            reduced_exp = exp % g_phi_n;
    } else {
        *teorema = 3;
    }

    base %= mod;
    while(reduced_exp > 0) {
        if(reduced_exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        reduced_exp /= 2;
    }
    return result;
}

int codifica_caractere(char c) {
    if(c == ' ') return 0;
    if(c >= 'A' && c <= 'Z') return 10 + (c - 'A' + 1);
    if(c >= 'a' && c <= 'z') return 10 + (c - 'a' + 1);
    return 99;
}

char decodifica_numero(int n) {
    if(n == 0) return ' ';
    if(n >= 11 && n <= 36) return 'A' + (n - 11);
    return '?';
}

void codifica_mensagem(const char* msg, int* codificada, int* tam) {
    int i;
    for(i = 0; msg[i] != '\0' && msg[i] != '\n'; i++)
        codificada[i] = codifica_caractere(msg[i]);
    *tam = i;
}

void decodifica_mensagem(const int* codificada, int tam, char* msg) {
    for(int i = 0; i < tam; i++)
        msg[i] = decodifica_numero(codificada[i]);
    msg[tam] = '\0';
}

int main() {
    int N1, N2, p, q;
    int n, z, e, d;
    char mensagem[256];
    int codificada[256], cifrada[256], decifrada[256];
    int tam, teorema;

    printf("Digite N1: ");
    scanf("%d", &N1);
    printf("Digite N2: ");
    scanf("%d", &N2);
    getchar();

    p = pollard_rho(N1);
    q = pollard_rho(N2);

    if(p <= 1 || q <= 1 || p == q) {
        printf("Erro nos fatores. Escolha outros N1 e N2.\n");
        return 1;
    }

    gera_chaves(p, q, &n, &z, &e, &d);
    printf("\nChave pública: (n=%d, e=%d)\n", n, e);
    printf("Chave privada: (n=%d, d=%d)\n", n, d);

    printf("\nMensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    size_t len = strlen(mensagem);
    if(len > 0 && mensagem[len-1] == '\n') mensagem[len-1] = '\0';

    codifica_mensagem(mensagem, codificada, &tam);

    for(int i = 0; i < tam; i++)
        cifrada[i] = exponenciacao_modular(codificada[i], e, n, &teorema);

    for(int i = 0; i < tam; i++)
        decifrada[i] = exponenciacao_modular(cifrada[i], d, n, &teorema);

    char mensagem_decifrada[256];
    decodifica_mensagem(decifrada, tam, mensagem_decifrada);

    printf("\nMensagem decifrada: %s\n", mensagem_decifrada);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_phi_n = -1;

int mdc(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int pollard_rho(int N) {
    int x = 2, y = 2, d = 1;
    while(d == 1) {
        x = (x*x + 1) % N;
        y = (y*y + 1) % N;
        y = (y*y + 1) % N;
        d = mdc(abs(x - y), N);
        if(d == N) return -1;
    }
    return d;
}

int euclides_estendido(int a, int b, int* x, int* y) {
    if(a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = euclides_estendido(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int mod_inverse(int e, int z) {
    int x, y;
    int g = euclides_estendido(e, z, &x, &y);
    if(g != 1) return -1;
    return (x % z + z) % z;
}

int is_prime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return 0;
    return 1;
}

int totiente(int p, int q) {
    return (p-1)*(q-1);
}

void gera_chaves(int p, int q, int* n, int* z, int* e, int* d) {
    *n = p * q;
    *z = totiente(p, q);
    g_phi_n = *z;
    for(*e = 2; *e < *n; (*e)++)
        if(mdc(*e, *z) == 1) break;
    *d = mod_inverse(*e, *z);
}

int exponenciacao_modular(int base, int exp, int mod, int *teorema) {
    int result = 1;
    int reduced_exp = exp;

    if(is_prime(mod)) {
        *teorema = 1;
        if(base % mod != 0)
            reduced_exp = exp % (mod - 1);
    } else if(mdc(base, mod) == 1) {
        *teorema = 2;
        if(g_phi_n > 0)
            reduced_exp = exp % g_phi_n;
    } else {
        *teorema = 3;
    }

    base %= mod;
    while(reduced_exp > 0) {
        if(reduced_exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        reduced_exp /= 2;
    }
    return result;
}

int codifica_caractere(char c) {
    if(c == ' ') return 0;
    if(c >= 'A' && c <= 'Z') return 10 + (c - 'A' + 1);
    if(c >= 'a' && c <= 'z') return 10 + (c - 'a' + 1);
    return 99;
}

char decodifica_numero(int n) {
    if(n == 0) return ' ';
    if(n >= 11 && n <= 36) return 'A' + (n - 11);
    return '?';
}

void codifica_mensagem(const char* msg, int* codificada, int* tam) {
    int i;
    for(i = 0; msg[i] != '\0' && msg[i] != '\n'; i++)
        codificada[i] = codifica_caractere(msg[i]);
    *tam = i;
}

void decodifica_mensagem(const int* codificada, int tam, char* msg) {
    for(int i = 0; i < tam; i++)
        msg[i] = decodifica_numero(codificada[i]);
    msg[tam] = '\0';
}

int main() {
    int N1, N2, p, q;
    int n, z, e, d;
    char mensagem[256];
    int codificada[256], cifrada[256], decifrada[256];
    int tam, teorema;

    printf("Digite N1: ");
    scanf("%d", &N1);
    printf("Digite N2: ");
    scanf("%d", &N2);
    getchar();

    p = pollard_rho(N1);
    q = pollard_rho(N2);

    if(p <= 1 || q <= 1 || p == q) {
        printf("Erro nos fatores. Escolha outros N1 e N2.\n");
        return 1;
    }

    gera_chaves(p, q, &n, &z, &e, &d);
    printf("\nChave pública: (n=%d, e=%d)\n", n, e);
    printf("Chave privada: (n=%d, d=%d)\n", n, d);

    printf("\nMensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    size_t len = strlen(mensagem);
    if(len > 0 && mensagem[len-1] == '\n') mensagem[len-1] = '\0';

    codifica_mensagem(mensagem, codificada, &tam);

    for(int i = 0; i < tam; i++)
        cifrada[i] = exponenciacao_modular(codificada[i], e, n, &teorema);

    for(int i = 0; i < tam; i++)
        decifrada[i] = exponenciacao_modular(cifrada[i], d, n, &teorema);

    char mensagem_decifrada[256];
    decodifica_mensagem(decifrada, tam, mensagem_decifrada);

    printf("\nMensagem decifrada: %s\n", mensagem_decifrada);
    return 0;
}
