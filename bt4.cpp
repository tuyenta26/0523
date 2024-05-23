#include <iostream>
using namespace std;

void nhapMang(int* &a, int &n) {
    cout << "Nhap so phan tu cua mang (1 < n <= 30): ";
    cin >> n;
    while (n <= 1 || n > 30) {
        cout << "Nhap lai! ";
        cin >> n;
    }

    a = new int[n];
    cout << "Nhap cac phan tu cua mnag";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void saoChepAm(int* a, int n) {
    cout << "cac phan tu am sau khi da sao chep";
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            swap(a[i], a[j]);
            cout << a[j++] << " ";
        }
    }
    cout << endl;
}

void xoaSoChan(int* &a, int &n) {
    int demSoLe = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != 0) {
            a[demSoLe++] = a[i];
        }
    }

    int* temp = new int[demSoLe];
    for (int i = 0; i < demSoLe; ++i) {
        temp[i] = a[i];
    }
    delete[] a;
    a = temp;
    n = demSoLe;
}

int main() {
    int* a;
    int n;
    nhapMang(a, n);
    saoChepAm(a, n);
    xoaSoChan(a, n);
    cout << "Mang sau khi xoa cac so chan la:";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}