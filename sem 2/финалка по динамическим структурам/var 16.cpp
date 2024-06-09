#include <iostream>
#include <string>

using namespace std;

// Структура для элементов односвязного списка
struct Node {
    int data;
    Node* next;
    //для более простого создания узла
    Node(int val) : data(val), next(nullptr) {}
};


// поиск элемента в списке
Node* searchElement(Node* head, int target) {
    Node* current = head; //создаем еще один указатель на начало
    while (current != nullptr) { // проходимся по всему списку
        if (current->data == target) {
            return current; // возвращаем узел, если найден элемент
        }
        current = current->next; // двигаем в цикле
    }
    return nullptr; // если элемент не был найден
}

void deleteNode(Node*& head, int value) { // удаение элементов
    if (head == nullptr) {
        return; // если пусто, ретурн
    }
    Node* current = head; // указатель с начала 
    Node* previous = nullptr; // с конца
    do {
        if (current->data == value) { //если найденный элемент соответсвует
            if (current == head) { // если это первый
                if (head->next == head) { // и второй равен указателю первого
                    delete head; // то удаляем первый
                    head = nullptr;
                } 
                else { // если следующий не имеет указатель первого
                    Node* temp = head; // запоминаем указатель на голову
                    while (temp->next != head) {
                        temp = temp->next; //двигаемся до последнего
                    }
                    temp->next = head->next; // последнему меняем указатель на второй элемент
                    head = head->next; // второй становится первым
                    delete current; // первый удаляется
                }
            }
            else { // если не первый
                previous->next = current->next; // то стандартное удаление 
                delete current;
            }
            return;
        }
        previous = current; // двигаем указатель в цикле
        current = current->next;
    } while (current != head); // пока не пройдем по кругу

    cout << "Element not found" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    string input;

    int n; // кол-во грузов
    cin >> input;
    try { // проверка на входные данные
        size_t pos;
        n = stoi(input, &pos); // преобразуем строку в число
        if (pos < input.size()) {
            throw invalid_argument("Ошибка: Введенная строка не является целым числом.");
            return 0;
        }
    } catch (const invalid_argument& e) { // встроенное исключение в c++
        cerr << "Не может быть словом / символом" << endl; // если это не число, выбрасываем исключение
        return 1;
    } catch (const out_of_range& e) {
        cerr << "Ошибка: Число находится вне диапазона типа int." << endl;
    }
    int m; // номер месяца
    cin >> input;
    try { // проверка на входные данные
        size_t pos;
        m = stoi(input, &pos); // преобразуем строку в число
        if (pos < input.size()) {
            throw invalid_argument("Ошибка: Введенная строка не является целым числом.");
            return 0;
        }
    }
    catch (const invalid_argument& e) { // встроенное исключение в c++
        cerr << "Не может быть словом / символом" << endl; // если это не число, выбрасываем исключение
        return 1;
    }
    catch (const out_of_range& e) { // если число больше инта
        cerr << "Ошибка: Число находится вне диапазона типа int." << endl;
    }
    if (m > 12 || m > n) { // если m не коректный
        cout << "Месяц не может быть больше 12 или количества грузов";
        return 0;
    }
    int k; // переодичность
    cin >> input;
    try { // проверка на входные данные
        size_t pos;
        k = stoi(input, &pos); // преобразуем строку в число
        if (pos < input.size()) {
            throw invalid_argument("Ошибка: Введенная строка не является целым числом.");
            return 0;
        }
    }
    catch (const invalid_argument& e) { // встроенное исключение в c++
        cerr << "Не может быть словом / символом" << endl; // если это не число, выбрасываем исключение
        return 1;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: Число находится вне диапазона типа int." << endl;
    }

    Node* head = new Node(1); // создаем узел, начиная нумеровать
    Node* current = head; // указатель на голову
    for (int i = 2; i <= n; i++) {
        current->next = new Node(i); // добавляем все грузы в список
        current = current->next;
    }
    current->next = head; // циклим список

    current = head; // переходим в начало
    while (current->next != head) { // вывод изначального спика
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;
    // находим элемент месяца
    Node* result = searchElement(head, m); // находим элемент месяца
    Node* tea = result->next; // чтобы проще удалять дальше, элемент на следующий запоминаем

    deleteNode(head, m); // удаляем найденный элемент

    current = head; 
    while (current->next != head) { //вывод элементов после удаления номера месяца
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;

    Node* temp = tea; //еще один вспомогательный указатель
    for (int i = 0; i < (n - 1) / 2; i++) { // цикл с половиной элементов
        temp = tea; 
        int count = 1; // ставим счетчик = 1
        while (count != k) { // проходим, пока не пройдет переодичность K
            temp = temp->next; 
            count++;
        }
        tea = temp->next; // запоминаем указатель на следующий
        deleteNode(head, temp->data); // удаляем элемент, который прошел после переодичности K
    }
    cout << "позиции, чтобы груз не выкинули " << endl;
    current = head; // конечное удаление элемента
    while (current->next != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;
    return 0;
}
