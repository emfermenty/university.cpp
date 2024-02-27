#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int N, K;
	cout << "press massive: ";
	cin >> N;
	int* x = new int[N];
	int max;
	int kol = 1;
	cout << "press elements: \n";
	max = x[0];
	
	for(int i = 0; i < N; i++) {
		cin >> x[i];
		if(x[i] > max) {
			max = x[i];
			kol = 1;
		} else if (x[i] == max) {
			kol++;
		}
	}
	
	cout << "Max = " << max << endl;
	cout << "kol-vo max elements = " << kol;
	delete[] x;
}