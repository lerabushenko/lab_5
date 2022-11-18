#include<stdio.h>
#include<locale.h>
int main() {
	setlocale(0, "");
	int n(0), m(0), max(0), max1(0), max2(0);
	printf("введите количество строк\n");
	scanf_s("%d", &n);
	printf("введите количество столбцов\n");
	scanf_s("%d", &m);
	int **a = new int* [n];
	for (int i(0); i < n; i++)
	{
		*(a + i) = new int[m];
	}
	printf("введите массив\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("a[%d%d] = ", i + 1, j + 1);
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("массив\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++) 
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	int k(0), q(n);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
			if (a[i][j] == 0)
			{
				k++;
			}
		if (k != 0)
		{
			k = 0;
			q--;
		}
	}
	printf("%d строк не содержит нулевые элементы\n", q);
	int k1(0);
	for (int i(0); i<n; i++)
	{
		for (int j(0); j < m; j++)
		{
			max1 = a[i][j];
			a[i][j] = 0;
			for (int i1(0); i1 < n; i1++)
			{
				for (int j1(0); j1 < m; j1++)
				{
					if (max1==a[i1][j1])
					{
						max=a[i1][j1];
						k1++;
					}
				}
				if (max2 > max)
				{
					max = max2;
				}
			}
			max2 = max;
			a[i][j] = max1;
		}
	}
	if (k1 == 0)
		printf("нет повторяющегося максимума");
	else
		printf("Максимум, который повторяется %d", max);
	for (int i(0); i < m; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	return 0;
}