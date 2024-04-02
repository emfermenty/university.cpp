#include <deque>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    list<int> L;
    deque<int> D;

        L.insert(L.begin(), D.begin(), D.begin() + D.size() / 2);

        for (int num : L) {
            std::cout << num << " ";
        }

        return 0;
    }
