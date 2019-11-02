#include "../include/line.h"
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* srcname = lines[1];
    char* dstname = lines[2];
    if((strcmp("move",lines[0])==0)) {
        if(rename(srcname, dstname)<0){
            perror("Rename error!\n");
        }
    }
    else {
        perror("sytax error\n");
    }
    return 0;
}
