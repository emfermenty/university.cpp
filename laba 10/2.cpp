//c коровой

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string word;
    cout << "press word: ";
    cin >> word;

    string shuffled_word = word;
    srand(time(0));

    int count = 1;
    for (int i = 0; i < shuffled_word.length(); i++) {
        int j = rand() % shuffled_word.length(); 
        char temp = shuffled_word[i];  
        shuffled_word[i] = shuffled_word[j]; 
        shuffled_word[j] = temp;
    }

    while (shuffled_word != word) { 
        for (int i = 0; i < shuffled_word.length(); i++) {
            int j = rand() % shuffled_word.length();
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