// affiche un text en couleur

#include <stdio.h>
#include <stdlib.h>

int main() {
    int couleur = 34;
    printf("\033[0;%dm", couleur);
    printf("Choisissez un niveau entre 1 et 30 : ");
    printf("\033[0m");
}