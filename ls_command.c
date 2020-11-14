/* Title : program to display information of files and directories in argument/current directory.
   Author : Aman Ojha
   Syntax : ls -l <filename> 
   */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    int pid;
    pid=fork();
    if (pid<0){
        printf("\n Fork failed");
        exit(-1);
    }
    else if (pid==0){
        execlp("/bin/ls","ls","-l",NULL);

    }
    else{
        wait(NULL);
        printf("\n Child complete \n");
        exit(0);
    }
    return 0;
}