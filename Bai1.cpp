#include <stdio.h>
#include <conio.h>
#include <time.h>

void taoMangRandom(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}