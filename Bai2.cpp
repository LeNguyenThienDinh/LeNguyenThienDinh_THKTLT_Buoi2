#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Min 15

typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;

HonSo taoHonSoNgauNhien(int min, int max) {
	HonSo hs;
	hs.phanNguyen = min + rand() % (max - min + 1);
	hs.tuSo = min + rand() % (max - min + 1);
	hs.mauSo = min + rand() % (max - min) + 1;
	return hs;
}

void taoMangHonSoNgauNhien(HonSo b[], int n, int min, int max) 
{
	for (int i = 0; i < n; i++) 
	{
		b[i] = taoHonSoNgauNhien(min, max);
	}
}

void xuatMang(HonSo b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %d / %d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
	}
}
int main() {
	srand(time(0));
	int n;
	printf("Nhap so phan tu n (>= 15): ");
	scanf("%d", &n);
	if (n < Min) {
		printf("So luong phan tu phai it nhat la %d.\n", Min);
		return 1;
	}
	HonSo *b = (HonSo *)malloc(n * sizeof(HonSo));
	if (b == NULL) {
		printf("Khong du bo nho.\n");
		return 1;
	}
	int chon;
	do {
		printf("\nMenu:\n");
		printf("1. Tao mang hon so ngau nhien\n");
		printf("2. Xuat danh sach hon so\n");
		printf("0. Thoat\n");
		printf("Hay nhap lua chon: ");
		scanf("%d", &chon);

		switch (chon) {
		case 1:
			taoMangHonSoNgauNhien(b, n, 0, 100);
			printf("Mang hon so ngau nhien da duoc tao.\n");
			break;
		case 2:
			printf("Danh sach hon so:\n");
			xuatMang(b, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (chon != 0);

	free(b);
	return 0;
}