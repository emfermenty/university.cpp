#include <iostream>
#include "header.h"

using namespace std;

int main()
{
  int a, b, c, d, k, m;
  cin >> a >> b >> c >> d >> k >> m;
  cout << "-----------------------------" << endl;
  cout << "node: " << node(a, b) << endl;
  cout << "-----------------------------" << endl;
  cout << "sokr: \n" << sokr(a, b) << "\n-\n" << sokr(b, a) << "\n" << endl;
  cout << "-----------------------------" << endl;
  cout << "div: \n" << div(a, b, c, d) << "\n-\n" << div(b, a, d, c)  << endl;
  cout << "-----------------------------" << endl;
  cout << "mult: \n" << mult(a, b, c, d) << "\n-\n" << mult(b, a, d, c) << endl;
  cout << "-----------------------------" << endl;
  int chisl = div(a, b, c, d);
  int znam = div(b, a, d, c);
  cout << "final: \n" << div(chisl, znam, k, m) << "\n-\n" << div(znam, chisl, m, k) << endl;
}