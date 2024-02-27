#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "size of matrix(n x n): " << endl;
    cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cout << "mirror matrix";
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << arr[i][j] << " ";
            }
            if (i < j) {
                cout << arr[j][i] << " ";
            }
            if (i > j) {
                cout << arr[i][j] << " ";
            }
        }
    }
}