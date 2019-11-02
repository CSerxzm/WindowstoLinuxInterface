#include "../include/line.h"
int mycplink(char *name1, char *name2)
{
    char buf[1024]="";
    int ret;
    ret=readlink(name1, buf, sizeof(buf));
    if(ret!=0)
    {
        symlink(buf , name2 );
    }
    return 0;
}

int mycp(char *dir1, char *dir2)
{
    int fd1;
    int fd2;
    int ret;
    int sts;
    char buf[1024];
    fd1=open(dir1, O_RDONLY);
    fd2=open(dir2, O_WRONLY|O_CREAT|O_TRUNC, 0666);
    while(1)
    {
        bzero(buf, sizeof(buf));
        ret= read(fd1, buf, sizeof(buf)-1 );
        if(ret<=0)
            break;
        sts=write(fd2, buf, ret);
        while(sts<ret)
        {
            sts+=write(fd2, buf+sts, ret-sts);
         }
    }
    close(fd1);
    close(fd2);
    struct stat info;
    ret=stat(dir1, &info);
    if(ret!=0)
    {
        perror("stat");
        return 1;
    }
    chmod(dir2, info.st_mode);
    return 0;
}
int mycpdir(char *name1, char *name2)
{
    int ret;
    DIR *dir1;
    DIR *dir2;
    struct dirent *drr;
    struct stat info;
    struct stat dirinfo;
    char buf1[1024];
    char buf2[1024];
    lstat(name1, &info);
    dir1=opendir(name1);
    if(dir1==NULL)
    {
        perror("opendir1");
        return 1;
    }
    dir2=opendir(name2); 
    if(dir2==NULL)
    {
        mkdir(name2, info.st_mode);
        dir2=opendir(name2);
    }

    while(1)
    {
        bzero(buf2, sizeof(buf2));
        bzero(buf2, sizeof(buf2));
        drr=readdir(dir1);
        if(drr==NULL)break;
        if(*drr->d_name=='.')
            continue;
        sprintf(buf1, "%s/%s", name1, drr->d_name);
        sprintf(buf2, "%s/%s", name2, drr->d_name);
        ret=lstat(buf1, &dirinfo);
        if(ret<0)
        {
            perror("lstat\n");
            break;
        }
        if(S_ISDIR(dirinfo.st_mode))
        {
            mycpdir(buf1 , buf2);
        }
        else if(S_ISREG(dirinfo.st_mode))
        {
            mycp(buf1, buf2);
        }
        else if(S_ISLNK(dirinfo.st_mode))
        {
            mycplink(buf1, buf2);
        }
    }
	closedir(dir1);
    closedir(dir2);
    return 0;
}
int main(int argc, char **argv)
{
    char lines[argc+1][255];
    predealLine(argc, argv, lines);
    mycpdir(lines[1], lines[2]);
    return 0;
}
