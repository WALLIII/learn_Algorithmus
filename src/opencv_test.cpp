#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    int count = 0;
    pid = fork();   //fork一个进程，返回子进程的进程号
    if(pid == 0)
    {               //pid为0,
        printf("this is child process, pid is %d\n",getpid());//getpid返回的是当前进程的PID
        count+=2;
        printf("count = %d\n",count);
    }
    else if(pid > 0)
    {
        printf("this is father process, pid is %d\n",getpid());
        count++;
        printf("count = %d\n",count);
    }
    else
    {
        fprintf(stderr,"ERROR:fork() failed!\n");
    }
    return 0;
}

// int main()
// {
//     pid_t pid[3];
//     int count = 0;
//     pid[0] = fork();
//     pid[1] = fork();
//     pid[2] = fork();

//     printf("this is process\n");

//     return 0;
// }