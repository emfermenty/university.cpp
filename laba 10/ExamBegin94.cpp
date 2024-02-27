//На вход подается текстовая строка, содержащая набор слов, набранных заглавными латинскими буквами
// и разделенных ровно одним пробелом.
// Найти количество слов, начинающихся и оканчивающихся одной и той же буквой.

#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  cout << "Enter a string: ";
  getline(cin, input);

  int count = 0;
  string word = "";

  for (int i = 0; i < input[i]; i++) {
    input[i] = tolower(input[i]);
  }

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ' ') {  // если встречается пробел, проводим проверку
      if (word.length() > 1 && word[0] == word[word.length() - 1]) {
        count++;
      }
      word = ""; // и обнулям переменную до след пробела
    } else {   //записываем по букве в переменную
      word += input[i];
    }
  }

  if (word.length() > 1 && word[0] == word[word.length() - 1]) {  //так как в конце строки пробел не ставится, проверка на последнее слово
    count++;
  }

  cout << "kol-vo slov, where first symbol and last symbol equal: " << count << endl;

  return 0;
}