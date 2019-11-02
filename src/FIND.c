#include "../include/line.h"
int main(int argc, char** argv)
{
	char lines[argc+1][255];
    predealLine(argc, argv, lines);
   	char* filename = lines[1];
    char* findstr = lines[2];
   	char fileline[1024]; 
   	int linecnt = 1;
   	FILE *src = fopen(filename, "r");
   	while(!feof(src)) {
   		fgets(fileline, 1024, src);
   		if(feof(src)) {
			break;
		}
   		if(strstr(fileline, findstr) != NULL) {
   			printf("[%d]%s", linecnt, fileline);
   		}
   		linecnt++;
   	}
   	printf("\n");
	return 0;
}
