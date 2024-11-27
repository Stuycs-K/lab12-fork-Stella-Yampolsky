#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p, b;

  p = fork();
  if (p < 0) {
      perror("fork fail");
      exit(1);
    } 
    else if (p == 0) {
      printf("%d ", getpid());
      srand(getpid());
      int x = rand() % 5 + 1;
      printf("%d seconds\n", x);
      sleep(x);
      printf("%d finished after %d seconds\n", getpid(), x);
      exit(x);
  }

  b = fork();
  if (b < 0) {
    perror("fork fail");
    exit(1);
  } 
  else if (b == 0) {
    printf("%d ", getpid());
    srand(getpid());
    int x = rand() % 5 + 1;
    printf("%d seconds\n", x);
    sleep(x);
    printf("%d finished after %d seconds\n", getpid(), x);
    exit(x);
  }

  int status;
  pid_t finished = wait(&status);
  if (WIFEXITED(status)) {
    int sleep_time = WEXITSTATUS(status);
    printf("Main Process %d is done. Child %d slept for %d seconds\n", getpid(), finished, sleep_time);
  }
  return 0;
}
