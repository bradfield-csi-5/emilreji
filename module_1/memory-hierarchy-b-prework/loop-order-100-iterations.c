  /*

Two different ways to loop over an array of arrays.

Spotted at:
http://stackoverflow.com/questions/9936132/why-does-the-order-of-the-loops-affect-performance-when-iterating-over-a-2d-arra

*/
#include <stdio.h>
#include <time.h>

void option_one() {
  int i, j;
  static int x[4000][4000];
  for (i = 0; i < 4000; i++) {
    for (j = 0; j < 4000; j++) {
      x[i][j] = i + j;
    }
  }
} 
// 0,0-> 0,1 -> ... -> 0,3999 -> 1,0-> 1,1 -> ... -> 1,3999
// inner loop iterates over same sub array so it should be faster

void option_two() {
  int i, j;
  static int x[4000][4000];
  for (i = 0; i < 4000; i++) {
    for (j = 0; j < 4000; j++) {
      x[j][i] = i + j;
    }
  }
}
// 0,0-> 1,0 -> ... -> 3999,0 -> 0,1-> 1,1 -> ... -> 3999,1
// inner loop iterates over different sub arrays so it should be slower

int main() {
  int times = 100;
  float totalTime = 0;
  float avgTimeElapsed;
  for(int i = 0; i < times; i++) {
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    option_one();
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    // fmt.printf("option 1 timeElapsed: %d", timeElapsed);
    totalTime += timeElapsed;
  }
  printf("option 1 total timeElapsed for %d iterations: %.10f\n", times, totalTime);
  avgTimeElapsed = totalTime/times;
  printf("option 1 avg timeElapsed: %.10f\n", avgTimeElapsed);

  // option_two
  totalTime = 0;
  for(int i = 0; i < times; i++) {
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    option_two();
    float endTime = (float)clock()/CLOCKS_PER_SEC;
    float timeElapsed = endTime - startTime;
    // fmt.printf("option 1 timeElapsed: %d", timeElapsed);
    totalTime += timeElapsed;
  }
  printf("option 2 total timeElapsed for %d iterations: %.10f\n", times, totalTime);
  avgTimeElapsed = totalTime/times;
  printf("option 2 avg timeElapsed: %.10f\n", avgTimeElapsed);
  // option_two();
  return 0;
}
