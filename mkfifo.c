#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {


    int fd;

    char fifo_path[] = "fifo1";
    mkfifo(fifo_path, 0666);

    int fRet = fork();

    if (fRet < 0) {
        perror("fork");
        exit(1);
    }
    else if (fRet == 0) {


        fd = open(fifo_path, O_WRONLY | S_IWUSR);
        printf("%d\n", fd);
        char buf[] = {"Hello from child!"};
        printf("%s\n", buf);
        write(fd, buf, sizeof(buf));
        close(fd);
        exit(1);

    }
    else {
        wait(NULL);
        fd = open(fifo_path, O_RDONLY | S_IRUSR);
        char buf[1024];
        int size = read(fd, buf, 1000);
        buf[size] = '\0';
        close(fd);
        unlink(fifo_path);
    }

    unlink(fifo_path);

    return 0;
}