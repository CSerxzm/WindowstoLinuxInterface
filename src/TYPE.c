#include "../include/line.h"
void copy_file(FILE *file1, FILE* file2){
    int c;
    while((c=getc(file1))!=EOF){
        putc(c,file2);
    }
}
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    struct stat dir_stat;
    if(access(lines[1], F_OK)==0){
        if(stat(lines[1], &dir_stat)>=0){
            if(S_ISREG(dir_stat.st_mode)){
                FILE *fp=fopen(lines[1],"r");
                copy_file(fp,stdout);
            }
            else{
                perror("Not reg\n");
            }
        }
        else{
            perror("stat error!\n");
        }
    }
    else{
        perror("Don't exist\n");
    }

    return 0;
}
