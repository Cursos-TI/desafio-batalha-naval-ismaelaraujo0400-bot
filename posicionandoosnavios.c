#include <stdio.h>

int main() {

    /*
        ============================================================
                     BATALHA NAVAL – DESAFIO NOVATO
        ============================================================
        Representação:
            - Tabuleiro 10x10 → matriz
            - Água → 0
            - Navios (tamanho 3) → 3
        ============================================================
    */

    // ---------------- TABULEIRO 10x10 ----------------
    int tabuleiro[10][10];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------- NAVIOS (tamanho 3) ----------------
    int navioHorizontal[3] = {3, 3, 3}; // Representação do navio horizontal
    int navioVertical[3]   = {3, 3, 3}; // Representação do navio vertical

    // ---------------- COORDENADAS INICIAIS ----------------
    int linH = 2;   // linha do navio horizontal
    int colH = 4;   // coluna inicial do navio horizontal

    int linV = 5;   // linha inicial do navio vertical
    int colV = 7;   // coluna do navio vertical

    // ---------------- VALIDAÇÃO DOS NAVIOS ----------------
    // Navio horizontal precisa caber da coluna colH até colH+2
    if (colH + 2 >= 10) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 0;
    }

    // Navio vertical precisa caber da linha linV até linV+2
    if (linV + 2 >= 10) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 0;
    }

    // ---------------- VERIFICAR SOBREPOSIÇÃO ----------------
    for (int i = 0; i < 3; i++) {

        // Se alguma posição onde o navio horizontal será colocado já é 3
        if (tabuleiro[linH][colH + i] == 3) {
            printf("Erro: Navios se sobrepõem!\n");
            return 0;
        }

        // Se alguma posição onde o navio vertical será colocado já é 3
