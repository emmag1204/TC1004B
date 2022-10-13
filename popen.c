#include <stdio.h>

int main(){
    FILE * lsOutput;
    FILE * tomayInput;
    char readBuffer[80];
    lsOutput = popen("ls", "r");
    tomayInput = popen("wc - 1 ", "w");
    while (fgets(readBuffer, 80, lsOutput)){
        fputs(readBuffer, tomayInput);
    }
    pclose(lsOutput);
    pclose(tomayInput);
}
