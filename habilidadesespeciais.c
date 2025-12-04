#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Valor que representa navio
#define HABILIDADE 5  // Valor que representa área afetada por habilidade

// --------------------------------------------
// Função para exibir o tabuleiro
// --------------------------------------------
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\n===== TABULEIRO =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// --------------------------------------------
// Função para aplicar uma matriz de habilidade
// Ao tabuleiro, centrada na origem (linha,coluna)
// --------------------------------------------
void aplicarHabilidade(int tab[TAM][TAM], int habilidade[7][7], int linhaOrigem, int colunaOrigem) {
    int tamHab = 7;
    int centro = tamHab / 2;  // Centro da matriz da habilidade (posição 3)

    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {

            // Se a habilidade afeta esta posição
            if (habilidade[i][j] == 1) {

                // Converte posição da matriz para posição do tabuleiro
                int linhaTab = linhaOrigem + (i - centro);
                int colunaTab = colunaOrigem + (j - centro);

                // Validação: garantir que está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    // Marca o efeito da habilidade sem sobrescrever navios
                    if (tab[linhaTab][colunaTab] == 0) {
                        tab[linhaTab][colunaTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {

    // --------------------------------------------
    // 1) Criar tabuleiro 10x10
    // --------------------------------------------
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // --------------------------------------------
    // 2) Posicionar navios (tamanho 3)
    // Dois navios normais (horizontal/vertical)
    // Dois navios diagonais
    // --------------------------------------------

    // Navio horizontal
    int linhaH = 2, colH = 1;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaH][colH + i] = NAVIO;

    // Navio vertical
    int linhaV = 5, colV = 4;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaV + i][colV] = NAVIO;

    // Navio diagonal principal (↘)
    int linhaD1 = 1, colD1 = 7;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaD1 + i][colD1 + i] = NAVIO;

    // Navio diagonal secundária (↙)
    int linhaD2 = 6, colD2 = 2;
    for (int i = 0; i < 3; i++)
        tabuleiro[linhaD2 + i][colD2 - i] = NAVIO;

    // --------------------------------------------
    // 3) Criar matrizes de habilidades (7x7)
    // Todas com 0 inicial
    // --------------------------------------------
    int cone[7][7] = {0};
    int cruz[7][7] = {0};
    int octaedro[7][7] = {0};

    // --------------------------------------------
    // MATRIZ – CONE (ponta para cima, abre para baixo)
    // --------------------------------------------
    for (int i = 0; i < 7; i++) {
        for (int j = 3 - i; j <= 3 + i; j++) {
            if (j >= 0 && j < 7)
                cone[i][j] = 1;
        }
    }

    // --------------------------------------------
    // MATRIZ – CRUZ (linhas e colunas cruzadas)
    // --------------------------------------------
    for (int i = 0; i < 7; i++) {
        cruz[3][i] = 1; // Linha central
        cruz[i][3] = 1; // Coluna central
    }

    // --------------------------------------------
    // MATRIZ – OCTAEDRO (formato de losango)
    // --------------------------------------------
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (abs(i - 3) + abs(j - 3) <= 3)
                octaedro[i][j] = 1;
        }
    }

    // --------------------------------------------
    // 4) Aplicar habilidades ao tabuleiro
    // --------------------------------------------

    // Origem do cone
    aplicarHabilidade(tabuleiro, cone, 1, 1);

    // Origem da cruz
    aplicarHabilidade(tabuleiro, cruz, 5, 8);

    // Origem do octaedro
    aplicarHabilidade(tabuleiro, octaedro, 7, 3);

    // --------------------------------------------
    // 5) Exibir tabuleiro final com tudo aplicado
    // --------------------------------------------
    exibirTabuleiro(tabuleiro);

    return 0;
}
