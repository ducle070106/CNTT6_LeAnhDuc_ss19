#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    if (*n <= 0) {
        printf("So phan tu khong hop le.\n");
        *n = 0;
        return;
    }
    if (*arr != NULL) {
        free(*arr);
    }
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
void inSoChan(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    printf("Cac phan tu chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
void inSoNguyenTo(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    printf("Cac phan tu la so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(*(arr + i))) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
void daoNguocMang(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("Da dao nguoc mang.\n");
}
void sapXepTang(int *arr, int n) {
    if (n <= 0) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    printf("Da sap xep mang tang dan.\n");
}
void sapXepGiam(int *arr, int n) {
    if (n <= 0) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    printf("Da sap xep mang giam dan.\n");
}
void timKiemPhanTu(int *arr, int n) {
    if (n <= 0) {
        printf("Mang rong. Vui long nhap mang truoc.\n");
        return;
    }
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == value) {
            printf("Tim thay phan tu %d tai vi tri %d.\n", value, i);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", value);
    }
}
void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu la so chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("6. Nhap vao mot phan tu va tim kiem\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}
void hienThiMenuSapXep() {
    printf("\n--- MENU SAP XEP ---\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
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
                nhapMang(&array, &size);
                break;
            case 2:
                inSoChan(array, size);
                break;
            case 3:
                inSoNguyenTo(array, size);
                break;
            case 4:
                daoNguocMang(array, size);
                break;
            case 5:
                if (size <= 0) {
                    printf("Mang rong. Vui long nhap mang truoc.\n");
                    break;
                }
                int subChoice;
                hienThiMenuSapXep();
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sapXepTang(array, size);
                } else if (subChoice == 2) {
                    sapXepGiam(array, size);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                timKiemPhanTu(array, size);
                break;
            case 7:
                printf("Tam biet!\n");
                if (array != NULL) {
                    free(array);
                }
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 7);
    return 0;
}
