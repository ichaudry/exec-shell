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

#define MAX_BUFFER 1024

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
    
int main(int argc, char *argv[]){
    char * prompt;
    char * exitPrompt= "exit\n";


    //Takes the command line arguments to initalize prompt
    if(argc==2){
    prompt=argv[1];
    }

    //If no prompt set prompt to >
    else{
    prompt=">";
    }


    while(1){
        //Dynamically allocate the inputline array with the desired buffer size
        char * inputLine=(char *)malloc(MAX_BUFFER * sizeof(char));

        //
        char ** arguments= lsh_split_line(inputLine);




        //Catch erros while allocating array
        if(inputLine==NULL){
            printf("An error occured while allocating array");
            return(-1);
        }

        //Prints prompt 
        printf("%s", prompt);


        //Gets line from standard in and store in inputLine array while cathcing error
        if ( fgets(inputLine,1024,stdin)== NULL )
            {
                printf("Error occured while reading input. Input may be too long.");
            }
        else
            {       
                //Input line print test
                printf("%s", inputLine);

                inputLine[strlen(inputLine-1)]=(char)NULL; 

                 //Input line print test
                printf("%s", inputLine);
                
                //if user enters the exit command quit the shell
                if(strcmp(inputLine, exitPrompt)==0){
                printf("Exiting Shell");
                break;
            }
   
            
          


             //Forking to run execvp
            pid_t childPid=fork();
            

            if(childPid==0){
            printf("Child process created through successful fork");
            execvp(arguments[0], arguments);

            printf("Unknown command\n");

            exit(0);
            }

        else{
        /*
         * Here the parent is going to wait for the child to terminate
         */
        printf("fork not succsefful");

        int childStatus;
       
        waitpid(childPid, &childStatus, 0); 
            
        if (WIFEXITED(childStatus) ) 
            { 
            int exit_status = WEXITSTATUS(childStatus);         
            printf("Exit status of the child was %d\n", exit_status); 
            } 


        }
       
        
        free(inputLine);
        free(arguments);


    }
}

return 0;
}



// int index=0;

            // // //Dynamically allocate the arguments array to store individual tokens
            // char * tempArguments;

            // //Get the first token 
            // tempArguments = strtok(inputLine, " \0\n");
   
            // //Get the rest of the tokens
            // while( tempArguments != NULL ) {
            // printf( " %s\n", tempArguments );
    
            // tempArguments = strtok(NULL, " ");
            // index++;
            //     }

            // char * arguments=malloc(strlen(inputLine));
            // strcpy(arguments, tempArguments);
            // strcat(arguments,"\0");

            


            //Dynamically allocate the arguments array to store individual tokens
            // char ** arguments=getInputArguments(inputLine);

            // for(int i=0; i<strlen(inputLine);i++){
            //     printf("Value: %s",arguments[i]);
            // }   


            //Add null terminator after the last argument 
            // arguments[index]=NULL;

            // printf("this is the length of the arguments array %d", strlen(arguments));