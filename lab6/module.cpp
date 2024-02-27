#include "header.h"
#include <cmath>

int node(int a, int b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return b;
}
int sokr(int a, int b) {
  a = a / node(a, b);
  return a;
}
int div(int a, int b, int c, int d) {
  a = sokr(a, b) * sokr(d, c);
  return a;
}
int mult(int a, int b, int c, int d) {
  int z;
  z = sokr(a, b) * sokr(c, d);
  return z;
}