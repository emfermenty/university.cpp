/*Дано целое число X и текстовый файл. В файле записан набор целых чисел, 
расположенных в неубывающем порядке. 
С помощью метода бинарного поиска определить индекс самого левого вхождения числа X 
в исходный набор. 
Нумерация элементов начинается с нуля. 
Если элемент не найден, вывести -1. Чисел в исходном наборе не более 200.*/

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int binarysearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            result = mid;
            return result;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ofstream zapfile("binary.txt");
    int k = 2;
    for (int i = 0; i < 200; i++) {
        zapfile << k << " ";
        k += 2;
    }
    zapfile.close();

    ifstream file("binary.txt");
    int count=0;
    int n;
    while (file >> n){
        count++;
    }

    file.close();
    ifstream fiile("binary.txt");
    int* arr = new int[count];

    for (int i = 0; i < count; i++) {
        fiile >> arr[i];
    }
    int x;
    cout << "Press X(digit which you want finded): ";
    cin >> x;

    int last = binarysearch(arr, count, x);
    cout << "your index: " << last;
    fiile.close();
}