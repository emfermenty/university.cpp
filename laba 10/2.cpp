//c коровой

#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
    string word;
    cout << "press word: ";
    cin >> word;

    string shuffled_word = word;
    random_device rd;
    mt19937 g(rd());

    int count = 0;
    for (int i = 0; i < shuffled_word.length(); i++) {
        int j = uniform_int_distribution<>(0, word.length() - 1)(g);
        char temp = shuffled_word[i];
        shuffled_word[i] = shuffled_word[j];
        shuffled_word[j] = temp;
    }

    while (shuffled_word != word) {
        for (int i = 0; i < shuffled_word.length(); i++) {
            int j = uniform_int_distribution<>(0, word.length() - 1)(g);
            char temp = shuffled_word[i];
            shuffled_word[i] = shuffled_word[j];
            shuffled_word[j] = temp;
        }
        cout << shuffled_word << endl;
        count++;
    }

    cout << "Общее количество выводов: " << count << endl;

    return 0;
}
