#include "../include/line.h"
int main(int argc, char** argv){
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    if((strcmp("ren",lines[0])==0)||(strcmp("rename",lines[0])==0)){
        struct stat dir_stat;
        if((access(lines[1],F_OK)!=0)){
            perror("Don't exist DIR1\n");
            return 0;
        }
        else if(stat(lines[1], &dir_stat)<0){
            perror("Stat error!\n");
            return 0;
        }
        else if(rename(lines[1],lines[2])<0){
            perror("Rename error!\n");
        }
		else{
			printf("rename %s to %s \n",lines[1],lines[2]);
		}
    }
    else{
        perror("error after lines\n");
    }

    return 0;
}