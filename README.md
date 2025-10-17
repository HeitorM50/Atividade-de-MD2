# Atividade-de-MD2

4 atividades referentes ao Trabalho de ponto extra na P2 de Matemática Discreta 2

**Aluno:** Heitor Macêdo Ricardo  
**Matrícula:** 241039073

---

## 📋 Descrição dos Códigos

### Questão 1 - Criptografia RSA
**Arquivo:** [Códigos/Questao1.c](Códigos/Questao1.c)

Implementação completa do algoritmo RSA (Rivest-Shamir-Adleman) para criptografia de mensagens.

**Funcionalidades principais:**
- **Fatoração de números:** Utiliza o algoritmo de Pollard-Rho para fatorar N1 e N2 e encontrar os primos p e q
- **Geração de chaves:** Calcula a função totiente φ(n) = (p-1)(q-1) e gera as chaves pública (n, e) e privada (n, d)
- **Algoritmo de Euclides Estendido:** Implementado em [`euclides_estendido`](Códigos/Questao1.c) para calcular o inverso modular
- **Exponenciação modular otimizada:** A função [`exponenciacao_modular`](Códigos/Questao1.c) aplica:
  - **Pequeno Teorema de Fermat** quando o módulo é primo
  - **Teorema de Euler** quando mdc(base, módulo) = 1
- **Codificação de mensagens:** Converte caracteres em números (A-Z = 11-36, espaço = 0)
- **Cifragem e decifragem:** Usa as chaves RSA para cifrar e decifrar mensagens

**Entrada:**
- Dois números compostos N1 e N2
- Uma mensagem em texto

**Saída:**
- Chaves pública e privada
- Mensagem decifrada

---

### Questão 2 - MMC e MDC (Sincronização de Ciclos)
**Arquivo:** [Códigos/Questao2.c](Códigos/Questao2.c)

Calcula o Mínimo Múltiplo Comum (MMC) de múltiplos ciclos para determinar quando todos sincronizam.

**Funcionalidades principais:**
- **Função [`mdc`](Códigos/Questao2.c):** Calcula o Máximo Divisor Comum usando o Algoritmo de Euclides
- **Função [`mmc`](Códigos/Questao2.c):** Calcula o MMC usando a fórmula: MMC(a,b) = (a × b) / MDC(a,b)
- **Cálculo iterativo:** Calcula o MMC de N números de forma sequencial

**Entrada:**
- N: quantidade de ciclos
- N números representando os ciclos

**Saída:**
- O valor do MMC se for ≤ 50
- Mensagem de erro se o MMC > 50

**Exemplo:**
```
Entrada:
3
4 6 8

Saída:
24
```

---

### Questão 3 - Razão de Eficiência de um Número
**Arquivo:** [Códigos/Questao3.c](Códigos/Questao3.c)

Calcula a razão entre a função tau (τ - número de divisores) e sigma (σ - soma dos divisores) de um número.

**Funcionalidades principais:**
- **Fatoração em números primos:** Decompõe N em fatores primos p₁^a₁ × p₂^a₂ × ... × pₖ^aₖ
- **Cálculo de τ(n):** Número de divisores = ∏(aᵢ + 1)
- **Cálculo de σ(n):** Soma dos divisores = ∏[(pᵢ^(aᵢ+1) - 1) / (pᵢ - 1)]
- **Razão de eficiência:** τ(n) / σ(n)

**Entrada:**
- Um número N (1 ≤ N ≤ 100.000)

**Saída:**
- Razão de eficiência com 2 casas decimais

**Exemplo:**
```
Entrada:
12

Saída:
0.13
(τ(12) = 6, σ(12) = 28+6+4+3+2+1 = 28, razão = 6/28 ≈ 0.21)
```

---

### Questão 4 - Divisão Modular e Inverso Modular (Bônus)
**Arquivo:** [Códigos/Questao4.c](Códigos/Questao4.c)

