#include "../include/line.h"
int main(int argc, char *argv[])
{
    char lines[argc+1][255];
    char cwd[100];
    predealLine(argc, argv, lines);
    if(argc!=2)
    {
		printf("参数数目不正确.\n");
		return 0; 
    }
    if(!chdir(lines[1]))
    {
		printf("当前工作文件夹改变到：");
        if(getcwd(cwd,sizeof(cwd)) != NULL)
	{
		puts(cwd);  
	}
	else
	{
		perror("getcwd");
	}
    }
    else
    {
		perror("chdir"); 
    }
    return 0;
}
