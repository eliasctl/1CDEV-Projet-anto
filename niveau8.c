

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tableau[3][2] = {{1,1},{1,0},{1,2}};
    int tableaucouleur[3][2] = {{0,0},{0,34},{0,0}}; // 34 = bleu ; 31 = rouge ; 32 = vert ; 33 = jaune
    int dx = 1;
    int dy = 1;
    int x = 3;
    int y = 2;
    int px = dx;
    int py = dy;
    int dpx = px;
    int dpy = py;
    int end = 0;

    while (end == 0)
    {
        printf("\n");
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (tableaucouleur[i][j] != 0)
                {
                    printf("\033[0;%dm", tableaucouleur[i][j]);
                }
                if (tableau[i][j] == 0)
                {
                    printf(" X ");
                }
                else if (tableau[i][j] == -1)
                {
                    printf("   ");
                }
                else
                {
                    printf(" %d ", tableau[i][j]);
                }
                if (tableaucouleur[i][j] != 0)
                {
                    printf("\033[0m");
                }
            }
            printf("\n\n");
        }
        printf("\nChoisissez une direction (H, B, G, D) : ");
        printf("\nEffacer le dernier coup (E) : ");
        printf("\nEffacer la chaine de couleur (C) : ");
        printf("\nRecommencer la partie (R) :");
        printf("\nChanger de couleur (O = bleu, L = rouge, P = vert, M = jaune) :");
        printf("\n");
        char m;
        scanf(" %c", &m);
        switch (m)
        {
        case 'H':
            if (px > 0)
            {
                if (tableau[px - 1][py] >= tableau[px][py] && tableaucouleur[px - 1][py] == 0)
                {
                    dpx = px;
                    dpy = py;
                    px = px - 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                }
                else
                {
                    printf("\nVous ne pouvez pas aller plus haut");
                }
            }
            else
            {
                printf("\nVous ne pouvez pas aller plus haut");
            }
            break;
        case 'B':
            if (px < x - 1)
            {
                if (tableau[px + 1][py] >= tableau[px][py] && tableaucouleur[px + 1][py] == 0)
                {
                    dpx = px;
                    dpy = py;
                    px = px + 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                }
                else
                {
                    printf("\nVous ne pouvez pas aller plus bas");
                }
            }
            else
            {
                printf("\nVous ne pouvez pas aller plus bas");
            }
            break;
        case 'G':
            if (py > 0)
            {
                if (tableau[px][py - 1] >= tableau[px][py] && tableaucouleur[px][py - 1] == 0)
                {
                    dpx = px;
                    dpy = py;
                    py = py - 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                }
                else
                {
                    printf("\nVous ne pouvez pas aller plus à gauche");
                }
            }
            else
            {
                printf("\nVous ne pouvez pas aller plus à gauche");
            }
            break;
        case 'D':
            if (py < y - 1)
            {
                if (tableau[px][py + 1] >= tableau[px][py] && tableaucouleur[px][py + 1] == 0)
                {
                    dpx = px;
                    dpy = py;
                    py = py + 1;
                    tableaucouleur[px][py] = tableaucouleur[dpx][dpy];
                }
                else
                {
                    printf("\nVous ne pouvez pas aller plus à droite");
                }
            }
            else
            {
                printf("\nVous ne pouvez pas aller plus à droite");
            }
            break;
        case 'E':
            if (tableau[px][py] != 0 && (px != dpx || py != dpy))
            {
                tableaucouleur[px][py] = 0;
                px = dpx;
                py = dpy;
            }
            else
            {
                printf("\nVous ne pouvez pas effacer le dernier coup");
            }
            break;
        case 'C':
            if (tableau[px][py] != 0)
            {
                for (int i = 0; i < x; i++)
                {
                    for (int j = 0; j < y; j++)
                    {
                        if (tableaucouleur[i][j] == tableaucouleur[px][py] && tableau[i][j] != 0)
                        {
                            tableaucouleur[i][j] = 0;
                        }
                    }
                }
            }
            else
            {
                printf("\nVous ne pouvez pas effacer la chaine de couleur");
            }
            break;
        case 'R':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (tableau[i][j] > 0)
                    {
                        tableaucouleur[i][j] = 0;
                    }
                }
            }
            px = dx;
            py = dy;
            dpx = px;
            dpy = py;
            break;
        case 'O':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (tableaucouleur[i][j] == 34)
                    {
                        px = i;
                        py = j;
                        dpx = px;
                        dpy = py;
                    }
                }
            }
            break;
        case 'L':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (tableaucouleur[i][j] == 31)
                    {
                        px = i;
                        py = j;
                        dpx = px;
                        dpy = py;
                    }
                }
            }
            break;
        case 'P':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (tableaucouleur[i][j] == 32)
                    {
                        px = i;
                        py = j;
                        dpx = px;
                        dpy = py;
                    }
                }
            }
            break;
        case 'M':
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (tableaucouleur[i][j] == 33)
                    {
                        px = i;
                        py = j;
                        dpx = px;
                        dpy = py;
                    }
                }
            }
            break;
        default:
            break;
        }
        end = 1;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (tableau[i][j] > 0 && tableaucouleur[i][j] == 0)
                {
                    end = 0;
                }
            }
        }
    }
    printf("\n");
    return 0;
}