Implementa operações de aritmética modular incluindo cálculo de inverso modular e divisão modular.

**Funcionalidades principais:**
- **[`mdcComPassos`](Códigos/Questao4.c):** Calcula o MDC mostrando cada passo do Algoritmo de Euclides
- **[`InversoModular`](Códigos/Questao4.c):** Implementa o Algoritmo de Euclides Estendido para encontrar o inverso modular de G em Zn
  - Retorna x tal que (G × x) ≡ 1 (mod Zn)
  - Só funciona quando mdc(G, Zn) = 1
- **[`powMod`](Códigos/Questao4.c):** Exponenciação modular usando exponenciação binária (método otimizado)
- **Divisão modular:** Calcula (H / G) mod Zn = (H × G⁻¹) mod Zn

**Entrada:**
- H: dividendo
- G: divisor
- Zn: módulo para divisão
- x: expoente
- n1: módulo para exponenciação

**Saída:**
- Passos do algoritmo de Euclides
- Inverso modular de G em Zn
- Resultado da divisão modular
- Resultado final: a^x mod n1

**Documentação adicional:** [Questao4docs/Questao4_parte2.md](Questao4docs/Questao4_parte2.md)

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema Windows (os executáveis já estão compilados para Windows)

### Compilação Manual

Para compilar qualquer um dos códigos:

```bash
gcc Códigos/Questao1.c -o Executáveis/Questao1.exe
gcc Códigos/Questao2.c -o Executáveis/Questao2.exe
gcc Códigos/Questao3.c -o Executáveis/Questao3.exe
gcc Códigos/Questao4.c -o Executáveis/Questao4.exe
```

### Executar os Programas

#### Questão 1 (RSA)
```bash
cd Executáveis
Questao1.exe
```
Quando solicitado, digite:
- N1 (número composto)
- N2 (número composto)
- Mensagem para criptografar

#### Questão 2 (MMC)
```bash
cd Executáveis
Questao2.exe
```
Digite:
- Quantidade de ciclos
- Os valores dos ciclos (separados por espaço ou enter)

#### Questão 3 (Razão de Eficiência)
```bash
cd Executáveis
Questao3.exe
```
Digite:
- Um número N entre 1 e 100.000

#### Questão 4 (Divisão Modular)
```bash
cd Executáveis
Questao4.exe
```
Digite sequencialmente:
- H (dividendo)
- G (divisor)
- Zn (módulo)
- x (expoente)
- n1 (módulo final)

---

## 📁 Estrutura do Projeto

```
Atividade-de-MD2/
├── README.md                          # Este arquivo
├── Códigos/
│   ├── Questao1.c                    # RSA
│   ├── Questao2.c                    # MMC/MDC
│   ├── Questao3.c                    # Razão de Eficiência
│   └── Questao4.c                    # Divisão Modular
├── Executáveis/
│   ├── Questao1.exe
│   ├── Questao2.exe
│   ├── Questao3.exe
│   └── Questao4.exe
└── Questao4docs/
    ├── Questão 4 - parte 2 V ou F.pdf
    └── Questao4_parte2.md            # Explicação teórica
```

---

## 📚 Conceitos Matemáticos Utilizados

- **Algoritmo de Euclides:** Cálculo do MDC
- **Algoritmo de Euclides Estendido:** Cálculo do inverso modular
- **Algoritmo de Pollard-Rho:** Fatoração de números compostos
- **Função Totiente de Euler (φ):** Quantidade de coprimos menores que n
- **Pequeno Teorema de Fermat:** a^(p-1) ≡ 1 (mod p) para p primo
- **Teorema de Euler:** a^φ(n) ≡ 1 (mod n) quando mdc(a,n) = 1
- **Exponenciação Binária:** Método otimizado para calcular a^b mod n
- **Aritmética Modular:** Operações em Zn

---

## 👨‍💻 Autor

**Heitor Macêdo Ricardo**  
Matrícula: 241039073  
Disciplina: Matemática Discreta 2