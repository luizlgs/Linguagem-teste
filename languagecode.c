
#include <stdio.h>
#include <string.h>

//op

void error_message() {
    printf("Syntax error\n");
}

int countcurrentline(FILE *file) { //get the numeber of characters in the current line of code
    int count=0;
    char ch = fgetc(file);
    switch (ch) {
    case 10: //verifica se é uma linha vazia ou o final do arquivo
        return 0;
        break;
    case EOF:
        return ch;
    default:
        break;
    }

    while(ch != EOF) {
        if(ch != 10) {
            count++;
        }
        else {
            break;
        }
        ch = fgetc(file);
    }
    return count;
}


void main() {
    FILE *code = fopen("code", "r");

    //full input and the current function
    while(1) {
        long int initialposition =  ftell(code); //save the position of the beginning of the line
        int inputsize = countcurrentline(code);
        fseek(code, initialposition, SEEK_SET); //code points to the beginning again
        if(inputsize==EOF) {
            break;
        }
        else if(inputsize == 0) {fgetc(code); continue;} //check if the line is empty
        char input[inputsize+1], function[10];

        //index of the begining of the parameter in the whole input
        int indexoftheparameter=0;
        fgets(input, inputsize+1, code);
        //input[strlen(input)-1] = '\0';

        if(!(input[strlen(input)-1]==')') || inputsize == 0){error_message(); break;} //verify if there's a ")" at the end of the input
        //here the function received goes to the array "function"
        for(int i = 0; input[i] != '('; i++) {
            function[i] = input[i];
            indexoftheparameter++;
            if(i==inputsize-1) { //verify if the input is bigger than the maximun size
                error_message();
                return;
            }
        }
        function[indexoftheparameter] = '\0';

        //handlig the current function based on the funcprinytion in the array "function"
        if(strcmp(function, "printa") == 0) { //printf abrasileirado
            if(input[indexoftheparameter], input[strlen(input)-2] == '"'){
                for(int i=indexoftheparameter+2; i<strlen(input)-2; i++) {
                printf("%c", input[i]);
                }
            }
            else{
                error_message();
                break;
            }
            printf("\n");
        }else if(strcmp(function, "exit") == 0) {
            break;
        }
        else {
            printf("Non existent function\n");
        }

        if(fgetc(code) == EOF) { //get the '\n" at the end of the line and end if it's the end of the file
            break;
        }
        continue;
    }
    fclose(code);
}
