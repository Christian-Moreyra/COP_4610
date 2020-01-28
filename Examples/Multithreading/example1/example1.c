#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;
 
/* thread function */
void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
 
  printf("hello from thr_func, thread id: %d\n", data->tid);
 
  pthread_exit(NULL);
}

boolean isNumber(char[16] s) {
  for (int i = 0; i < s.length(); i++) 
    if (isdigit(s[i]) == false) 
      return false; 
  
  return true;
}

int doSomething(int threads) {
  printf(stderr, "Sorry, %d is not a number.\n", input);
  pthread_t thr[NUM_THREADS];
  int i, rc;
  /* create a thread_data_t argument array */
  thread_data_t thr_data[NUM_THREADS];

  /* create threads */
  for (i = 0; i < NUM_THREADS; ++i) {
    thr_data[i].tid = i;
    if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  /* block until all threads complete */
  for (i = 0; i < NUM_THREADS; ++i) {
    pthread_join(thr[i], NULL);
  }
}
 
int main(int argc, char **argv) {
  int NUM_THREADS;
  char [16] input;
  sscanf(argv[0], "%s", &input);
  if (isNumber(input)) {
    NUM_THREADS = input;
    doSomething(NUM_THREADS);
  } 
  else
    printf(stderr, "Sorry, %d is not a number.\n", input);

return 0;
}
