#include "../include/line.h"

int del_file(const char *dir){
    DIR* dirp;
    struct dirent *dp;
    struct stat dir_stat;
    char dir_name[255];

    if(access(dir,F_OK)!=0){
        return 0;
    }
    if(stat(dir, &dir_stat)<0){
        perror("失败!\n");
        return -1;
    } 
    if(S_ISREG(dir_stat.st_mode)){
        remove(dir);
    }
    else{
        perror("error!\n");
    }

    return 0;
}

int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    if((strcmp("DEL",lines[0])==0)||(strcmp("del",lines[0])==0)){
        for(int i=1;i<argc;i++){
            del_file(lines[i]);
        }
    }
    else{
        perror("error after lines\n");
    }
    return 0;
}
