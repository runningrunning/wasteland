/* fork, exec, wait, exit */
/* https://mp.weixin.qq.com/s/8pYWaaKaik1UyyUlV7Nemw */
/* How to use fork and pipe */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define CMD_BUF_LENGTH 512
char cmd[CMD_BUF_LENGTH] = {0};

void fork_and_exec(char* cmd, int pin, int pout)
{
    if (fork() == 0)
    {
        if (pin != -1)
        {
            dup2(pin, 0);
            close(pin);
        }

        if (pout != -1)
        {
            dup2(pout, 1);
            close(pout);
        }

        system(cmd);
        exit(0);
    }

    if (pin != -1)
        close(pin);

    if (pout != -1)
        close(pout);
}

int execute_cmd(char* cmd, int in)
{
    int status;
    char* p = cmd;
    int pipefd[2];

    while (*p)
    {
        switch(*p)
        {
        case '|':
            *p++ = 0;
            pipe(pipefd);
            fork_and_exec(cmd, in, pipefd[1]);
            execute_cmd(p, pipefd[0]);
            return 0;
        default:
            p ++;
        }
    }

    fork_and_exec(cmd, in, -1);
    while (waitpid(-1, &status, WNOHANG) != -1);
    return 0;
}

int main(int argc, char** argv)
{
    while (1)
    {
        printf("tiny sh >>");
        gets(cmd);

        if (!strcmp(cmd, "q")) {
            exit(0);
        }

        else
        {
            execute_cmd(cmd, -1);
        }
    }
    return 0;
}

/* int main(int argc, char** argv) */
/* { */
/*     int status; */

/*     if (fork() == 0) */
/*     { */
/*         system("./add 4 | ./add 5"); */
/*         exit(0); */
/*     } */

/*     while (waitpid(-1, &status, WNOHANG) != -1); */
/*     return 0; */
/* } */
