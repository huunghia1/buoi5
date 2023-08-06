#include <iostream>

using namespace std;


//- S? nguyên t?
bool soNguyenTo(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// - M?ng d?i x ?ng
bool checkMang(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        if (A[i] != A[n - i - 1])
            return false;
    }
    return true;
}

// - Li?t kê giá tr? xu?t hi?n 1 l?n
void check(int mang[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (mang[i] == mang[j]) {
                count++;
            }
        }
        if (count == 1) { 
            cout << mang[i] << " ";
        }
    }
    cout << endl;
}

// - Xóa ph?n t?
int xoaPTu(int a[], int& n, int k) {
    if (k < 0 || k >= n) {
        return 0;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}
const int MAX_SIZE = 100;

int main() {

    int choice;

    do {
        cout << "=== Yêu cau ve mang ===" << endl;
        cout << "1. So nguyen to trong mang." << endl;
        cout << "2. Mang doi xung." << endl;
        cout << "3. Liet ke gia tri xuat hien 1 lan." << endl;
        cout << "4. Vi tri gia tri am lon nhat." << endl;
        cout << "5. Xoa phan tu k." << endl;
        cout << "0. Thoat." << endl;
        cout << "Chon yeu cau: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                int n;

                do {
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                }while (n <= 0);       
            
                int* arr = new int[n];
                cout << "Nhap day tang dan:\n";

                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];

                    if (i > 0 && arr[i] <= arr[i - 1]) {
                        cout << "Day khong thoa man! Nhap lai day tang dan " << (i + 1) << ": ";
                        --i;
                    }
                }

                cout << "Cac so nguyen to co trong mang: ";
                for (int i = 0; i < n; ++i) {
                    if (soNguyenTo(arr[i])) {
                        cout << arr[i] << " ";
                    }
                }

                delete[] arr;

                break;
            }
            case 2:
            {
                int n;
                do {
                    cout << "Nhap so luong phan tu ( > 0): ";
                    cin >> n;
                } while (n <= 0);

                int mang[100];
                cout << "Nhap phan tu: ";
                for (int i = 0; i < n; i++) {
                    cin >> mang[i];
                }

                if (checkMang(n, mang)) {
                    cout << "Mang doi xung";
                } else {
                    cout << "Khong phai mang doi xung";
                }
                break;
            }
            case 3:
            {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;

                int mang[100];
                cout << "Nhap gia tri phan tu: ";
                for (int i = 0; i < n; i++) {
                    cin >> mang[i];
                }

                cout << "Cac phan tu xuat hien 1 lan là: ";
                check(mang, n);
                break;
            }
            case 4:
            {
                const int SIZE = 10;
                int mang[SIZE];
                
                cout << "Nhap mang " << SIZE << " phan tu: ";
                for (int i = 0; i < SIZE; ++i) {
                    cin >> mang[i];
                }

                int soAm = -1;
                int viTri = -1;

                for (int i = 0; i < SIZE; ++i) {
                    if (mang[i] < 0 && (viTri == -1 || mang[i] > soAm)) {
                        soAm = mang[i];
                        viTri = i;
                    }
                }

                if (viTri != -1) {
                    cout << "Gia tri am lon nhat " << soAm << "  vi tri " << viTri << endl;
                } else {
                    cout << "Khong có gia tri am trong mang!" << endl;
                }
                break;
            }
            case 5:
            {
                int n;
                int a[MAX_SIZE];
                
                cout << "Nhap so luong phan tu: ";
                cin >> n;

                cout << "Nhap " << n << " gia tri phan tu:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }

                int k;
                cout << "Nhap vi tri muon xoa: ";
                cin >> k;

                int result = xoaPTu(a, n, k);
                if (result == 1) {
                    cout << "Xoa tai vi tri " << k << " thanh cong." << endl;
                    cout << "Mang sau khi xoa la:" << endl;
                    for (int i = 0; i < n; i++) {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Vi tri " << k << " nam ngoai pham vi xoa."<< endl;
                }
                break;
            }
            case 0:
                cout << "Thoat" << endl;
                break;
            default:
                cout << "Vui long chon lai" << endl;
        }
    } while (choice != 0);

    return 0;
}
