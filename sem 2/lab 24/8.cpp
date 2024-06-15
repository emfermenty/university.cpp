#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Money{
private:
    unsigned int rubles;
    short int kopeks;
public:
    Money(){
        rubles = 0;
        kopeks = 0;
    }

    Money(unsigned int r, short int k){
        rubles = r;
        kopeks = k;
    }
    
    Money(const Money &m){
        rubles = m.rubles;
        kopeks = m.kopeks;
    }

    void setrubles(unsigned int r){
        rubles = r;
    }
    unsigned int getrubles(){
        return rubles;
    }
    void setkopeks(short int k){
        kopeks = k;
    }
    short int getkopeks(){
        return kopeks;
    }

    Money operator-(const Money& other) {
        int totalKopeks = rubles * 100 + kopeks;
        int otherTotalKopeks = other.rubles * 100 + other.kopeks;
        int resultKopeks = totalKopeks - otherTotalKopeks;

        if (resultKopeks < 0) {
            cout << "не может быть отрицательным ";
            return Money(0, 0);
        }

        unsigned int resultRubles = resultKopeks / 100;
        short int resultRemainingKopeks = resultKopeks % 100;

        return Money(resultRubles, resultRemainingKopeks);
    }
    
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << m.rubles << " рублей " << m.kopeks << " копеек";
        return os;
    }
};

int main(){
    Money money1(5, 25);
    Money money2(10, 50);
    Money result = money1 - money2;
    cout << "Result: " << result; 
}
