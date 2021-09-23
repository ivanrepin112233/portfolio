#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <stdlib.h>;
#include <time.h>;

void shell(int* items, int count);
void qs(int* items, int left, int right);

void shell(int* items, int count)
{
	printf("\nArray before sort:\n");
	for (int k = 0; k < count; k++) {
		printf("%i ", items[k]);
	}
	clock_t start, end; // объявляем переменные для определения времени выполнения
	start = clock();
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
	end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nArray after sort:\n");
	for (int k = 0; k < count; k++) {
		printf("%i ", items[k]);
	}
	printf("\nShell complited in %f seconds", time_spent);
}
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	clock_t start, end; // объявляем переменные для определения времени выполнения
	start = clock();
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int main(void) {
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // объявляем переменные для определения времени выполнения
	start = clock();
	int i = 0, j = 0, r;
	int a[400][400], b[400][400], c[400][400], elem_c, randarray[10], highterarray[10], lowerarray[10], combarray[10], sortarray[10];
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 400)
	{
		while (j < 400)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 400)
	{
		while (j < 400)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	for (i = 0; i < 400; i++)
	{
		for (j = 0; j < 400; j++)
		{
			elem_c = 0;
			for (r = 0; r < 400; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Complited in %f seconds", time_spent);
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	//random array
	for (i = 0; i < 10; i++)
	{
		randarray[i] = rand() % 10 + 1;
	}
	//возрастающий массив
	for (i = 0; i < 10; i++)
	{
		highterarray[i] = i;
	}
	//убывающий массив
	for (i = 0; i < 10; i++)
	{
		lowerarray[i] = 10 - i;
	}
	//комбинированный массив
	for (i = 0; i < 10; i++)
	{
		if (i < 5) {
			combarray[i] = i;
		}
		else {
			combarray[i] = 10 - i;
		}
	}
	printf("\n\nRandom array:");
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = randarray[i];
	}
	shell(sortarray, 10);
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = randarray[i];
	}
	printf("\nArray before sort:\n");
	for (int k = 0; k < 10; k++) {
		printf("%i ", sortarray[k]);
	}
	start = clock();
	qs(sortarray, 0, 9);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nArray after sort:\n");
	for (int k = 0; k < 10; k++) {
		printf("%i ", sortarray[k]);
	}
	printf("\nQsort complited in %f seconds", time_spent);
	printf("\n\nhighterarray:");
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = highterarray[i];
	}
	shell(sortarray, 10);
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = highterarray[i];
	}
	start = clock();
	qs(sortarray, 0, 9);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nArray after sort:\n");
	for (int k = 0; k < 10; k++) {
		printf("%i ", sortarray[k]);
	}
	printf("\nQsort complited in %f seconds", time_spent);
	printf("\n\nlowerarray:");
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = lowerarray[i];
	}
	shell(sortarray, 10);
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = lowerarray[i];
	}
	start = clock();
	qs(sortarray, 0, 9);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nArray after sort:\n");
	for (int k = 0; k < 10; k++) {
		printf("%i ", sortarray[k]);
	}
	printf("\nQsort complited in %f seconds", time_spent);
	printf("\n\ncombarray:");
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = combarray[i];
	}
	shell(sortarray, 10);
	for (i = 0; i < 10; i++)
	{
		sortarray[i] = combarray[i];
	}
	start = clock();
	qs(sortarray, 0, 9);
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nArray after sort:\n");
	for (int k = 0; k < 10; k++) {
		printf("%i ", sortarray[k]);
	}
	printf("\nQsort complited in %f seconds", time_spent);
	return(0);
}