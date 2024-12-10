#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int* get_num_matrix(matrix* Matrix, int x, int y)
{
	if (Matrix == NULL) 
	{
		exit(0);
	}

	return &((Matrix->data)[x][y]);
}

void full_matrix(matrix* Matrix, int num)
{
	if (Matrix == NULL)
	{
		exit(0);
	}

	for (int y = 0; y < Matrix->cols; y++)
	{
		for (int x = 0; x < Matrix->rows; x++)
		{
			*get_num_matrix(Matrix, x, y) = num;
		}
	}
}

 matrix* create_matrix(int rows, int cols)
{
	matrix* Matrix = (matrix*)malloc(sizeof(matrix));

	Matrix->rows = rows;
	Matrix->cols = cols;

	Matrix->data = (int**)malloc(rows*sizeof(int*));

	for (int x = 0; x < rows; x++) 
	{
		(Matrix->data)[x] = (int*)malloc(cols * sizeof(int));
	}

	full_matrix(Matrix, 0);

	return Matrix;
}

 matrix* matrix_num(int rows, int cols, int num)
 {
	 matrix* Matrix = create_matrix(rows, cols);

	 full_matrix(Matrix, num);

	 return Matrix;
 }

 matrix* matrix_rand(int rows, int cols, int min, int max)
 {
	 if (min > max)
	 {
		 exit(0);
	 }

	 matrix* Matrix = create_matrix(rows, cols);

	 for (int x = 0; x < Matrix->rows; x++) 
	 {
		 for (int y = 0; y < Matrix->cols; y++) 
		 {
			 *get_num_matrix(Matrix, x, y) = min + rand() % (max - min + 1);
		 }
	 }

	 return Matrix;
 }

void matrix_print(matrix* Matrix)
{
	if (Matrix == NULL)
	{
		exit(0);
	}

	for (int x = 0; x < Matrix->rows; x++)
	{
		for (int y = 0; y < Matrix->cols; y++) 
		{
			printf("%i ", *get_num_matrix(Matrix, x, y));
		}

		printf("\n");
	}
}

matrix* matrix_add(matrix* Matrix_A, matrix* Matrix_B)
{
	if ((Matrix_A == NULL) || (Matrix_B == NULL))
	{
		exit(0);
	}

	else if (Matrix_A->rows == Matrix_B->rows && Matrix_A->cols == Matrix_B->cols)
	{
		int rows = Matrix_A->rows;
		int cols = Matrix_A->cols;

		matrix* Matrix = create_matrix(rows, cols);

		for (int x = 0; x < Matrix->rows; x++)
		{
			for (int y = 0; y < Matrix->cols; y++)
			{
				*get_num_matrix(Matrix, x, y) = (Matrix_A->data)[x][y] + (Matrix_B->data)[x][y];
			}
		}

		return Matrix;
	}

	else
	{
		exit(0);
	}
}

matrix* matrix_sub(matrix* Matrix_A, matrix* Matrix_B)
{
	if ((Matrix_A == NULL) || (Matrix_B == NULL))
	{
		exit(0);
	}

	else if (Matrix_A->rows == Matrix_B->rows && Matrix_A->cols == Matrix_B->cols)
	{
		int rows = Matrix_A->rows;
		int cols = Matrix_A->cols;

		matrix* Matrix = create_matrix(rows, cols);

		for (int x = 0; x < Matrix->rows; x++)
		{
			for (int y = 0; y < Matrix->cols; y++)
			{
				*get_num_matrix(Matrix, x, y) = (Matrix_A->data)[x][y] - (Matrix_B->data)[x][y];
			}
		}

		return Matrix;
	}

	else
	{
		exit(0);
	}
}

matrix* matrix_multi(matrix* Matrix_A, matrix* Matrix_B)
{
	if ((Matrix_A == NULL) || (Matrix_B == NULL))
	{
		exit(0);
	}

	else if (Matrix_A->cols == Matrix_B->rows)
	{
		int rows = Matrix_A->rows;
		int cols = Matrix_B->cols;

		matrix* Matrix = create_matrix(rows, cols);

		for (int x = 0; x < Matrix->rows; x++)
		{
			for (int y = 0; y < Matrix->cols; y++)
			{
				int count = 0;

				for (int i = 0; i < Matrix_A->cols; i++) 
				{
					count += *get_num_matrix(Matrix_A, x, i) * *get_num_matrix(Matrix_B, i, y);
				}

				*get_num_matrix(Matrix, x, y) = count;
			}
		}

		return Matrix;
	}

	else
	{
		exit(0);
	}
}

matrix* matrix_trans(matrix* Matrix_A)
{
	if (Matrix_A == NULL)
	{
		exit(0);
	}

	int rows = Matrix_A->cols;
	int cols = Matrix_A->rows;

	matrix* Matrix = create_matrix(rows, cols);

	for (int x = 0; x < Matrix->rows; x++)
	{
		for (int y = 0; y < Matrix->cols; y++)
		{
			*get_num_matrix(Matrix, x, y) = (Matrix_A->data)[y][x];
		}
	}

	return Matrix;
}

matrix* matrix_copy(matrix* Matrix_A)
{
	if (Matrix_A == NULL)
	{
		exit(0);
	}

	int rows = Matrix_A->rows;
	int cols = Matrix_A->cols;

	matrix* Matrix = create_matrix(rows, cols);

	for (int x = 0; x < Matrix->rows; x++)
	{
		for (int y = 0; y < Matrix->cols; y++)
		{
			*get_num_matrix(Matrix, x, y) = (Matrix_A->data)[x][y];
		}
	}

	return Matrix;
}

void matrix_del(matrix* Matrix)
{
	if (Matrix == NULL)
	{
		exit(0);
	}

	for (int x = 0; x < Matrix->rows; x++)
	{
		free(Matrix->data[x]);
	}

	free(Matrix->data);
	free(Matrix);
}

matrix* build_matrix(int rows, int cols, int mas[]) 
{
	matrix* Matrix = create_matrix(rows, cols);

	int i = 0;

	for (int x = 0; x < Matrix->rows; x++)
	{
		for (int y = 0; y < Matrix->cols; y++)
		{
			*get_num_matrix(Matrix, x, y) = mas[i];

			i++;
		}
	}

	return Matrix;
}
