/*На вход подаются сведения о клиентах фитнес-центра. В первой строке
указывается код K одного из клиентов, во второй строке — целое число N, а каждая из
последующих N строк имеет формат
<Продолжительность занятий (в часах)> <Код клиента> <Год> <Номер месяца>
Все данные целочисленные. Значение года лежит в диапазоне от 2000 до 2010, код клиента — в
диапазоне 10–99, продолжительность занятий — в диапазоне 1–30. Для каждого года, в котором
клиент с кодом K посещал центр, определить месяц, в котором продолжительность занятий
данного клиента была наименьшей для данного года (если таких месяцев несколько, то
выбирать месяц с наибольшим номером; месяцы с нулевой продолжительностью занятий не
учитывать). Сведения о каждом годе выводить на новой строке в следующем порядке:
наименьшая продолжительность занятий, год, номер месяца. Упорядочивать сведения по
возрастанию продолжительности занятий, а при равной продолжительности — по возрастанию
номера года. Если данные о клиенте с кодом K отсутствуют, то вывести строку «Нет данных».*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct ClientData {
    int duration;
    int clientCode;
    int year;
    int month;
};

void enterClientData(ClientData& client) {
   cin >> client.duration >> client.clientCode >> client.year >> client.month;
}

void printClientData(const ClientData& client) {
    cout << client.duration << " " << client.year << " " << client.month << endl;
}

int main() {
    int K;
    cin >> K;

    int N;
    cin >> N;

    ClientData minDurationClient;
    minDurationClient.duration = 0;

    bool foundData = false;

    for (int i = 0; i < N; i++) {
        ClientData client;
        enterClientData(client);

        if (client.clientCode == K) {
            if (client.duration < minDurationClient.duration || minDurationClient.duration == 0) {
                minDurationClient = client;
            }
            else if (client.duration == minDurationClient.duration) {
                if (client.year > minDurationClient.year || (client.year == minDurationClient.year && client.month > minDurationClient.month)) {
                    minDurationClient.year = client.year;
                    minDurationClient.month = client.month;
                }
            }

            foundData = true;
        }
    }

    if (!foundData) {
        cout << "Нет данных" << endl;
    }
    else {
        printClientData(minDurationClient);
    }

    return 0;
}