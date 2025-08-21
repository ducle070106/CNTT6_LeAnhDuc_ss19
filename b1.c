#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    printf("Nhap tung phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", *arr + i);
    }
}
void hienThiMang(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
void tinhTong(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    printf("Tong cac phan tu trong mang la: %d\n", sum);
}
void timMax(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    int *maxPtr = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", *maxPtr);
}
void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}
int main() {
    int *array = NULL;
    int size = 0;
    int choice;
    do {
        hienThiMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (array != NULL) {
                    free(array);
                }
                nhapMang(&array, &size);
                break;
            case 2:
                hienThiMang(array, size);
                break;
            case 3:
                if (size > 0) {
                    printf("Do dai mang la: %d\n", size);
                } else {
                    printf("Mang rong. Vui long nhap mang truoc.\n");
                }
                break;
            case 4:
                tinhTong(array, size);
                break;
            case 5:
                timMax(array, size);
                break;
            case 6:
                printf("Tam biet!\n");
                if (array != NULL) {
                    free(array);
                }
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}