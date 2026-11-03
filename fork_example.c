#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("자식 프로세스: PID=%d, 부모 PID=%d\n", getpid(), getppid());
    } else {
        wait(NULL);
        printf("부모 프로세스: PID=%d, 자식 PID=%d\n", getpid(), pid);
    }
    return 0;
}