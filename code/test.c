#include <stdio.h>
#include <string.h>

int instructionTypeDetector () {
    FILE *fptr;
    printf("please note that you must name your file 'main.asm' for the program to find it\n");
    fptr = fopen("main.asm", "r");
    if(fptr == NULL) {
        printf("file not found");
        return 1;
    }
    char currentInstruction[100];
    while(fgets(currentInstruction, sizeof(currentInstruction), fptr)) {
        char instructionType[5];
        strncpy(instructionType, currentInstruction, 4);
        instructionType[4] = '\0';
        printf("%s\n", instructionType);        
    }
    fclose(fptr);       
    return 0;
}

int main () {
    return instructionTypeDetector();
}