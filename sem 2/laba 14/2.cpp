/*Имеется информация об учениках младшей школы.Для всех учеников известны :
фамилия, имя и класс.Для учеников 1 - х классов дополнительно известна их скорость чтения
(слов в минуту, тип short int).Для учеников 4 - х классов известны баллы итоговой аттестации
(единый муниципальный тест от 1 до 100 баллов, тип float).Для учеников 2 - х и 3 - х классов
известны данные итоговой школьной контрольной по математике(оценки от 1 до 10 баллов,
тип short int).Описать структурный тип «ученик».Обязательно использовать тип union!
Написать процедуру, позволяющую ввести с клавиатуры данные для одного ученика.Используя
эту процедуру, ввести сведения об N учениках и сохранить их в бинарном файле.Распечатать
на экране содержимое данного файла в виде таблицы*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;
struct Student {
	string surname;
	string name;
	int grade;
	union {
		short int reading_speed;
		short int math_score;
		float exam_score;
	};
};


void enterStudentData(Student& student) {
    cout << "Введите фамилию: ";
    cin >> student.surname;
    cout << "Введите имя: ";
    cin >> student.name;
    cout << "Введите класс(1-4): ";
    cin >> student.grade;

    if (student.grade == 1) {
        cout << "Слов в минуту: ";
        cin >> student.reading_speed;
    }
    else if (student.grade == 4) {
        cout << "Баллы за экзамен: ";
        cin >> student.exam_score;
    }
    else {
        cout << "Баллы по математике: ";
        cin >> student.math_score;
    }
}


int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "Введите количество учеников: ";
    cin >> N;

    Student* students = new Student[N];

    for (int i = 0; i < N; i++) {
    cout << "Введите информацию для учеников с номером: " << i + 1 << endl;
        enterStudentData(students[i]);
    }

    ofstream file("students.dat", ios::binary);
    file.write((char*)students, N * sizeof(Student));
    file.close();

    delete[] students;

    ifstream readFile("students.dat", ios::binary);

    Student studentFromFile;
    while (readFile.read((char*)&studentFromFile, sizeof(Student))) {
    cout << "Фамилия: " << studentFromFile.surname << "\tИмя: " << studentFromFile.name << "\t Класс: " << studentFromFile.grade;
        if (studentFromFile.grade == 1) {
            cout << "\tСкорость чтения: " << studentFromFile.reading_speed << " слов в минуту";
        }
        else if (studentFromFile.grade == 2 || studentFromFile.grade == 3) {
            cout << "\tСтатистика по математике: " << studentFromFile.math_score;
        }
        else if (studentFromFile.grade == 4) {
            cout << "\tРезультат за экзамен: " << studentFromFile.exam_score;
        }
        cout << endl;
    }

    readFile.close();

    return 0;
}