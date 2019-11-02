#include "../include/line.h"
int main(int argc, char**argv){
    
    char lines[argc+1][255];
    predealLine(argc, argv, lines);

    DIR* fd;
    struct dirent* fp;
    struct stat buf;
    char temp[255];

    if(strcmp(lines[1], "")==0){
        strcpy(lines[1], "./");
    }
    else if(lines[1][strlen(lines[1])-1]!='/'){
        strcat(lines[1],"/");
    }
    if((fd=opendir(lines[1]))==NULL){
        perror("fail!");
        exit(0);
    }
    printf("%s 目录\n", lines[1]);
    int file_num=0;
    int dir_num=0;
    long long file_size=0;
    long long dir_size=0;
    while((fp=readdir(fd))!=NULL){
        strcpy(temp, lines[1]);
        strcat(temp, fp->d_name);
        if(stat(temp, &buf)==-1){
            perror("stat");
            exit(0);
        }

        printf("%.12s ",ctime(&buf.st_mtime));
        if(fp->d_type==DT_DIR){
            printf("        <DIR>");
            dir_num++;
            dir_size+=buf.st_size;
        }
        else{
            printf("\t%10ld", buf.st_size);
            file_num++;
            file_size+=buf.st_size;
        }
            
        printf("   %s\n", fp->d_name);

    }
    printf("%12d 个文件 %12lld 字节\n",file_num,file_size);
    printf("%12d 个目录 %12lld 字节\n",dir_num,dir_size);
    return 0;
}
