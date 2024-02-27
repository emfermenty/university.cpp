/* Дано натуральное N и массив целых чисел размерности N. Отсортировать данный массив
по убыванию методом простого выбора. В процессе сортировки отсортированную часть накапливать в начале массива. 
Вывести содержимое массива после каждой итерации сортировки. 
Одной итерацией сортировки считать такое действие, в результате которого один элемент массива
гарантированно встает на правильное место в отсортированном массиве. 
При выводе массива отсортированную часть отделять от неотсортированной с помощью символа |. 
Протокол сортировки выводить в текстовый файл. */

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

void sort_vybor(int arr[], int n)
{
    ofstream file("sort.txt");

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;

        file << "Итерация " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            if (j == i) {
                file << arr[j] << " ";
                file << "| ";
                j++;
            }
            file << arr[j] << " ";
        }
        file << endl;
    }

    file.close();
}


int main() {
    int n;
    cout << "press amount elements of array: " << endl;
    cin >> n;
    int* arr = new int[n];
    cout << "press elements of array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort_vybor(arr, n);

    cout << "final vyvod" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}