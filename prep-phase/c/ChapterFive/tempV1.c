#include <stdio.h>

int main() {
  int a = 13;
  int b = 22;
  int *pa = &a;
  int *pb = &b;
  int c = *pa;
  int *pc = &c;

  printf("a: %d b: %d c: %d pa: %p pb: %p pc: %p *pc: %d\n", a, b, c, pa, pb,
         pc, *pc);
  pc = &b;

  printf("a: %d b: %d c: %d pa: %p pb: %p pc: %p *pc: %d\n", a, b, c, pa, pb,
         pc, *pc);

  return 0;
}