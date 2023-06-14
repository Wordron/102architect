/*
** EPITECH PROJECT, 2022
** 102archi.c
** File description:
** 102architect project
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"

void display(struct flags_s *stock);

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] <= 'z' && str[i] >= 'a') ||
            (str[i] <= 'Z' && str[i] >= 'A'))
            i++;
        else
            return (0);
    }
    return (1);
}

int my_str_isfloat(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '.')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
    return (0);
}

void init_struct(struct flags_s *stock)
{
    stock->t = 0;
    stock->t_x = 0;
    stock->t_y = 0;

    stock->r = 0;
    stock->r_angle = 0;

    stock->z = 0;
    stock->z_x = 0;
    stock->z_y = 0;

    stock->s = 0;
    stock->s_angle = 0;
    stock->matrice_id[0][0] = 1;
    stock->matrice_id[0][1] = 0;
    stock->matrice_id[0][2] = 0;

    stock->matrice_id[1][0] = 0;
    stock->matrice_id[1][1] = 1;
    stock->matrice_id[1][2] = 0;
    stock->matrice_id[2][0] = 0;
    stock->matrice_id[2][1] = 0;
    stock->matrice_id[2][2] = 1;

    stock->matrice_result[0][0] = 1;
    stock->matrice_result[0][1] = 0;
    stock->matrice_result[0][2] = 0;
    stock->matrice_result[1][0] = 0;
    stock->matrice_result[1][1] = 1;
    stock->matrice_result[1][2] = 0;
    stock->matrice_result[2][0] = 0;
    stock->matrice_result[2][1] = 0;
    stock->matrice_result[2][2] = 1;


    stock->matrice_witness[0][0] = 1;
    stock->matrice_witness[0][1] = 0;
    stock->matrice_witness[0][2] = 0;
    stock->matrice_witness[1][0] = 0;
    stock->matrice_witness[1][1] = 1;
    stock->matrice_witness[1][2] = 0;
    stock->matrice_witness[2][0] = 0;
    stock->matrice_witness[2][1] = 0;
    stock->matrice_witness[2][2] = 1;

    stock->dot[0] = 0;
    stock->dot[1] = 0;
    stock->dot[2] = 1;

    stock->dot_result[0] = 0;
    stock->dot_result[1] = 0;
    stock->dot_result[2] = 0;

    //stock->dot = {0, 0, 1};
}

void reset_matrix_id(double **matrice_id)
{
    matrice_id[0][0] = 1;
    matrice_id[0][1] = 0;
    matrice_id[0][2] = 0;
    matrice_id[1][0] = 0;
    matrice_id[1][1] = 1;
    matrice_id[1][2] = 0;
    matrice_id[2][0] = 0;
    matrice_id[2][1] = 0;
    matrice_id[2][2] = 1;
}

void update_matrix_witness(double **matrice_witness, double **matrice_result)
{
    matrice_witness[0][0] = matrice_result[0][0];
    matrice_witness[0][1] = matrice_result[0][1];
    matrice_witness[0][2] = matrice_result[0][2];
    matrice_witness[1][0] = matrice_result[1][0];
    matrice_witness[1][1] = matrice_result[1][1];
    matrice_witness[1][2] = matrice_result[1][2];
    matrice_witness[2][0] = matrice_result[2][0];
    matrice_witness[2][1] = matrice_result[2][1];
    matrice_witness[2][2] = matrice_result[2][2];
}

int check_nb_arg(int ac, char **av)
{
    int p = 3;

    while (p < ac) {
        if (p < ac && (av[p][1] == 't' && av[p][0] == '-')) {
            if (p + 2 >= ac)
                return (84);
            if (my_str_isfloat(av[p + 1]) == 0 | my_str_isfloat(av[p + 2]) == 0)
                return (84);
            if (p + 4 == ac)
                return (84);
            p += 3;
        }
        if (p < ac && (av[p][1] == 'z' && av[p][0] == '-')) {
            if (p + 2 >= ac)
                return (84);
            if (my_str_isfloat(av[p + 1]) == 0 | my_str_isfloat(av[p + 2]) == 0)
                return (84);
            if (p + 4 == ac)
                return (84);
            p += 3;
        }
        if (p < ac && (av[p][1] == 'r' && av[p][0] == '-')) {
            if (p + 1 >= ac)
                return (84);
            if (my_str_isfloat(av[p + 1]) == 0)
                return (84);
            if (p + 3 == ac)
                return (84);
            p += 2;
        }
        if (p < ac && (av[p][1] == 's' && av[p][0] == '-')) {
            if (p + 1 >= ac)
                return (84);
            if (my_str_isfloat(av[p + 1]) == 0)
                return (84);
            if (p + 3 == ac)
                return (84);
            p += 2;
        }
        if (p < ac && (av[p][0] != '-' || av[p][1] != 't' && av[p][1] != 'z' && av[p][1] != 'r' && av[p][1] != 's'))
            return (84);
    }
}

int main(int ac, char **av)
{
    struct flags_s *stock = malloc(sizeof(struct flags_s));
    int place = 1;
    int p = 3;

    if (check_nb_arg(ac, av) == 84)
        return (84);
    stock->matrice_id = malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++)
        stock->matrice_id[i] = malloc(sizeof(double) * 3);
    stock->matrice_result = malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++)
        stock->matrice_result[i] = malloc(sizeof(double) * 3);
    stock->matrice_witness = malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++)
        stock->matrice_witness[i] = malloc(sizeof(double) * 3);
    stock->dot = malloc(sizeof(double) * 3);
    stock->dot_result = malloc(sizeof(double) * 3);
    init_struct(stock);

    if (ac < 4)
        return (84);
    if (my_str_isfloat(av[1]) == 0 || my_str_isfloat(av[2]) == 0)
        return (84);

    stock->dot[0] = atof(av[1]);
    stock->dot[1] = atof(av[2]);

    if (av[3][0] != '-' || av[3][1] != 't' && av[3][1] != 'z' && av[3][1] != 'r' && av[3][1] != 's')
        return (84);

    if (p < ac && (av[3][1] == 't' && av[3][0] == '-')) {
        reset_matrix_id(stock->matrice_id);
        stock->t = 1;
        stock->t_x = atof(av[3 + 1]);
        stock->t_y = atof(av[3 + 2]);

        stock->matrice_result[0][2] = stock->t_x;
        stock->matrice_result[1][2] = stock->t_y;
        update_matrix_witness(stock->matrice_witness, stock->matrice_result);
        p += 3;
        printf("Translation along vector (%.0f, %.0f)\n", stock->t_x, stock->t_y);
    }
    if (3 < ac && (av[3][1] == 'z' && av[3][0] == '-')) {
        reset_matrix_id(stock->matrice_id);
        stock->z = 1;
        stock->z_x = atof(av[3 + 1]);
        stock->z_y = atof(av[3 + 2]);

        stock->matrice_result[0][0] = stock->z_x;
        stock->matrice_result[1][1] = stock->z_y;
        update_matrix_witness(stock->matrice_witness, stock->matrice_result);
        p += 3;
        printf("Scaling by factors %.0f and %.0f\n", stock->z_x, stock->z_y);
    }
    if (3 < ac && (av[3][1] == 'r' && av[3][0] == '-')) {
        reset_matrix_id(stock->matrice_id);
        stock->r = 1;
        stock->r_angle = atof(av[3 + 1]);

        stock->matrice_result[0][0] = (cos(stock->r_angle * 3.1415926535 / 180));
        stock->matrice_result[0][1] = (sin(stock->r_angle * 3.1415926535 / 180)) * (-1);
        stock->matrice_result[1][0] = (sin(stock->r_angle * 3.1415926535 / 180));
        stock->matrice_result[1][1] = (cos(stock->r_angle * 3.1415926535 / 180));
        update_matrix_witness(stock->matrice_witness, stock->matrice_result);
        p += 2;
        printf("Rotation by a %.0f degree angle\n", stock->r_angle);
    }
    if (3 < ac && (av[3][1] == 's' && av[3][0] == '-')) {
        reset_matrix_id(stock->matrice_id);
        stock->s = 1;
        stock->s_angle = atof(av[3 + 1]);

        stock->matrice_result[0][0] = (cos(2 * stock->s_angle * 3.1415926535 / 180));
        stock->matrice_result[0][1] = (sin(2 * stock->s_angle * 3.1415926535 / 180));
        stock->matrice_result[1][0] = (sin(2 * stock->s_angle * 3.1415926535 / 180));
        stock->matrice_result[1][1] = (cos(2 * stock->s_angle * 3.1415926535 / 180)) * (-1);
        update_matrix_witness(stock->matrice_witness, stock->matrice_result);
        p += 2;
        printf("Reflection over an axis with an inclination angle of %.0f degrees\n", stock->s_angle);
    }

    while (p < ac) {
        if (p < ac && (av[p][1] == 't' && av[p][0] == '-')) {
            reset_matrix_id(stock->matrice_id);
            stock->t = 1;
            stock->t_x = atof(av[p + 1]);
            stock->t_y = atof(av[p + 2]);

            stock->matrice_id[0][2] = stock->t_x;
            stock->matrice_id[1][2] = stock->t_y;
            update_matrix_witness(stock->matrice_witness, stock->matrice_result);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    stock->matrice_result[j][k] = 0;
                    for (int l = 0; l < 3; l++)
                        stock->matrice_result[j][k] += stock->matrice_id[j][l] * stock->matrice_witness[l][k];
                }
            }
            p += 3;
            printf("Translation along vector (%.0f, %.0f)\n", stock->t_x, stock->t_y);
        }
        if (p < ac && (av[p][1] == 'z' && av[p][0] == '-')) {
            reset_matrix_id(stock->matrice_id);
            stock->z = 1;
            stock->z_x = atof(av[p + 1]);
            stock->z_y = atof(av[p + 2]);

            stock->matrice_id[0][0] = stock->z_x;
            stock->matrice_id[1][1] = stock->z_y;
            update_matrix_witness(stock->matrice_witness, stock->matrice_result);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    stock->matrice_result[j][k] = 0;
                    for (int l = 0; l < 3; l++)
                        stock->matrice_result[j][k] += stock->matrice_id[j][l] * stock->matrice_witness[l][k];
                }
            }
            p += 3;
            printf("Scaling by factors %.0f and %.0f\n", stock->z_x, stock->z_y);
        }
        if (p < ac && (av[p][1] == 'r' && av[p][0] == '-')) {
            reset_matrix_id(stock->matrice_id);
            stock->r = 1;
            stock->r_angle = atof(av[p + 1]);

            stock->matrice_id[0][0] = (cos(stock->r_angle * 3.1415926535 / 180));
            stock->matrice_id[0][1] = (sin(stock->r_angle * 3.1415926535 / 180)) * (-1);
            stock->matrice_id[1][0] = (sin(stock->r_angle * 3.1415926535 / 180));
            stock->matrice_id[1][1] = (cos(stock->r_angle * 3.1415926535 / 180));
            update_matrix_witness(stock->matrice_witness, stock->matrice_result);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    stock->matrice_result[j][k] = 0;
                    for (int l = 0; l < 3; l++)
                        stock->matrice_result[j][k] += stock->matrice_id[j][l] * stock->matrice_witness[l][k];
                }
            }
            p += 2;
            printf("Rotation by a %.0f degree angle\n", stock->r_angle);
        }
        if (p < ac && (av[p][1] == 's' && av[p][0] == '-')) {
            reset_matrix_id(stock->matrice_id);
            stock->s = 1;
            stock->s_angle = atof(av[p + 1]);

            stock->matrice_id[0][0] = (cos(2 * stock->s_angle * 3.1415926535 / 180));
            stock->matrice_id[0][1] = (sin(2 * stock->s_angle * 3.1415926535 / 180));
            stock->matrice_id[1][0] = (sin(2 * stock->s_angle * 3.1415926535 / 180));
            stock->matrice_id[1][1] = (cos(2 * stock->s_angle * 3.1415926535 / 180)) * (-1);
            update_matrix_witness(stock->matrice_witness, stock->matrice_result);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    stock->matrice_result[j][k] = 0;
                    for (int l = 0; l < 3; l++)
                        stock->matrice_result[j][k] += stock->matrice_id[j][l] * stock->matrice_witness[l][k];
                }
            }
            p += 2;
            printf("Reflection over an axis with an inclination angle of %.0f degrees\n", stock->s_angle);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            stock->dot_result[i] += stock->matrice_result[i][j] * stock->dot[j];
    }

    display(stock);
    free(stock->dot);
    free(stock->dot_result);
    for (int i = 0; i < 3; i++)
        free(stock->matrice_witness[i]);
    free(stock->matrice_witness);
    for (int i = 0; i < 3; i++)
        free(stock->matrice_id[i]);
    free(stock->matrice_id);
    for (int i = 0; i < 3; i++)
        free(stock->matrice_result[i]);
    free(stock->matrice_result);
    free(stock);
    return (0);
}
