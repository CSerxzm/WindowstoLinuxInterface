#include "../include/line.h"
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* srcname = lines[1];
    char* dstname = lines[2];
    char option[5];
    FILE *src, *dst;
	
	if(access(srcname, F_OK)==-1) {
		printf("源文件不存在\n");
		return 0;
    }
    if(!access(dstname, F_OK)) {
        while(1) {
            printf("覆盖 %s 吗?(Yes/No/All):", dstname);
            scanf("%s", option);
            if(strcmp("No", option) == 0) {
                printf("已复制 0 个文件\n");
                return 0;
            } 
            else if(strcmp("Yes", option) == 0) {
                break;
            }
        }
    }
    src = fopen(srcname, "rb");
    dst = fopen(dstname, "wb");
    int bufferLen = 1024;
    int readCount = 0;
    char *buffer = (char*)malloc(bufferLen);
    while((readCount=fread(buffer, 1, bufferLen, src)) > 0) {
        fwrite(buffer, readCount, 1, dst);
    }
    printf("已复制 1 个文件\n");
    free(buffer);
    fclose(src);
    fclose(dst);
    return 0;
}
