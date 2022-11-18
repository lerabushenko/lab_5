#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	srand(time(0));
	int n(0), sumd1(0), sumst(0), sumd(0), kolvo(0);
	printf("vvedite razmer matrizi\n");
	scanf_s("%d", &n);
	int** a = new int* [n];
	for (int i(0); i < n; i++)
	{
		*(a + i) = new int[n];
	}
	printf("massiv\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			a[i][j] = -30 + rand() % 100;
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	int k(0);
	for (int j(0); j < n; j++)
	{
		for (int i(0); i < n; i++)
		{
			if (a[i][j] > 0)
			{
				sumst += a[i][j];
				k++;
			}
			else
			{
				sumst = 0;
				break;
			}
		}
		if (k == n)
		{
			printf("summa stolbza %d ravna %d\n", j+1, sumst);
			kolvo++;
		}
		sumst = 0;
		k = 0;
	}
	if (kolvo == 0)
	{
		printf("net stolbzov s poloz elementami\n");
	}
	sumd = abs(a[0][0]);
	for (int i(1); i < n; i++)
	{
		sumd1 = 0;
		for (int j(0); j <= i; j++)
		{
			sumd1 += abs(a[j][i - j]);
		}
		if (sumd > sumd1)
		{
			sumd = sumd1;
		}
	}
	for (int i(1); i < n; i++)
	{
		sumd1 = 0;
		for (int j(0); j < n - i; j++)
		{
			sumd1 += abs(a[i + j][n - j - 1]);
		}
		if (sumd > sumd1)
		{
			sumd = sumd1;
		}
	}
	printf("minimalnaya summa pobochnoy diagonaly %d", sumd);
	for (int i(0); i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
	return 0;
}