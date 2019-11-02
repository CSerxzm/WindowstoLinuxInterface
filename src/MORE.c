#include "../include/line.h" 
#define PAGELEN 24  
#define LINELEN 514  
void do_more(FILE *);  
int see_more(FILE *);  
int main(int ac, char *av[])  { 
    FILE *fp;  
    if(ac==1)  
      do_more(stdin);  
    else  {  
        while(--ac)  
          if( (fp = fopen(* ++av, "r")) != NULL)  {  
              do_more(fp);  
              fclose(fp);  
          }  
          else  
            exit(1);  
    }  
    return 0;  
}  
void do_more(FILE *fp)  {  
    char line[LINELEN];  
    int reply;  
    int number_line = 0;  
    FILE *fp_tty;  
    fp_tty = fopen("/dev/tty", "r");
    if(fp_tty == NULL)  
      exit(1);  
    while(fgets(line, LINELEN, fp) != NULL)  {  
        if(number_line == PAGELEN)  {  
            reply = see_more(fp_tty);  
            if(reply == 0)   
              break;  
            number_line -= reply;  
        }  
        if( fputs(line, stdout) == EOF)  
          exit(1);  
        number_line ++;  
    }  
}  
  
int see_more(FILE *cmd)  {  
    int c;    
    while( (c = getc(cmd)) != EOF ) {  
        if(c == 'q')  
          return 0;  
        if(c == ' ')  
          return PAGELEN; 
        if(c == '\n')  
          return 1;
    }  
    return 0;  
}  
