#include "../include/line.h"
int main(int argc, char* argv[]){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    if(strcmp(lines[0],"MD")==0||strcmp(lines[0],"md")==0){
        for(int i=1;i<argc;i++){
            if(access(lines[i],R_OK)){
                char cm[255]="./";
                strcat(cm, lines[i]);
                mkdir(lines[i],S_IRWXU|S_IRGRP|S_IROTH);
            }
            else{
                printf("%s", lines[0]);
                printf("不能创建文件夹: %s :\n", lines[i]);
                printf("文件已经存在或权限不允许!\n");
            }
        }
    }
    else{
        printf("%s: ", lines[0]);
        printf("error\n");
    }

    return 0;
}
