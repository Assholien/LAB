#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

double x_in_a_power_of_y (const double, const double);
double funcx (const double);
double** create_array (const int);
void free_array (double**, const int);
void write_files (const double**, const int, FILE*, FILE*, const char[], const char[]);
void fill_array (double**, const int, double, const double);
void binary_print (FILE*);

#endif // PROTOTYPES_H_INCLUDED
