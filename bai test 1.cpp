#include <stdio.h>

int main() {
	// khai  bao mang
    int arr[100]; 
    int size = 0; 
    int choice;

    do {
        // In menu ra ngoai man hinh
        printf("\n      MENU      \n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Nhap so phan tu va gia tri cac phan tu
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);
                if (size <= 0 || size > 100) {
                    printf("So phan tu khong hop le!\n");
                    size = 0;
                } else {
                    for (int i = 0; i < size; i++) {
                        printf("Nhap gia tri phan tu arr[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: {
                // In gia tri cac phan tu dang quan ly
                if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                // in ra gia tri lon nhat cua mang
                if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    int max = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri lon nhat cua mang: %d\n", max);
                }
                break;
            }
            case 4: {
                // in ra cac phan tu la so nguyen to cua mang
                if (size == 0) {
                    printf("Mang rong!\n");
                } else {
                    printf("Cac phan tu la so nguyen to: ");
                    for (int i = 0; i < size; i++) {
                        int isPrime = 1;
                        if (arr[i] <= 1) isPrime = 0;
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime) {
                            printf("%d ", arr[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case 5: {
                // them phan tu vao ben trong mang
                if (size >= 100) {
                    printf("Mang da day, khong the them phan tu!\n");
                } else {
                    int value;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    arr[size] = value;
                    size++;
                    printf("Da them %d vao mang.\n", value);
                }
                break;
            }
            case 6: {
                // xoa 1 phan tu trong mang
                if (size == 0) {
                    printf("Mang rong, khong co phan tu de xoa!\n");
                } else {
                    int index;
                    printf("Nhap vi tri can xoa (0 - %d): ", size - 1);
                    scanf("%d", &index);
                    if (index < 0 || index >= size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = index; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Da xoa phan tu tai vi tri %d.\n", index);
                    }
                }
                break;
            }
            case 7: {
                // S?p x?p m?ng theo th? t? tang d?n
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep tang dan.\n");
                break;
            }
            case 8: {
                // Tim kiem phan tu va in ra vitri index
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Vi tri cua gia tri %d trong mang: ", value);
                for (int i = 0; i < size; i++) {
                    if (arr[i] == value) {
                        printf("%d ", i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d trong mang.\n", value);
                } else {
                    printf("\n");
                }
                break;
            }
            case 9: {
                // thoat chuong trinh
                printf("Ket thuc chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 9);

    return 0;
}

