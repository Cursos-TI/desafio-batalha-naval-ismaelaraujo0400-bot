#include <stdio.h>

int main() {

    /*
        ============================================================
                       BATALHA NAVAL – NÍVEL INTERMEDIÁRIO
        ============================================================
        - Tabuleiro 10x10.
        - 4 navios de tamanho 3:
            * 2 horizontais/verticais
            * 2 diagonais (↘ e ↗)
        - Representação:
            * Água → 0
            * Navio → 3
        ============================================================
    */

    // ---------------- TABULEIRO 10x10 ----------------
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------- NAVIOS ----------------
    int navio1[3] = {3,3,3}; // horizontal
    int navio2[3] = {3,3,3}; // vertical
    int navio3[3] = {3,3,3}; // diagonal ↘
    int navio4[3] = {3,3,3}; // diagonal ↗

    // ============================================================
    //                  COORDENADAS DOS NAVIOS
    // ============================================================

    // Navio horizontal (tamanho 3)
    int hLinha = 1;
    int hColuna = 2;

    // Navio vertical (tamanho 3)
    int vLinha = 5;
    int vColuna = 1;

    // Navio diagonal ↘ (linha++, coluna++)
    int d1Linha = 2;
    int d1Coluna = 5;

    // Navio diagonal ↗ (linha--, coluna++)
    int d2Linha = 7;
    int d2Coluna = 4;

    // ============================================================
    //                FUNÇÃO GENÉRICA DE VALIDAÇÃO
    // ============================================================

    // HORIZONTAL: verifica se cabe no tabuleiro
    if (hColuna + 2 >= 10) {
        printf("Erro: Navio horizontal fora do limite!\n");
        return 0;
    }

    // VERTICAL
    if (vLinha + 2 >= 10) {
        printf("Erro: Navio vertical fora do limite!\n");
        return 0;
    }

    // DIAGONAL ↘
    if (d1Linha + 2 >= 10 || d1Coluna + 2 >= 10) {
        printf("Erro: Navio diagonal ↘ fora do limite!\n");
        return 0;
    }

    // DIAGONAL ↗
    if (d2Linha - 2 < 0 || d2Coluna + 2 >= 10) {
        printf("Erro: Navio diagonal ↗ fora do limite!\n");
        return 0;
    }

    // ============================================================
    //             VERIFICA SOBREPOSIÇÃO EM TODAS AS POSIÇÕES
    // ============================================================

    // Função de teste rápida (macro simples)
    #define OCUPADO(l,c) (tabuleiro[l][c] == 3)

    // Testa navio 1 (horizontal)
    for (int i = 0; i < 3; i++) {
        if (OCUPADO(hLinha, hColuna + i)) {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 0;
        }
    }

    // Testa navio 2 (vertical)
    for (int i = 0; i < 3; i++) {
        if (OCUPADO(vLinha + i, vColuna)) {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 0;
        }
    }

    // Testa navio 3 (diagonal ↘)
    for (int i = 0; i < 3; i++) {
        if (OCUPADO(d1Linha + i, d1Coluna + i)) {
            printf("Erro: Sobreposição detectada no navio diagonal ↘!\n");
            return 0;
        }
    }

    // Testa navio 4 (diagonal ↗)
    for (int i = 0; i < 3; i++) {
        if (OCUPADO(d2Linha - i, d2Coluna + i)) {
            printf("Erro: Sobreposição detectada no navio diagonal ↗!\n");
            return 0;
        }
    }

    // ============================================================
    //                 POSICIONAMENTO DOS NAVIOS
    // ============================================================

    // Horizontal →
    for (int i = 0; i < 3; i++) {
        tabuleiro[hLinha][hColuna + i] = 3;
    }

    // Vertical ↓
    for (int i = 0; i < 3; i++) {
        tabuleiro[vLinha + i][vColuna] = 3;
    }

    // Diagonal ↘
    for (int i = 0; i < 3; i++) {
        tabuleiro[d1Linha + i][d1Coluna + i] = 3;
    }

    // Diagonal ↗
    for (int i = 0; i < 3; i++) {
        tabuleiro[d2Linha - i][d2Coluna + i] = 3;
    }

    // ============================================================
    //                    EXIBE TABULEIRO
    // ============================================================

    printf("\n=========== TABULEIRO BATALHA NAVAL ===========\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n================================================\n");

    return 0;
}
