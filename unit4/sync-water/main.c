#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/*Shared variables*/
int moleculas_H; //number of hydrogen molecules
int moleculas_O; //number of oxygen molecules
int moleculas_W; //number of water molecules

pthread_t *worker_H; 
pthread_t *worker_O;
pthread_t worker_W;

void *hidrogens(void * args) {
  printf("I'm an Hidrogen's thread.\n");
  return (void *) 0;
}

void *oxygens(void * args) {
  printf("I'm an Oxygen's thread.\n");
  return (void *) 0;
}

void * water(void * args) {
  printf("I'm an Water's thread.\n");
  return (void *) 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    perror("Use: ./main numHidrog numOxig");
    return 0;
  }

  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  worker_H = malloc(N * sizeof(pthread_t));
  worker_O = malloc(M * sizeof(pthread_t));
  
  for (int i=0; i < N; i++)
    pthread_create(&worker_H[i], NULL, hidrogens, NULL);
  
  for (int i=0; i < M; i++)
    pthread_create(&worker_O[i], NULL, oxygens, NULL);

  pthread_create(&worker_W, NULL, water, NULL);

  int val;
  for (int i=0; i < N; i++) 
    pthread_join(worker_H[i],(void *) &val);
  for (int i=0; i < M; i++) 
    pthread_join(worker_O[i],(void *) &val);

  pthread_join(worker_W,(void *) &val);

  return 0;
}
