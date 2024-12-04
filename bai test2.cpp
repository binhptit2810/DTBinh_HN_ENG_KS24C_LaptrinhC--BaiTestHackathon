#include <stdio.h>

int main() {
    const int MAX = 100;
    int arr[MAX][MAX];
    int rows = 0, cols = 0;
    int choice;

    do {
        // in menu ra ngoai man hinh
        printf("\n      MENU      \n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. in ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In cac phan tu nam tren duong cheo chinh\n");
        printf("5. In cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
            // nhap gia tri va kich co cua mang
                printf("Nhap so hang: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);

                if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
                    printf("Kich co mang khong hop le!\n");
                } else {
                    printf("Nhap cac phan tu cua mang:\n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            printf("arr[%d][%d]: ", i, j);
                            scanf("%d", &arr[i][j]);
                        }
                    }
                }
                break;
            }
            case 2: { 
            // in mang ra theo kieu ma tran
                printf("Ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
           
            case 3: { 
            //in cac phan tu duong bien va tinh tich
                int product = 1;
                printf("Cac phan tu tren duong bien la:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", arr[i][j]);
                            product *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", product);
                break;
            }
            case 4: { // in cac phan tu cua duong cheo chinh
                if (rows != cols) {
                    printf("Ma tran khong phai vuong, khong co duong cheo chinh!\n");
                } else {
                    printf("Cac phan tu tren duong cheo chinh la:\n");
                    for (int i = 0; i < rows; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 5: {
            	// in cac phan tu nam tren duong cheo phu
            	if (rows != cols) {
            		printf("Khong phai ma tran vuong , khong co duong cheo phu");
				}else{
					printf("Cac phan tu nam tren duong cheo phu la: \n");
					for (int i =0 ; i< rows; i++){
						printf("%d",arr[i][cols-1-i]);
					}
					printf("\n");
				}
				break;
			}
			case 6: {
                // sap xep duong cheo chinh tang dan
                if (rows != cols) {
                    printf("Ma tran khong phai vuong, khong sap xep duoc duong cheo chinh!\n");
                } else {
                    int diag[MAX], n = 0;
                    for (int i = 0; i < rows; i++) {
                        diag[n++] = arr[i][i];
                    }
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (diag[i] > diag[j]) {
                                int temp = diag[i];
                                diag[i] = diag[j];
                                diag[j] = temp;
                            }
                        }
                    }
                    for (int i = 0; i < rows; i++) {
                        arr[i][i] = diag[i];
                    }
                    printf("Da sap xep duong cheo chinh theo thu tu tang dan!\n");
                }
                break;
            }
            case 7: {
                // tim kiem 1 phan tu va in ra vi tri cua phan tu do
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Vi tri cua gia tri %d trong ma tran:\n", value);
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (arr[i][j] == value) {
                            printf("(%d, %d) ", i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d trong ma tran.\n", value);
                } else {
                    printf("\n");
                }
                break;
            }
        }
    } while (choice != 8);
    printf("Ket thuc chuong trinh");

    return 0;
}

