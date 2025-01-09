#include <stdio.h>

int nhapmang(int arr[]) {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

int inmang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    printf("\n");
    return 0;
}

int kiemtrasohoanhao(int n) {
    int tong = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return (tong == n) ? 1 : 0;
}

int sohoanhao(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (kiemtrasohoanhao(arr[i])) {
            count++;
        }
    }
    return count;
}

int timgiatrilonthu2(int arr[], int n) {
    if (n < 2) {
        return -1;
    }
    int max1 = arr[0];
    int max2 = arr[1];
    if (max1 < max2) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }
    return max2;
}

int themphantu(int arr[], int n) {
    int val, index;
    printf("Nhap phan tu can them: ");
    scanf("%d", &val);
    printf("Nhap vi tri muon them: ", n);
    scanf("%d", &index);
    if (index >= 0 && index <= n) {
        for (int i = n; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        return n + 1;
    }
    return n;
}

int xoaphantu(int arr[], int n) {
    int index;
    printf("Nhap vi tri muon xoa: ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        return n - 1;
    }
    return n;
}

int sapxep_insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}

int binarysearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int sapxepchanle(int arr[], int n) {
    int arr_chan[n], arr_le[n];
    int chan_count = 0, le_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr_chan[chan_count++] = arr[i];
        } else {
            arr_le[le_count++] = arr[i];
        }
    }

    for (int i = 0; i < chan_count - 1; i++) {
        for (int j = i + 1; j < chan_count; j++) {
            if (arr_chan[i] > arr_chan[j]) {
                int temp = arr_chan[i];
                arr_chan[i] = arr_chan[j];
                arr_chan[j] = temp;
            }
        }
    }

    for (int i = 0; i < le_count - 1; i++) {
        for (int j = i + 1; j < le_count; j++) {
            if (arr_le[i] > arr_le[j]) {
                int temp = arr_le[i];
                arr_le[i] = arr_le[j];
                arr_le[j] = temp;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < chan_count; i++) {
        arr[index++] = arr_chan[i];
    }
    for (int i = 0; i < le_count; i++) {
        arr[index++] = arr_le[i];
    }

    return 0;
}

int daonguocmang(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    return 0;
}

int main() {
    int arr[100];
    int n = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong so hoan hao co trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu tang dan(Insertion sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Sap xep mang sao cho so chan dung truoc, so le dung sau\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("11. Thoat!\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = nhapmang(arr);
                break;
            case 2:
                inmang(arr, n);
                break;
            case 3:
                printf("So luong so hoan hao: %d\n", sohoanhao(arr, n));
                break;
            case 4:
                printf("Gia tri lon thu hai trong mang: %d\n", timgiatrilonthu2(arr, n));
                break;
            case 5:
                n = themphantu(arr, n);
                break;
            case 6:
                n = xoaphantu(arr, n);
                break;
            case 7:
                sapxep_insertionsort(arr, n);
                printf("Mang sau khi sap xep: ");
                inmang(arr, n);
                break;
            case 8: {
                int x;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                if (binarysearch(arr, n, x)) {
                    printf("Phan tu %d co trong mang!\n", x);
                } else {
                    printf("Phan tu %d khong co trong mang!\n", x);
                }
                break;
            }
            case 9:
                sapxepchanle(arr, n);
                printf("Mang sau khi sap xep chan truoc, le sau: ");
                inmang(arr, n);
                break;
            case 10:
                daonguocmang(arr, n);
                printf("Mang sao khi dao nguoc: ");
                inmang(arr, n);
                break;
            case 11:
                printf("Thoat chuong trinh!!!.\n");
                return 0;
        }
    }
    return 0;
}
