#include <iostream>
#include <math.h>
using namespace std;

bool laChuSoTangDan(int num) {
    if (num < 0) num = abs(num); 
    int chuSoTruoc = 10; 
    while (num > 0) {
        int chuSoHienTai = num % 10;
        if (chuSoHienTai > chuSoTruoc) {
            return false;
        }
        chuSoTruoc = chuSoHienTai;
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang (2 < n < 50): ";
    cin >> n;
    while (n <= 2 || n >= 50) {
        cout << "Nhap lai! ";
        cin >> n;
    }

    int* arr = new int[n];

    cout << "Nhap cac phan tu cua mang:";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu"<< i + 1<< " ";
        cin >> arr[i];
    }

    int* b = arr;
    cout << "Cac phan tu co chu so tang dan la";
    for (int i = 0; i < n; ++i) {
        if (laChuSoTangDan(b[i])) {
            cout << b[i] << " ";
        }
    }
    cout << endl;

    delete[] arr;

    return 0;
}