/************************************************************** * Class: CSC-415-0# Spring 2020
* Name: Ibraheem Chaudry    
* Student ID: 917227450
* Project: Assignment 1 – Simple Shell 
* File: main.c
*
* Description: Simple shell that execfutes lunix commands by forking and waiting for child processes 
*
**************************************************************/
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *getInputLine();
char ** getInputArguments(char * inputLine);

int main(int argc, char *argv[]){
    int runStatus;
    char *prompt;
    char * inputLine;
    char ** inputArgs;
   
    //Takes the command line arguments to initalize prompt
    if(argc==2){
    prompt=argv[1];
    }

    //If no prompt set prompt to >
    else{
    prompt=">";
    }

    do{
        //Prints prompt
        printf("%s\n", prompt);


        //Get input line from the user
        inputLine= getInputLine();

        //Break input line into arguments
        inputArgs= getInputArguments(inputLine);

        printf("%s checking null %s",inputArgs[0],inputArgs[2]);
   
    }
    while(runStatus);

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

    args[index] = NULL;
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

