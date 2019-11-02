#include "../include/line.h"
int comp(char* filename1, char*filename2); 

int main(int argc, char **argv)
{
	char lines[argc+1][255];
    predealLine(argc, argv, lines);
    char* filename1 = lines[1];
    char* filename2 = lines[2];
    int flag = comp(filename1, filename2);
	if(!flag) {
		printf("文件的大小不同\n");
	}
	else {
		printf("文件比较无误\n");
	}
	return 0;
}
int comp(char* filename1, char*filename2) 
{
	FILE *file1;
	FILE *file2;
	char ch1, ch2;
	int flag = 1;
	if((file1=fopen(filename1, "r"))==NULL) {
    		printf("文件不能打开");
    		exit(0);
	}
	if((file2=fopen(filename2, "r"))==NULL) {
    		printf("文件不能打开");
    		exit(0);
	}
	printf("比较 %s 和 %s \n", filename1, filename2);
	while((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
    	if(ch1 == ch2)
    		continue;
    	else {
    		flag = 0;
    		break;
    	}
	}
	if( ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) == EOF) || 
	    ((ch1 = fgetc(file1)) == EOF && (ch2 = fgetc(file2)) != EOF) ) {
		flag = 0;
	}
	fclose(file1);
	fclose(file2);
	return flag;
}
