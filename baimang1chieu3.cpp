#include <iostream>
#include <math.h>
using namespace std;

void nhapMang(double* mang, int n) {
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> mang[i];
    }
}

double tinhTrungBinhCongPhanTuChan(double* mang, int n) {
    double tong = 0;
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        int phanNguyen = static_cast<int>(mang[i]);
        if (phanNguyen % 2 == 0) {
            tong += mang[i];
            dem++;
        }
    }
    if (dem == 0) {
        return -1;
    }
    return tong / dem;
}

void sapXepMangTangDan(double* mang, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mang[i] > mang[j]) {
                swap(mang[i], mang[j]);
            }
        }
    }
}

void chuyenPhanTuLeThanh1_23(double* mang, int n) {
    for (int i = 0; i < n; ++i) {
        int phanNguyen = mang[i];
        if (phanNguyen % 2 != 0) {
            mang[i] = 1.23;
        }
    }
}

void inMang(double* mang, int n) {
    for (int i = 0; i < n; ++i) {
        cout  << mang[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang (3 <= n <= 50): ";
    cin >> n;

    if (n < 3 || n > 50) {
        cout << "Nhap lai!" << endl;
        return 1;
    }

    double* mang = new double[n];
    nhapMang(mang, n);

    double trungBinhCong = tinhTrungBinhCongPhanTuChan(mang, n);
    if (trungBinhCong == -1) {
        cout << "-1" << endl;
    } else {
        cout << "Trung binh cong cua cac phan tu co phan nguyen chan la: "   << trungBinhCong << endl;
    }

    sapXepMangTangDan(mang, n);
    cout << "Mang sau khi sap xep tang dan la: ";
    inMang(mang, n);

    chuyenPhanTuLeThanh1_23(mang, n);
    cout << "Mang sau khi chuyen cac phan tu le thanh 1.23: ";
    inMang(mang, n);

    delete[] mang;
    return 0;
}