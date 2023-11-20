#include <stdio.h>

int main() {
  char a = 'a';
  char b = 'b';
  char *pa = &a;
  char *pb = &b;
  char c = *pa;
  char *pc = &c;

  printf("a: %d b: %d c: %d pa: %p pb: %p pc: %p *pc: %d\n", a, b, c, pa, pb,
         pc, *pc);
  printf("a: %c b: %c c: %c pa: %p pb: %p pc: %p *pc: %d\n", a, b, c, pa, pb,
         pc, *pc);
  pc = &b;

  printf("a: %d b: %d c: %d pa: %p pb: %p pc: %p *pc: %d\n", a, b, c, pa, pb,
         pc, *pc);

  return 0;
}