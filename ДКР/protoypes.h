#ifndef PROTOYPES_H_INCLUDED
#define PROTOYPES_H_INCLUDED

void sum_count ();
int matrix_size ();
int** matrix_make (int);
void matrix_autofill (int**, int);
void matrix_manualfill (int**, int);
void matrix_print (const int**, int);
void matrix_find_bigger_values_below_main_diagonal (int**, int, int*, int*, int*, int*);
void matrix_print_bigger_values (int**, int, int*, int*, int*, int*);
void matrix_clear (int**, int);
void top_eight_letters_in_file();

#endif // PROTOYPES_H_INCLUDED
