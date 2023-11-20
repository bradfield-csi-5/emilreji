#include <stdio.h>

int main() {
  int arr[10] = {1, 2, 3, 4};
  int *pArr = arr;
  int firstVal = arr[0];
  int *pFirstVal = &arr[0];
  int secVal = arr[1];
  int *pSecVal = pFirstVal + 1;
  int thirdVal = *(arr + 2);
  int *pthirdVal = arr + 2;

  printf("arr: %p firstVal: %d secVal: %d thirdVal: %d\n", arr, firstVal,
         secVal, thirdVal);
  printf("pArr: %p pFirstVal: %p pSecVal: %p pthirdVal: %p\n", pArr, pFirstVal,
         pSecVal, pthirdVal);
  printf("pArr == pFirstVal: %d\n", pArr == pFirstVal);

  // arr += 1; // Invalid operands to binary expression ('int[10]' and 'int')
  // doesn't work since array name can't be  assigned to or incremented even
  // though pointers can; thats main difference between array name and pointer
  pthirdVal += 1;
  printf("arr: %p firstVal: %d secVal: %d thirdVal: %d\n", arr, firstVal,
         secVal, thirdVal);
  printf("pArr: %p pFirstVal: %p pSecVal: %p pthirdVal: %p\n", pArr, pFirstVal,
         pSecVal, pthirdVal);

  return 0;
}