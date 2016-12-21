// this code should be compiled with
// g++ -Wall -Wextra -Wconversion -O -pthread ex2.c
// or
// g++ -Wall -Wextra -Wconversion -O ex2.c -lpthread

#include <stdio.h>
#include <pthread.h>

// global variables
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void * increment(void *)
{
  // locks mutex
  pthread_mutex_lock(&counter_mutex);

  counter++;
  printf("Counter value: %d\n", counter);

  // unlocks mutex
  pthread_mutex_unlock(&counter_mutex);

  return 0;
}


int main()
{
  const int TN = 10; // thread number
  pthread_t threads[TN];

  // create TN threads
  for (int i=0; i < TN; ++i) {
    pthread_create(&threads[i], 0, increment, 0);
  }

  // wait until all threads are complete before
  // main continues
  for (int i=0; i < TN; ++i) {
    pthread_join(threads[i], 0);
  }

  return 0;
}
