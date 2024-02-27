#include <iostream>
#include <string>

using namespace std;

using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
            if (s[i] == ' '){
                i++;
            }
        }
    }
    cout << s;
}