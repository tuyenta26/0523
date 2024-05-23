#include <iostream>
using namespace std;

bool tangDan (int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool giamDan(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang (3 <= n <= 50): ";
    cin >> n;

    if (n < 3 || n > 50) {
        cout << "Nhap lai!." << endl;
        return 0;
    }

    int* mang = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> mang[i];
    }

    int x;
    cout << "Nhap so nguyen x: ";
    cin >> x;

    int dem = 0;
    for (int i = 0; i < n; ++i) {
        if (mang[i] < x) {
            dem++;
        }
    }
    cout << "So phan tu co gia tri nho hon " << x << " la: " << dem << endl;

    int tong = 0;
    int demChiaHet3KhongChiaHet5 = 0;
    for (int i = 0; i < n; ++i) {
        if (mang[i] % 3 == 0 && mang[i] % 5 != 0) {
            tong += mang[i];
            demChiaHet3KhongChiaHet5++;
        }
    }

    if (demChiaHet3KhongChiaHet5 > 0) {
        double trungBinhCong = tong / demChiaHet3KhongChiaHet5;
        cout << "Trung binh cong cua ca so chia het cho 3 ma khong chia het cho 5 la: " << trungBinhCong << endl;
    } else {
        cout << "Khong co so nao hop le." << endl;
    }

    if (tangDan (mang, n) || giamDan(mang, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    delete[] mang;

    return 0;
}