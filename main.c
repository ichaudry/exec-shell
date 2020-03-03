/************************************************************** * Class: CSC-415-0# Spring 2020
* Name: Ibraheem Chaudry
* Student ID: 917227450
* Project: Assignment 1 – Simple Shell
* File: main.c
*
* Description: Simple shell that executes linux commands by forking and waiting for child processes
*
**************************************************************/
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

char *getInputLine();
char ** getInputArguments(char * inputLine);

int main(int argc, char *argv[]){
    char *prompt;
    char * inputLine;
    char ** inputArgs;
    pid_t childPid;
    pid_t terminatePid;
    int childStatus;

    //Takes the command line arguments to initalize prompt
    if(argc==2){
    prompt=argv[1];
    }

    //If no prompt set prompt to >
    else{
    prompt=">";
    }

    while(1){
        //Prints prompt
        printf("%s\n", prompt);


        //Get input line from the user
        inputLine= getInputLine();

        if(inputLine=="exit"){
            printf("Exiting Shell");
            break;
        }


        //Break input line into arguments
        inputArgs= getInputArguments(inputLine);

        printf("these are the arguments in the args list %s , %s , %s",inputArgs[0],inputArgs[1],inputArgs[3]);


        //Forking to run execvp
        childPid=fork();

        if(childPid==0){
            printf("the execvp funciton is being reached and a child process has been created\n");
            execvp(inputArgs[0], inputArgs);

            printf("Unknown command\n");
            exit(0);
        }
        else{
        /*
         * Here the parent is going to wait for the child to terminate
         */
        printf("the waiting else is being reached \n");
        do{
            printf("Parent is now waiting \n");
            terminatePid= wait(&childStatus);

            if(terminatePid!= childPid){
                printf("Killing a child process of id %d", terminatePid);
                kill(terminatePid,SIGKILL);
            }

        }
        while(terminatePid!= childPid);

        free(inputLine);
        free(inputArgs);

        }
    }


    return 0;
}


char *getInputLine()
{
    char *linePtr;
    size_t buffer = 1024;

    //Segmenting buffer and catching errors with allocation
    linePtr = (char *)malloc(buffer * sizeof(char));
    if( linePtr == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    getline(&linePtr, &buffer, stdin);
    return linePtr;
}


  char ** getInputArguments(char * inputLine){
    int bufferSize= 64;
    char **args = malloc(bufferSize * sizeof(char*));
    char * arg;
    int index=0;

    arg = strtok(inputLine, " \0\n");
    while (arg != NULL)
    {
       
        args[index]=arg;
        index++;

        if (index >= bufferSize) {
            bufferSize += bufferSize;
            args = realloc(args, bufferSize * sizeof(char*));
        if (!args) {
            fprintf(stderr, "lsh: allocation error\n");
            exit(EXIT_FAILURE);
        }
     }
        arg = strtok(NULL, " \0\n");
    }

    args[index-1]="\0";
    return args;

    }



    // char *getInputLine()
// {
//     int buffer= 1024;
//     char *linePtr= malloc(sizeof(char)* buffer);
//     char tempChar;
//     int stringIndex=0;

//     //Segmenting buffer and catching errors with allocation
//     if( linePtr == NULL)
//     {
//         perror("Unable to allocate buffer");
//         exit(1);
//     }

//     //Loop gets characters until EOF or until the buufer size is reached
//     while(1){

//         //Read in a character from input
//         tempChar= getchar();

//         //checks if end of file or end of line or buffer size is reached and returns resulting character array
//         if (tempChar == EOF || tempChar == '\n' || stringIndex == buffer)
//         {
//             linePtr[stringIndex] = '\0';
//             return linePtr;
//         }
//         else
//         {
//             linePtr[stringIndex] = tempChar;
//         }
//         stringIndex++;

//     }
// }
