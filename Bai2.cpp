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
int main()
{
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
	do{
		printf("chon 0 de thoat chuong trinh");
		switch (chon)
		{
		case 1:
			break;
		default:
			printf("Lua chon khong hop le vui long chon lai");
		}
	} while (chon != 0);
}