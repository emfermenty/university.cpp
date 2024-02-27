#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	int x, k;
	fstream in("d.txt");

	if (!in.is_open()) {
		cout << "ne otkr";
		return 0;
	}

	vector<int> num;

	while (in >> x) {
		num.push_back(x);
	}
	cout << "original vector " << endl;
	for (int i : num) {
		cout << i << " ";
	}
	cout << endl << "press k: ";
	cin >> k;
	

	for (int i = 0; i < num.size(); ) {
		if (num[i] > k) {
			num.erase(num.begin() + i);
		}
		else
			i++;
	}

	cout << "second vector " << endl;
	for (int i : num) {
		cout << i << " ";
	}


	num.clear();
	in.close();
	return 0;
}