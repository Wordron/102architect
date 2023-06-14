/*
** EPITECH PROJECT, 2022
** struch.h
** File description:
** structure for flags
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct flags_s {
        int t;
        double t_x;
        double t_y;
        int t_place;

        int r;
        double r_angle;
        int r_place;

        int z;
        double z_x;
        double z_y;
        int z_place;

        int s;
        double s_angle;
        int s_place;
    
        double **matrice_id;
        double **matrice_result;
        double **matrice_witness;
        double *dot;
        double *dot_result;
    } flags_t;


#endif /* !STRUCT_H_ */
