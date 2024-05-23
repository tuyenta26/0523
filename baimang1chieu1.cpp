#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang (3 <= n <= 50): ";
    cin >> n;
    while (n < 3 || n > 50) {
        cout << "Nhap lai! ";
        cin >> n;
    }

    int* mang = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> mang[i];
    }

    bool coSoChanGanNhau = false;
    for (int i = 0; i < n - 1; ++i) {
        if (mang[i] % 2 == 0 && mang[i + 1] % 2 == 0) {
            coSoChanGanNhau = true;
            break;
        }
    }
    cout << "Kiem tra mang co 2 so chan gan nhau khong: ";
    if (coSoChanGanNhau) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    int* mangSoLe = new int[n]; 
    int* mangSoChan = new int[n]; 
    int demSoLe = 0, demSoChan = 0;
    for (int i = 0; i < n; ++i) {
        if (mang[i] % 2 != 0) {
            mangSoLe[demSoLe++] = mang[i];
        } else if (mang[i] != 0) {
            mangSoChan[demSoChan++] = mang[i];
        }
    }

    cout << "Mang so le - Mang so chan:\n";
    if (demSoLe == 0 || demSoChan == 0) {
        cout << "-1\n"; 
    } else {
        for (int i = 0; i < demSoLe; ++i) {
            cout << mangSoLe[i] << " ";
        }
        cout << "-";
        for (int i = 0; i < demSoChan; ++i) {
            cout << " " << mangSoChan[i];
        }
        cout << endl;
    }

    sort(mang, mang + n, greater<int>());

    cout << "Mang sau khi sap xep:\n";
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " ";
    }
    cout << endl;

    delete[] mang;
    delete[] mangSoLe;
    delete[] mangSoChan;

    return 0;
}