#include<stdio.h>
int main()
{
	int n(0), m(0);
	printf("vvedite kol-vo strok\n");
	scanf_s("%d", &n);
	printf("vvedite kol-vo stolbzov\n");
	scanf_s("%d", &m);
	int** a = new int* [n];
	for (int i(0); i < n; i++)
	{
		*(a + i) = new int[m];
	}
	printf("vvedite elementi\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("massiv\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	int sum(0), max(0);
	for (int i(0); i < n; i++)
	{
		max = a[i][0];
		for (int j(1); j < m; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
		sum += max;
	}
	printf("summa max elementov kazhdoi stroki %d\n", sum);
	a[n - 1][m - 1] = sum;
	printf("massiv\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	int b(0), c(0);
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				b++;
			}
			else
			{
				c++;
			}
		}
	}
	int* ch = new int[b];
	int* nech = new int[c];
	b = 0;
	c = 0;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				ch[b] = a[i][j];
				b++;
			}
			else
			{
				nech[c] = a[i][j];
				c++;
			}
		}
	}
	printf("massiv ch\n");
	for (int i(0); i < b; i++)
	{
		printf("%d ", ch[i]);
	}
	printf("\n");
	printf("massiv nech\n");
	for (int i(0); i < c; i++)
	{
		printf("%d ", nech[i]);
	}
	for (int i(0); i < n; i++)
	{
		delete[]a[i];
	}
	return 0;
	
}