#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Choisissez un niveau entre 1 et 30 : ");
    int niveau;
    scanf("%d", &niveau);
    while (niveau < 1 || niveau > 30) {
        printf("Choisissez un niveau entre 1 et 30 : ");
        scanf("%d", &niveau);
    }
    int tableau[1][4] = {{0, 1, 1, 1}}; //
    int tableaucouleur[1][4] = {{34, 0, 0, 0}}; // 34 bleu, 31 rouge, 32 vert, 33 jaune
    int x = 1; // nombre de lignes
    int y = 4; // nombre de colonnes
    int px = 0;
    int py = 0;
    int dpx = 0;
    int dpy = 0;
    int end = 0;

    while (end == 0)
    {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (tableaucouleur[i][j] != 0) {
                    printf("\033[0;%dm", tableaucouleur[i][j]);
                }
                if (tableau[i][j] == 0) {
                    printf(" X ");
                } else if (tableau[i][j] == -1) {
                    printf("   ");
                } else {
                    printf(" %d ", tableau[i][j]);
                }
                if (tableaucouleur[i][j] != 0) {
                    printf("\033[0m");
                }
            }
            printf("\n");
        }
        printf("Choisissez une direction (H, B, G, D) : ");
        char m;
        scanf(" %c", &m);
        switch (m)
        {
        case 'H':
            if (px > 0) {
                if (tableau[px - 1][py] >= tableau[px][py] && tableaucouleur[px - 1][py] == 0) {
                    dpx = px;
                    dpy = py;
                    px = px - 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                } else {
                    printf("Vous ne pouvez pas aller plus haut");
                }
            } else {
                printf("Vous ne pouvez pas aller plus haut");
            }
            break;
        case 'B':
            if (px < x - 1) {
                if (tableau[px + 1][py] >= tableau[px][py] && tableaucouleur[px + 1][py] == 0) {
                    dpx = px;
                    dpy = py;
                    px = px + 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                } else {
                    printf("Vous ne pouvez pas aller plus bas");
                }
            } else {
                printf("Vous ne pouvez pas aller plus bas");
            }
            break;
        case 'G':
            if (py > 0) {
                if (tableau[px][py - 1] >= tableau[px][py] && tableaucouleur[px][py - 1] == 0) {
                    dpx = px;
                    dpy = py;
                    py = py - 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                } else {
                    printf("Vous ne pouvez pas aller plus à gauche");
                }
            } else {
                printf("Vous ne pouvez pas aller plus à gauche");
            }
            break;
        case 'D':
            if (py < y - 1) {
                if (tableau[px][py + 1] >= tableau[px][py] && tableaucouleur[px][py + 1] == 0) {
                    dpx = px;
                    dpy = py;
                    py = py + 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                } else {
                    printf("Vous ne pouvez pas aller plus à droite");
                }
            } else {
                printf("Vous ne pouvez pas aller plus à droite");
            }
            break;
        default:
            break;
        }

        // parcours du tableau
        end = 1;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (tableau[i][j] > 0 && tableaucouleur[i][j] == 0) {
                    end = 0;
                }
            }
        }
    }
}