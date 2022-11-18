#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
int main() {
	setlocale(0, "");
	int max(0), min(0), s(0), b(0), n(0), m(0), j1(0), j2(0);
	srand(time(0));
	printf("введите количество строк\n");
	scanf_s("%d", &n);
	printf("введите количество столбцов\n");
	scanf_s("%d", &m);
	int** a = new int* [n];
	printf("массив\n");
	for (int i(0); i < n; i++) {
		*(a + i) = new int[m];
		for (int j(0); j < m; j++) {
			a[i][j] = -50 + rand() % 101;
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	s = 0;
	for (int i(0); i < n; i++)
		for (int j(0); j < m; j++)
			if (i == j) s += a[i][j];
	printf("сумма элементов главной диагонали: %d\n", s);
	printf("новый массив:\n");
	for (int i(0); i < n; i++)
	{
		j1 = 0;
		j2 = 0;
		max = a[i][0]; 
		min = a[i][0];
		for (int j(0); j < m; j++)
		{
			if (a[i][j] > max)
			{ 
				max = a[i][j]; j1 = j;
			};
			if (a[i][j] < min)
			{
				min = a[i][j]; j2 = j;
			
			}
		}
		b = min;
		a[i][j2] = max; 
		a[i][j1] = b;
		for (int j(0); j < m; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	for (int i(0); i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	return 0;
}
