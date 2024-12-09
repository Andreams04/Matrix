#pragma once

typedef struct matrix
{
	int** data;
	int rows;
	int cols;

} matrix;

int* get_num_matrix(matrix* Matrix, int x, int y);
void full_matrix(matrix* Matrix, int num);
void matrix_print(matrix* Matrix);
void matrix_del(matrix* Matrix);
matrix* create_matrix(int rows, int cols);
matrix* matrix_num(int rows, int cols, int num);
matrix* matrix_rand(int rows, int cols, int min, int max);
matrix* matrix_add(matrix* Matrix_A, matrix* Matrix_B);
matrix* matrix_sub(matrix* Matrix_A, matrix* Matrix_B);
matrix* matrix_multi(matrix* Matrix_A, matrix* Matrix_B);
matrix* matrix_trans(matrix* Matrix_A);
matrix* matrix_copy(matrix* Matrix_A);
matrix* build_matrix(int rows, int cols, int mas[]);