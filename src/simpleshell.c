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
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#define MAX_BUFFER 1025
#define ARGUMENTS_BUFFER 64
#define DELIMETER " \t\r\n\a"

//Function declarations
char *getInputLine();
char **getArguments(char * inputLine);

int main(int argc, char *argv[]){
    //Prompt to print at each shell stdin line 
    char * prompt;
    
    //This command exits the shell
    char * exitCmd= "exit\n";

    //Takes the command line arguments to initalize prompt
    if(argc==2){
    prompt=argv[1];
    }

    //If no prompt set prompt to >
    else{
    prompt=">";
    }

    while(1)
    {
        //Prints prompt
        printf("%s ", prompt);

        char * inputLine= getInputLine();   

        //If no input report error and get another input
        if(*inputLine == '\n') {
            printf("You did not enter any input. Please try again.\n");
            continue;
        } 

        printf("%s",inputLine);
                
        //if user enters the exit command quit the shell
        if(strcmp(inputLine, exitCmd)==0){
        break;
        }
    
        //Split the input line into arguments using delimiters 
        char ** arguments= getArguments(inputLine);

        //Process id of child
        pid_t pid;

        //Status of child process parent is waiting on
        int status;

        pid = fork();
        
        if (pid == 0) 
        {
            // Child process
            if (execvp(arguments[0], arguments) == -1) {
            perror("lsh");
            }
            exit(EXIT_FAILURE);
        } 
        else if (pid < 0) 
        {
            // Error forking
            perror("lsh");
        } 
        else 
        {
            // Parent process
            wait(&status);
            } 
        //Print ID and exit status of child that finished executing
        printf("Child %d, exited with %d\n",pid,WEXITSTATUS(status));
        
          
        //Free allocated memory
        free(inputLine);
        free(arguments);
    }

return 0;
}

char *getInputLine(){
    //Dynamically allocate the inputline array with the desired buffer size
    char * inputLine=(char *)malloc(MAX_BUFFER * sizeof(char));

    //Catch erros while allocating array
    if(inputLine==NULL)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
     
    //Gets line from standard in and store in inputLine array while cathcing error
    if (fgets(inputLine,1024,stdin)== NULL )
    {
        printf("Error occured while reading input. Input may be too long.");
        exit(EXIT_FAILURE);
    }
         
    return inputLine;  
}


char **getArguments(char * inputLine)
{
    int index = 0;

    //Allocate arguments array on the heap
    char **arguments = malloc(ARGUMENTS_BUFFER* sizeof(char*));

    //Pointer to the tokens of inputline used for strtok splitting function
    char *token;

    if (!arguments) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(inputLine, DELIMETER);
    while (token != NULL) {
        arguments[index] = token;
        index++;
        token = strtok(NULL, DELIMETER);
    }

    //To ensure that the array is null terminated
    arguments[index] = NULL;

    return arguments;
}
