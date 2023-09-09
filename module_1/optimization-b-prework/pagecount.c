#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <inttypes.h>

#define TEST_LOOPS 10000000


// NOTE: we know that memory_size and page_size are both powers of 2, so one
// divides the other
//

uint64_t pagecount(uint64_t memory_size, uint64_t page_size) {
  uint64_t a = __builtin_ffsl(memory_size);
  uint64_t b = __builtin_ffsl(page_size);
  // see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
  // similar to __builtin_ffs but takes in long
  // both Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
  
  // printf("%llu %llu %llu %llu\n", memory_size, page_size, a, b);
  // printf("%llu, %llu\n\n", memory_size / page_size, 1LLU << (a - b));
  return 1LLU << (a - b); // same as memory_size / page_size
  // 1llu means 1 represented as a unsigned long long.
  // https://stackoverflow.com/questions/58499444/the-meaning-of-1llu-in-c
}

int main (int argc, char** argv) {
  clock_t baseline_start, baseline_end, test_start, test_end;
  // https://en.cppreference.com/w/c/chrono/clock_t
  // represents processer time returned by calling clock
  uint64_t memory_size, page_size;
  double clocks_elapsed, time_elapsed;
  int i, ignore = 0;

  uint64_t msizes[] = {1L << 32, 1L << 40, 1L << 52}; // 2^32 (4 GB), 2^40 (1 TB), 2^52 
  uint64_t psizes[] = {1L << 12, 1L << 16, 1L << 32}; // 2^12 (4 KB), 2^16 (64 KB), 2^32 
  // difference between msize[i] and psizes[i] is 2^20 (1 million) 
  // except where i = 1 which is 2^24 (4 million)

  // printf("msizes[0]:%d\t %" PRId64 "\n", msizes[0], msizes[0]);
  // printf("msizes[1]:%d\t %" PRId64 "\n", msizes[1], msizes[1]);
  // printf("msizes[2]:%d\t %" PRId64 "\n", msizes[2], msizes[2]);
  // printf("psizes[0]:%d\t %" PRId64 "\n", psizes[0], psizes[0]);
  // printf("psizes[1]:%d\t %" PRId64 "\n", psizes[1], psizes[1]);
  // printf("psizes[2]:%d\t %" PRId64 "\n", psizes[2], psizes[2]);
  // printf("pagecount of index 0:%d\t %" PRId64 "\n", pagecount(msizes[0], psizes[0]), pagecount(msizes[0], psizes[0]));
  // printf("pagecount of index 1:%d\t %" PRId64 "\n", pagecount(msizes[1], psizes[1]), pagecount(msizes[1], psizes[1]));
  // printf("pagecount of index 2:%d\t %" PRId64 "\n\n\n", pagecount(msizes[2], psizes[2]), pagecount(msizes[2], psizes[2]));

  /*
  msizes[0]:0      4294967296
  msizes[1]:0      1099511627776
  msizes[2]:0      4503599627370496
  psizes[0]:4096   4096
  psizes[1]:65536  65536
  psizes[2]:0      4294967296
  pagecount of index 0:1048576     1048576      2^20 
  pagecount of index 1:16777216    16777216     2^24 
  pagecount of index 2:1048576     1048576      2^20 
  */

  baseline_start = clock();
  for (i = 0; i < TEST_LOOPS; i++) {
    memory_size = msizes[i % 3];
    page_size = psizes[i % 3];
    // printf("baseline before: %d\n", ignore);
    // printf("adding 1, msizes[%d], and psizes[%d]: %d\n", i % 3, i % 3, 1 + memory_size + page_size);
    ignore += 1 + memory_size +
              page_size; // so that this loop isn't just optimized away
    // printf("baseline after: %d\n", ignore);
    // ignore ends up reaching close to 2^31 before becoming negative aka overflowing
    // then swaps back and forth between positive and negative
  }
  baseline_end = clock();

  test_start = clock();
  for (i = 0; i < TEST_LOOPS; i++) {
    memory_size = msizes[i % 3];
    page_size = psizes[i % 3];
    // printf("test before: %d\n", ignore);
    // printf("adding 1, msizes[%d], and psizes[%d]: %d\n", i % 3, i % 3, 1 + memory_size + page_size);
    ignore += pagecount(memory_size, page_size) + memory_size + page_size;
    // printf("test after: %d\n", ignore);
  }
  test_end = clock();

  clocks_elapsed = test_end - test_start - (baseline_end - baseline_start);
  time_elapsed = clocks_elapsed / CLOCKS_PER_SEC;

  printf("%.2fs to run %d tests (%.2fns per test)\n", time_elapsed, TEST_LOOPS,
         time_elapsed * 1e9 / TEST_LOOPS);
  return ignore;
}

