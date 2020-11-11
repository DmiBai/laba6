//
//
//2. Даны натуральное число n, действительное число x, действительная матрица размера n*2n. 
//Получить последовательность b1,…,bn из нулей и единиц, 
//где bi=1, если элементы i-ой строки матрицы не превосходят x, и bi=0 в противном случае.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void error() {
	printf("\tError. Try again.\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int** N;

	int i, j, n, x, d;
	//Ввод n.
	printf("Введите n. ");
	do {
		scanf_s("%d", &n);
		if (n <= 0) {
			error();
		}
	} while (n <= 0);
	printf("\n");

	N = (int**)malloc(n * sizeof(int*));//Выделение памяти под указатели на строки массива.

	//Объявление строк.
	for (i = 0; i < n; i++) {
		N[i] = (int*)malloc(2 * n, sizeof(int));
	}

	//Объявление и заполнение столбцов.
	for (i = 0; i < n; i++) {
		for (j = 0; j < (2 * n); j++) {
			N[i][j] = rand() % 200 - 100;
		}
	}

	//Вывод матрицы.
	for (i = 0; i < n; i++) {
		for (j = 0; j < (2 * n); j++) {
			printf("%d\t", N[i][j]);
		}
		printf("\n");
	}

	//Ввод x.
	printf("Введите х. ");
	do {
		scanf_s("%d", &x);
		if (x <= 0) {
			error();
		}
	} while (x <= 0);
	printf("\n");

	int *arr = (int*)malloc(n * sizeof(int));

	//Цикл проверки и выполнения главного условия задачи.
	for (i = 0; i < n; i++) {

		while ((j < (2 * n)) & (d = 0)) {
			if (N[i][j] > x) {
				d = +1;
			}
		}

		if (d = 0) {
			arr[i] = 1;
			d = 0;
		}
		else {
			arr[i] = 0;
			d = 0;
		}

	}

	//Цикл вывода результата.
	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}

}
