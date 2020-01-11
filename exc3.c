#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

  
void fork_next(int depth) 
{   
    if (depth < 10) 
    {
        if (fork() == 0)
        {
            printf("I'am %d my parent is %d  and my depth is %d\n", getpid(), getppid(), depth);
            fork_next(++depth);
        }
        else wait(NULL);
    }
}

int main() 
{ 
    fork_next(0); 
}
