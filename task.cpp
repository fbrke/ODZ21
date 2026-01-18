#include <iostream>
using namespace std;

void fillArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = (i * 8 + 11) % 100;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void shakerSort(int a[], int n, int& C, int& M) {
    C = 0; 
    M = 0; 

    int left = 0;
    int right = n - 1;

    while (left < right) {
        for (int i = left; i < right; i++) {
            C++;
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                M++;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            C++;
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                M++;
            }
        }
        left++;
    }
}

int main() {
    int n;
    cout << "Введите размер массива n: ";
    cin >> n;

    int a[100];

    fillArray(a, n);

    cout << "\nИсходный массив:\n";
    printArray(a, n);

    int C, M;
    shakerSort(a, n, C, M);

    cout << "\nОтсортированный массив:\n";
    printArray(a, n);

    cout << "\nКоличество сравнений C(n) = " << C << endl;
    cout << "Количество перестановок M(n) = " << M << endl;

    return 0;
}