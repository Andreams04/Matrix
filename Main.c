#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	printf("Создание нулевой матрицы 3*3\n\n");

	matrix_print(create_matrix(3, 3));

	printf("\n");

	printf("Создание матрицы 3*4 с указанным числом 4\n\n");

	matrix_print(matrix_num(3, 4, 4));

	printf("\n");

	printf("Создание матрицы 5*3 с числами от 5 до 23\n\n");

	matrix_print(matrix_rand(5, 3, 5, 23));

	printf("\n");

	printf("Создание матрицы 2*2 вручную (я выбрал числа 3 5 2 9)\n\n");

	int arr[] = { 3, 5, 2, 9 };

	matrix_print(build_matrix(2, 2, arr));

	printf("\n");

	printf("-----------------------------------------------------------");

	printf("\n");

	printf("Создадим две матрицы: \n\n");

	printf("Первая\n\n");

	matrix* a = matrix_rand(3, 3, -10, 10);

	matrix_print(a);

	printf("\n");

	printf("Вторая\n\n");

	matrix* b = matrix_rand(3, 3, -10, 10);

	matrix_print(b);

	printf("\n");

	printf("Сложение a + b\n\n");

	matrix_print(matrix_add(a, b));

	printf("\n");

	printf("Вычитание a - b\n\n");

	matrix_print(matrix_sub(a, b));

	printf("\n");

	printf("Умножение a * b\n\n");

	matrix_print(matrix_multi(a, b));

	printf("\n");

	printf("-----------------------------------------------------------");

	printf("\n");

	printf("Создадим новую матрицу\n\n");

	matrix* c = matrix_rand(3, 3, -10, 10);

	matrix_print(c);

	printf("\n");

	printf("Транспонируем матрицу\n\n");

	matrix_print(matrix_trans(c));

	printf("\n");

	printf("Скопируем получившуюся матрицу\n\n");

	matrix_print(matrix_copy(matrix_trans(c)));
}