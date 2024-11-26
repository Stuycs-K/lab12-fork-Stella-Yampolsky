#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  printf("%d about to create 2 child processes", getpid());
  pid_t p;
  pid_t b;
  p = fork();
  if(p<0){
    perror("fork fail");
    exit(1)
  }
  else if(p > 0){
    b = fork();
    wait(WIFEXITED(int* status));
    printf("Main Process %d is done, child ")
  }
  else if(p == ){
    printf("PID: %d\n", getpid());
    srand(getpid());
    int x = rand() % 5 + 1;
    printf("random number: %d\n", x);
    sleep(x);
    print("%d finished after %d seconds", getpid(), x);
    exit();
 }
}
