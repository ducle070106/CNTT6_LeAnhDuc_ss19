#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
void nhapChuoi(char **str) {
    if (*str != NULL) {
        free(*str);
    }
    *str = (char *)malloc(MAX_SIZE * sizeof(char));
    if (*str == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    printf("Nhap chuoi: ");
    getchar();
    fgets(*str, MAX_SIZE, stdin);
    (*str)[strcspn(*str, "\n")] = 0;
}
void inChuoiDaoNguoc(char *str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Chuoi rong. Vui long nhap chuoi truoc.\n");
        return;
    }
    int len = strlen(str);
    printf("Chuoi dao nguoc la: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
}
void demSoTu(char *str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Chuoi rong. Vui long nhap chuoi truoc.\n");
        return;
    }
    int count = 0;
    char *ptr = str;
    while (isspace(*ptr)) {
        ptr++;
    }
    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            count++;
            while (isspace(*ptr)) {
                ptr++;
            }
        } else {
            ptr++;
        }
    }
    if (strlen(str) > 0) {
        count++;
    }
    printf("So luong tu trong chuoi la: %d\n", count);
}
void soSanhDoDai(char *str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Chuoi ban dau rong. Vui long nhap chuoi truoc.\n");
        return;
    }
    char *otherStr = (char *)malloc(MAX_SIZE * sizeof(char));
    if (otherStr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return;
    }
    printf("Nhap chuoi khac de so sanh: ");
    getchar();
    fgets(otherStr, MAX_SIZE, stdin);
    otherStr[strcspn(otherStr, "\n")] = 0;
    int len1 = strlen(str);
    int len2 = strlen(otherStr);
    if (len2 > len1) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else if (len2 < len1) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
    free(otherStr);
}
void inHoaChuoi(char *str) {
    if (str == NULL || strlen(str) == 0) {
        printf("Chuoi rong. Vui long nhap chuoi truoc.\n");
        return;
    }
    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
    printf("Chuoi sau khi in hoa: %s\n", str);
}
void themChuoi(char **str) {
    if (*str == NULL) {
        printf("Chuoi ban dau rong. Vui long nhap chuoi truoc.\n");
        return;
    }
    char *newStr = (char *)malloc(MAX_SIZE * sizeof(char));
    if (newStr == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return;
    }
    printf("Nhap chuoi can them vao: ");
    getchar();
    fgets(newStr, MAX_SIZE, stdin);
    newStr[strcspn(newStr, "\n")] = 0;
    int currentLen = strlen(*str);
    int newLen = strlen(newStr);
    int totalLen = currentLen + newLen + 1;
    *str = (char *)realloc(*str, totalLen * sizeof(char));
    if (*str == NULL) {
        printf("Cap phat lai bo nho that bai!\n");
        exit(1);
    }
    strcat(*str, newStr);
    printf("Chuoi sau khi them la: %s\n", *str);

    free(newStr);
}
void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi dao nguoc\n");
    printf("3. Dem so luong tu trong chuoi\n");
    printf("4. So sanh do dai chuoi\n");
    printf("5. In hoa tat ca chu cai\n");
    printf("6. Them chuoi vao chuoi ban dau\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}
int main() {
    char *myString = NULL;
    int choice;

    do {
        hienThiMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapChuoi(&myString);
                break;
            case 2:
                inChuoiDaoNguoc(myString);
                break;
            case 3:
                demSoTu(myString);
                break;
            case 4:
                soSanhDoDai(myString);
                break;
            case 5:
                inHoaChuoi(myString);
                break;
            case 6:
                themChuoi(&myString);
                break;
            case 7:
                printf("Tam biet!\n");
                if (myString != NULL) {
                    free(myString);
                }
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}