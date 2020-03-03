#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> //header file for wait
#include <sys/types.h> //header file for type
#include <unistd.h> //header file for fork.
#include <string.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char line[BUFFER_SIZE];
    char *ptr;
    char *args[32];


    //search up if execvp is similar to execlp : ex:execlp("./bin/ls", "ls", NULL) Lecture02 -pg 29
    //Need to truncate input if more than 1024.
    //search up: Null terminator and implement EOF
    //List of websites I used for building this program:
    //https://stackoverflow.com/questions/37741349/c-delete-last-character-in-string

    while (1){
        int count = 0; /* make sure args begins at 0 again. Otherwise, each command will be stored next to each other.
                          which messes with the next command not registering */
        const char delim[] = " \n";
        printf("prompt$ ");
        fgets(line, BUFFER_SIZE, stdin); //take in user input
        line[strlen(line)-1] = (char) NULL; //if the input completely fits the buffer the last character will be \n. using strlen(line)-1 to delete it.
        int i;
        for(i = 0; i < 32; i++) {
            args[i] = malloc(sizeof(line));
        }

        ptr = strtok(line," "); //string token is used to break up user's input with the separator being white space.

        while(ptr!= NULL)
        {
            strcpy(args[count++],ptr);
            ptr = strtok(NULL,delim);

        }
        if(strcasecmp(args[0], "exit") == 0){ //case insensitive for comparing exit with EXIT.
            printf("Exiting Simple Shell... \n");
            exit(EXIT_SUCCESS);
        }
        args[count] = NULL;

        fclose((FILE *) line); //close input stream and clean up to avoid any resource leaks.

        pid_t pid = fork();

        if(pid == 0) { //child process

            execvp(args[0],args);
            perror("execvp failed to execute. Exiting Simple Shell..\n"); //this code only executes if execvp fails to execute. Otherwise, this line is ignored.
            return pid;
        }
        else //parent process
        {
            int status;
            waitpid(pid, &status, 0); //waiting for child to finish execute
            if( WIFEXITED(status)){
                printf("Child PID:  %d with return value %d\n", pid, WEXITSTATUS(status)); //WEXITSTATUS returns the value of the child exit status.

                //kill(pid, SIGTERM); //kill the pid
            }
        }
        free(args[0]);//free up the first position of the array. Which is the command argument.
    }