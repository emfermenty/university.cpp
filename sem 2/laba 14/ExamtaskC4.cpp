//На вход подаются сведения о клиентах фитнес-центра. В первой строке
//указывается целое число N, а каждая из последующих N строк имеет формат
//<Номер месяца> <Год> <Код клиента> <Продолжительность занятий(в часах)>
//Все данные целочисленные.Значение года лежит в диапазоне от 2000 до 2010, код клиента — в
//диапазоне 10–99, продолжительность занятий — в диапазоне 1−30.Найти строку исходных
//данных с максимальной продолжительностью занятий.Вывести эту продолжительность, а
//также соответствующие ей год и номер месяца(в указанном порядке).Если имеется несколько
//строк с максимальной продолжительностью, то вывести данные, соответствующие самой
//поздней дате.



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;
struct Client {
	int num_month;
	int num_year;
	int id_client;
	int duration;
};

int main() {
	setlocale(LC_ALL, "RU");
	int N;
	cout << "Введите количество людей в структуре: ";
	cin >> N;

	vector<Client> clients(N);

	for (int i = 0; i < N; i++) {
		cout << "Введите информацию по " << i+1 << " клиенту:" << endl;
		cout << "Номер месяца(0-12): ";
		cin >> clients[i].num_month;
		if (clients[i].num_month < 0 || clients[i].num_month > 12) {
			cout << "Неверный номер";
			return 0;
		}
		cout << "Год(2000-2010): ";
		cin >> clients[i].num_year;
		if (clients[i].num_year < 2000 || clients[i].num_year > 2010) {
			cout << "Неверный номер";
			return 0;
		}
		cout << "Номер клиента(10-99): ";
		cin >> clients[i].id_client;
		if (clients[i].id_client < 10 || clients[i].id_client > 99) {
			cout << "Неверный номер";
			return 0;
		}
		cout << "Длительность(1-30): ";
		cin >> clients[i].duration;
		if (clients[i].duration < 1 || clients[i].duration > 30) {
			cout << "Неверный номер";
			return 0;
		}
	}
	int max_duration = 0, max_year, max_month;
	for (int i = 0; i < N; i++) {
		if (clients[i].duration > max_duration || (clients[i].duration == max_duration && clients[i].num_year > max_year)) {
			max_duration = clients[i].duration;
			max_year = clients[i].num_year;
			max_month = clients[i].num_month;
		}
	}
	cout << "Максимальная длительность: " << max_duration << "\nГод: " << max_year << "\nМесяц: " << max_month;

}