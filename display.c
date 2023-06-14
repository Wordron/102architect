/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display informations about transformations
*/
#include <stdio.h>
#include "struct.h"

void display(struct flags_s *stock)
{
    int j = 0;

    for (int i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (stock->matrice_result[i][j] <= 0 && stock->matrice_result[i][j] >= -0.5)
                stock->matrice_result[i][j] = 0;
            printf("%.2f    ", stock->matrice_result[i][j]);
        }
        printf("%.2f", stock->matrice_result[i][j]);
        printf("\n");
    }
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", stock->dot[0], stock->dot[1], stock->dot_result[0], stock->dot_result[1]);
}
