// this code should be compiled with
// g++ -Wall -Wextra -Wconversion -O -pthread ex3.c
// or
// g++ -Wall -Wextra -Wconversion -O ex3.c -lpthread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

const int NUM_THREADS = 3;
const int NUM_INC = 10;     // how often inc_count increments
const int COUNT_LIMIT = 12; // when to wake up watch_count

int count = 0;

pthread_mutex_t count_mutex;
pthread_cond_t count_cond;


// increment counter a few times
// wake up watch_count thread when reaching COUNT_LIMIT
void * inc_count(void *t)
{
  int my_id = *(int *)t;
  for (int i=0; i < NUM_INC; ++i) {
    
    pthread_mutex_lock(&count_mutex);

    count++;

    // check the value of count and signal waiting thread when
    // condition is reached. This occurs while mutex is locked.
    if (count == COUNT_LIMIT) {
      pthread_cond_signal(&count_cond);
      printf("inc_count: thread %d, count = %d Threshold reached.\n",
             my_id, count);
    }

    printf("inc_count: thread %d, count = %d, unlocking mutex\n",
           my_id, count);

    pthread_mutex_unlock(&count_mutex);

    // do some "work" so threads can alternate on mutex lock
    sleep(1);
  }
  
  return 0;
}


// wait until signalled, then add 125
void * watch_count(void *t)
{
  int my_id = *(int*)t;
  printf("Starting watch_count: thread %d\n", my_id);

  /*
  Lock mutex and wait for signal. pthread_cond_wait will unlock
  mutex while it waits. Also, if COUNT_LIMIT is reached before
  this function is run by the waiting thread, the loop will be
  skipped to prevent pthread_cond_wait from never returning.
  */
  pthread_mutex_lock(&count_mutex);

  while (count < COUNT_LIMIT) {
    pthread_cond_wait(&count_cond, &count_mutex);
    printf("watch_count: thread %d signal received.\n", my_id);
    count += 125;
    printf("watch_count: thread %d count now = %d.\n", my_id, count);
  }

  pthread_mutex_unlock(&count_mutex);

  return 0;
}


// main() function
int main ()
{
  pthread_t threads[NUM_THREADS];
  int ids[NUM_THREADS];

  // initialize mutex and condition variable objects
  pthread_mutex_init(&count_mutex, 0);
  pthread_cond_init(&count_cond, 0);

  // create threads
  
  // watch:  this thread uses watch_count()
  ids[0] = 0;
  pthread_create(&threads[0], 0, watch_count, (void *)&ids[0]);

  // increment:  all other threads use inc_count()
  for (int i=1; i < NUM_THREADS; ++i) {
    ids[i] = i;
    pthread_create(&threads[i], 0, inc_count, (void *)&ids[i]);
  }

  // wait for all threads to complete
  for (int i=0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], 0);
  }
  printf("Main(): Waited on %d threads. Done.\n", NUM_THREADS);

  // clean up and exit
  pthread_mutex_destroy(&count_mutex);
  pthread_cond_destroy(&count_cond);

  return 0;
}
