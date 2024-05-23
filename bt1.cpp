#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void sortArray(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang (2 < n < 50): ";
    cin >> n;

    if (n <= 2 || n >= 50) {
        cout << "Nhap lai!" << endl;
        return 1;
    }
    int* arr = new int[n];
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; ++i) {
        cout<<"Phan tu thu" << i + 1 << ": ";
        cin >> arr[i];
    }
    sortArray(arr, n);
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
        if (!isPrime(sumOfDigits(arr[i]))) {
            newSize++;
        }
    }
    int* newArr = new int[newSize];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (!isPrime(sumOfDigits(arr[i]))) {
            newArr[index++] = arr[i];
        }
    }


    cout << "Mang sau khi xoa cac phan tu co tong la so Nguyen to: ";
    for (int i = 0; i < newSize; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] newArr;

    return 0;
}