#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "size of matrix(n x m): " << endl;
    cin >> n >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int maxel = arr[0][0];
    int itaya = 0;
    int jtaya = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > maxel) {
                maxel = arr[i][j];
                itaya = i;
                jtaya = j;
            }
        }
    }
    cout << "max: " << maxel << ", i: " << itaya << ", j: " << jtaya;
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}