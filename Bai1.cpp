#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define Min 15

void TaoMangRandom(int a[], int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		a[i] = min + rand() % (max - min + 1);
	}
}
void TaoMangChan(int a[], int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		int random = min + (rand() % ((max - min + 1) / 2)) * 2;
		a[i] = random;
	}
}
int LinearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}
void SapXepTangInterChange(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void SapXepGiamInterChange(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int BinarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
void SapXepTangSelection(int a[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}
void HoanVi(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int a[], int low, int high) {
	int p = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (a[j] <= p) {
			i++;
			HoanVi(&a[i], &a[j]);
		}
	}
	HoanVi(&a[i + 1], &a[high]);
	return (i + 1);
}

void QuickSort(int a[], int l, int h) {
	if (l < h) {
		int pi = Partition(a, l, h);

		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, h);
	}
}
void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	srand(time(0));
	int n;
	printf("nhap so phan tu n (>= 15): ");
	scanf("%d", &n);

	if (n < Min) {
		printf("so luong phan tu phai it nhat la 15 %d.\n", Min);
		return 1;
	}

	int *a = (int*)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Khong du bo nho.\n");
		return 1;
	}
	free(a);
	int chon;
	do{

		printf("\nMenu:\n");
		printf("1. xuat mang random\n");
		printf("2. xuat mang random toan chan\n");
		printf("3. Tim gia tri x tren mang\n");
		printf("4. Sap xep mang tang dan theo interchange sort\n");
		printf("5. Sap xep mang giam dan theo interchange sort\n");
		printf("6. Tra ve vi tri cua x trong a dua tren binary search\n");
		printf("7. Sap xep a tang dan theo selection sort\n");
		printf("8. Sap xep theo quick sort\n");
		printf("hay nhap lua chon: ");
		scanf("%d", &chon);

		switch (chon) {
		case 1:
			TaoMangRandom(a, n, 0, 100);
			printf("phan tu mang la: ");
			xuatMang(a, n);
			break;
		case 2:
			TaoMangChan(a, n, 0, 100);
			printf("Phan tu mang la: ");
			xuatMang(a, n);
			break;
		case 3:
		{
			int x;
			printf("Nhap gia tri x can tim: ");
			scanf("%d", &x);
			int result = LinearSearch(a, n, x);
			if (result != -1) {
				printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
			}
			else {
				printf("%d khong ton tai trong mang.\n", x);
			}
		}
		case 4:
			SapXepTangInterChange(a, n);
			printf("Mang sau khi sap xep tang dan: ");
			xuatMang(a, n);
			break;
		case 5:
			SapXepGiamInterChange(a, n);
			printf("Mang sau khi sap xep giam dan: ");
			xuatMang(a, n);
			break;
		case 6:
		{
			SapXepTangInterChange(a, n);
			xuatMang(a, n);
			int x;
			printf("Nhap gia tri x can tim: ");
			scanf("%d", &x);
			int result = BinarySearch(a, n, x);
			if (result != -1) {
				printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
			}
			else {
				printf("%d khong ton tai trong mang.\n", x);
			}
			xuatMang(a, n);
			break;
		}
		case 7:
		{
				  SapXepTangSelection(a, n);
				  xuatMang(a, n);
		}
		case 8:
		{
				  QuickSort(a, 0, n - 1);
				  printf("Mang sau khi sap xep tang dan theo Quick Sort: ");
				  xuatMang(a, n);
				  break;
		}
		default:
			printf("loi xin hay chon lai.\n");
		}
	} while (chon != 0);
	

	return 0;
}