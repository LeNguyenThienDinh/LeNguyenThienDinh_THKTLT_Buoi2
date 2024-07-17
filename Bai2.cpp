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

int soSanhHonSo(HonSo hs1, HonSo hs2) {
	int giaTri1 = hs1.phanNguyen * hs1.mauSo + hs1.tuSo;
	int giaTri2 = hs2.phanNguyen * hs2.mauSo + hs2.tuSo;

	if (giaTri1 * hs2.mauSo < giaTri2 * hs1.mauSo) return -1;
	if (giaTri1 * hs2.mauSo > giaTri2 * hs1.mauSo) return 1;
	return 0;
}

void chuyenHonSoSangPhanSo(HonSo hs, int *tuSo, int *mauSo) {
	*tuSo = hs.phanNguyen * hs.mauSo + hs.tuSo;
	*mauSo = hs.mauSo;
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
		printf("3. So sanh 2 hon so duoc chon\n");
		printf("4. Chuyen hon so sang mau so\n");
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
		case 3: 
		{
			int i1, i2;
			printf("Nhap chi so cua hai hon so can so sanh (0 <= x < %d): ", n);
			scanf("%d %d", &i1, &i2);
			if (i1 < 0 || i1 >= n || i2 < 0 || i2 >= n) {
				printf("Chi so khong hop le.\n");
			}
			else {
				int ketQua = soSanhHonSo(b[i1], b[i2]);
				if (ketQua == 0) {
					printf("Hai hon so bang nhau.\n");
				}
				else if (ketQua < 0) {
					printf("Hon so thu nhat nho hon hon so thu hai.\n");
				}
				else {
					printf("Hon so thu nhat lon hon hon so thu hai.\n");
				}
			}
		case 4: 
		{
			int id;
			printf("Nhap chi so cua hon so can chuyen (0 <= honso < %d): ", n);
			scanf("%d", &id);
			if (id < 0 || id >= n) {
				printf("Chi so khong hop le.\n");
			}
			else {
				int tuSo, mauSo;
				chuyenHonSoSangPhanSo(b[id], &tuSo, &mauSo);
				printf("Phan so tuong ung: %d/%d\n", tuSo, mauSo);
			}
			break;
		}
			break;
		}
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