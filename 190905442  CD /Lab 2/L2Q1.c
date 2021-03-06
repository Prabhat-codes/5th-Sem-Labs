#include <stdio.h>
#include <stdlib.h>

 

int main()
{
    char c1,c2;
    FILE *f1,*f2;
    f1= fopen("l2q1input.c","r");
    f2= fopen("outputl2q1.c","w");
    if(f1 == NULL || f2 ==NULL)
    {
        printf("Either the input or the output file does not exist \n");
        return 1;
    }
    c1=fgetc(f1);
    while(c1 != EOF)
    {
        if(c1 == '/')
        {
            c2 = getc(f1);
            if(c2 == '/')
            {
                putc(c1,f2);
                putc(c2,f2);
                c1 = getc(f1);
                while(c1 !='\n')
                {
                    putc(c1,f2);
                    c1 = getc(f1);
                }
            }
            else if(c2 == '*')
            {
                putc(c1,f2);
                putc(c2,f2);
                c1 = getc(f1);
                do
                {
                    while(c1 != '*')
                    {
                        putc(c1,f2);
                        c1 = getc(f1);
                    }
                    putc(c1,f2);
                    c1 = getc(f1);
                } while(c1 != '/');
            }
        }
        if(c1 == '"')
        {
            putc(c1,f2);
            c1 = getc(f1);
            while(c1 != '"')
            {
                putc(c1,f2);
                c1 = getc(f1);
            }
            putc(c1,f2);
            c1 = getc(f1);
        }
        if(c1 == ' ' || c1 == '\t')
        {
            putc(' ',f2);
            while(c1 == ' ' || c1 == '\t')
            {
                c1 = getc(f1);
            }
        }
        putc(c1,f2);
        c1 = getc(f1);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}