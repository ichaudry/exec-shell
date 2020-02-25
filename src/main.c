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


int main(int argc, char **argv){
    int condition=1;

    //Loop to run the shell until an error is thrown 
    do{
        printf("> ");
    }
    while(condition);



    return 0; 
}