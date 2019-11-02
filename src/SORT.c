#include "../include/line.h" 
int main(int argc, char** argv) 
{   
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* srcname = lines[1];
    FILE* src = fopen(srcname, "r");
    char fileLine[1024]; 
    int lineCnt = 0;
    while(!feof(src)) {
        fgets(fileLine, 1024, src);
        if(feof(src)) {
            break;
        }
        lineCnt++;
    }
    int i, j;
    rewind(src);
    char fileLineList[lineCnt][1024], temp[1024];
    for(i = 0; i < lineCnt; i++) {
        fgets(fileLine, 1024, src);
        strcpy(fileLineList[i], fileLine);
    }
    for(i = 0; i < lineCnt-1; ++i) {
        for(j = i+1; j < lineCnt; ++j) {
            if(strcmp(fileLineList[i], fileLineList[j])>0) {
                strcpy(temp, fileLineList[i]);
                strcpy(fileLineList[i], fileLineList[j]);
                strcpy(fileLineList[j], temp);
            }
        }
    }
    for(i = 0; i < lineCnt; i++) {
        int len = strlen(fileLineList[i]);
        if(fileLineList[i][len-1] == '\n')
            printf("%s", fileLineList[i]);
        else
            printf("%s\n", fileLineList[i]);
    }

    fclose(src);
    return 0;
}
