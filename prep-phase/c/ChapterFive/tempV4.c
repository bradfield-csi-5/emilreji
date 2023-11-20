#include <stdio.h>

void wrongSwap(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void correctSwap(int *x, int *y) {
  printf("xval: %d yval: %d x: %p y: %p\n", *x, *y, x, y);
  int temp = *x;
  *x = *y;
  *y = temp;
  printf("xval: %d yval: %d x: %p y: %p\n", *x, *y, x, y);
}

int main() {
  int a = 1;
  int b = 2;
  int *pa = &a;
  int *pb = &b;

  printf("a: %d b: %d pa: %p pb: %p\n", a, b, pa, pb);
  wrongSwap(a, b);
  printf("a: %d b: %d pa: %p pb: %p\n", a, b, pa, pb);
  correctSwap(pa, pb);
  printf("a: %d b: %d pa: %p pb: %p\n", a, b, pa, pb);

  return 0;
}