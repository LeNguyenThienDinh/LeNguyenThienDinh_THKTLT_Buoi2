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
			break;
		default:
			printf("loi xin hay chon lai.\n");
		}
	} while (chon != 0);
	

	return 0;
}