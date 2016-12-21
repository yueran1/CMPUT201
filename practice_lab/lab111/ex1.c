// this code should be compiled with
// g++ -Wall -Wextra -Wconversion -O -pthread ex1.c
// or
// g++ -Wall -Wextra -Wconversion -O ex1.c -lpthread

#include <stdio.h>
#include <pthread.h>

void * thread_func(void * ptr)
{
  const char *msg = (char *)ptr;
  printf("%s\n", msg);

  // return pointer to thread result, can't be pointing to
  // local variable
  return ptr;
}


int main()
{
  pthread_t t1, t2;
  
  const char *msg1 = "I am Thread 1";
  const char *msg2 = "I am Thread 2";

  void *ret1, *ret2;
  
  // Create independent threads each of which will
  // execute thread_func with one parameter
  pthread_create(&t1, 0, thread_func, (void *)msg1);
  pthread_create(&t2, 0, thread_func, (void *)msg2);

  // Wait till threads are complete before main
  // continues. Unless we wait we run the risk of
  // executing an exit which will terminate the
  // process and all threads before the threads
  // have completed. Thread results are stored in
  // ret1 and ret2.
  pthread_join(t1, &ret1);
  pthread_join(t2, &ret2);
  
  printf("Thread 1 returns: %s\n", (char *)ret1);
  printf("Thread 2 returns: %s\n", (char *)ret2);
  
  return 0;
}
