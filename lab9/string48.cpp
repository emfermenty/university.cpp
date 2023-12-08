#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string a;
	cout << "vvedite stroky ";
	getline(cin, a);

	char del = a[0];
	cout << a[0];
	for (int i = 0; i < a.length(); i++){
		if (a[i] == del) {
			a[i] = '.';	
		}
	}
	for (int i = 1; i < a.length(); i++) {
		cout << a[i];
	}
}