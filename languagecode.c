#include <stdio.h>
#include <string.h>

void main() {
    //local variables
    char charvariables[10][10];
    int intvariables[10];

    //full input and the current function
    char input[61], fuction[10];

    //index of the begining of the parameter in the whole input
    int indexoftheparameter=0;
    fgets(input, 60, stdin);
    input[strlen(input)-1] = '\0';

    //here the function received goes to the array "function"
    for(int i = 0; input[i] != '('; i++) {
        fuction[i] = input[i];
        indexoftheparameter++;
    }
    fuction[indexoftheparameter] = '\n';

    //handlig the current function based on the function in the array "function"
    if(strcmp(fuction, "printa")) { //printf abrasileirado
        if(input[indexoftheparameter], input[strlen(input)-2] == '"'){
            for(int i=indexoftheparameter+2; i<strlen(input)-2; i++) {
            printf("%c", input[i]);
            }
        }
        printf("\n");
    }
}
