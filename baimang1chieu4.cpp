#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if ( n < 2) return false;
    for (int i = 2; i <= sqrt(n);i++){
        if (n % i == 0) return false;
    }
    return true;
}
int ClosestPrime(int n) {
    if (n <= 1) return 2;
    if (isPrime(n)) return n;
    int nhoHon = n - 1;
    int lonHon = n + 1;
    while (true) {
        if (isPrime(nhoHon)) return nhoHon;
        if (isPrime(lonHon)) return lonHon;
        nhoHon--;
        lonHon++;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang (3 <= n <= 50): ";
    cin >> n;
    if (n < 3 || n > 50) {
        cout << "Nhap lai!" << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Nhap cac phan tu cua mang"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0 && arr[i] % 2 == 0) {
            arr[i] /= 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!isPrime(arr[i])) {
            arr[i] = ClosestPrime(arr[i]);
        }
    }
    cout << "Mang sau khi thay doi";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}