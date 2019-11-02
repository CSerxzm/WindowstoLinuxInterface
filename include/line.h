#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <unistd.h>
#include <fcntl.h>  
#include <dirent.h>
#include <time.h>
int predealLine(int argc, char* argv[], char (*lines)[255]){
    int real_len=0;
    for(int j=0;j<strlen(argv[0]);j++){
        if(isalpha(argv[0][j])||isdigit(argv[0][j]))
            lines[0][real_len++]=tolower(argv[0][j]);
    }
    lines[0][real_len]='\0';
    for(int i=1;i<argc;i++){
        //printf("%s ", argv[i]);
        real_len=0;
        for(int j=0;j<strlen(argv[i]);j++){
            lines[i][real_len++]=argv[i][j];
        }
        lines[i][real_len]='\0';
        //printf("%s ", lines[i]);
    }
    return 0;
}
