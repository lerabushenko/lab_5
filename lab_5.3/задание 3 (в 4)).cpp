#include<stdio.h>
#include<locale.h>
int main() 
{
	setlocale(0, "");
	int n(0), m(0), kolvo(0);
	printf("введите количество строк\n");
	scanf_s("%d", &n);
	printf("введите количество столбцов\n");
	scanf_s("%d", &m);
	int** a = new int* [n];
	for (int i(0); i < n; i++)
	{
		*(a + i) = new int[m];
	}
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
	printf("массив\n");
	int k(0), q(0), c(0);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m - 1; j++)
		{
			if (a[i][j] > a[i][j + 1]) k++;
		}
		if (k == m-1 && q == 0)
		{
			q++;
			for (int d(0); d < m / 2; d++)
			{

				c = a[i][d]; 
				a[i][d] = a[i][m-1 - d]; 
				a[i][m-1 - d] = a[i][d];
				kolvo++;

			}
		}
	}
	if (kolvo != 0)
	{
		for (int i(0); i < n; i++)
		{
			for (int j(0); j < m; j++)
			{
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("нет строки все элементы которой упорядоченны по убыванию");
	}
	for (int i(0); i < m; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	return 0;
}
