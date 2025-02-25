/*
** EPITECH PROJECT, 2025
** matrice.h
** File description:
** Header for the matrice
*/

#ifndef MATRICE_H
    #define MATRICE_H

//----------------------------------------------------------------//
/* TYPDEF */

/* matrice */
typedef struct matrice_s {
    float **matrice;
    int x;
    int y;
} matrice_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* init_matrice */
matrice_t *init_matrice(int x, int y); // Error: NULL
int free_matrice(matrice_t **matrice); // Error: KO

/* convertion_matrice */
matrice_t *str_to_square_matrice(char const *str); // Error: NULL
matrice_t *str_to_n_matrice(char const *str, int n); // Error: NULL

/* calcul_matrice */ // Error: NULL
matrice_t *multiplie_matrice(matrice_t *matrice_a, matrice_t *matrice_b);
matrice_t *transpose_matrice(matrice_t *matrice);
matrice_t *cofacteur_matrice(matrice_t *matrice);
float determinant_matrice_2(matrice_t *matrice); // Error: 0
float determinant_matrice(matrice_t *matrice); // Error: 0
matrice_t *inverse_matrice_2(matrice_t *matrice);
matrice_t *inverse_matrice(matrice_t *matrice);
matrice_t *reduce_matrice(matrice_t *matrice, int y_remove, int x_remove);

#endif /* MATRICE_H */
