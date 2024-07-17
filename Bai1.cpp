#include <stdio.h>
#include <conio.h>
#include <time.h>

void taoMangRandom(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
int main() {
	int n;
	int chon;
	int x;
	int index;

	while (1) {
		printf("\nChon mot trong cac tuy chon sau:\n");
		printf("1. Tao mang ngau nhien\n");
		printf("2. Tao mang so chan\n");
		printf("3. Tim kiem tuyen tinh\n");
		printf("4. Sap xep Interchange Sort tang dan\n");
		printf("5. Tim kiem nhi phan\n");
		printf("6. Sap xep Selection Sort\n");
		printf("7. Sap xep Quick Sort\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &chon);

		switch (chon) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			printf("Thoat chuong trinh.\n");
			return 0;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	}

	return 0;
}