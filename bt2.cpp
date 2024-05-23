#include <iostream>
#include <cctype>  
using namespace std;

int tinhTongChuSo(const char* str) {
    int tong = 0;
    while (*str) {
        if (isdigit(*str)) {
            tong += *str - '0';
        }
        str++;
    }
    return tong;
}

char* chuanHoaChuoi(const char* str) {
    int doDaiMoi = 0;
    for (const char* p = str; *p; ++p) {
        if (!isdigit(*p)) {
            doDaiMoi++;
        }
    }

    char* chuoiMoi = new char[doDaiMoi + 1];
    int index = 0;
    for (const char* p = str; *p; ++p) {
        if (!isdigit(*p)) {
            chuoiMoi[index++] = *p;
        }
    }
    chuoiMoi[index] = '\0'; 

    return chuoiMoi;
}

int main() {
    char* chuoi = new char[100];
    cout << "nhap vao mot chuoi ky tu bat ky: ";
    cin >>  chuoi;

    int tong = tinhTongChuSo(chuoi);
    cout << "Tong cac chu so trong chuoi la: " << tong << endl;

    char* chuoiChuanHoa = chuanHoaChuoi(chuoi);
    cout << "Chuoi sau khi chuan hoa thanh ten rieng: " << chuoiChuanHoa << endl;

    delete[] chuoi;
    delete[] chuoiChuanHoa;

    return 0;
}