#include<stdio.h>
#include<stdlib.h>

int main()
{
    char file_name[20];
    printf("Enter your file name: ");
    scanf("%s", file_name);
    FILE *f1;
    f1=fopen(file_name,"r");
    if(f1==NULL){
        printf("File doesnt exist");
    }
    else {
        char c=fgetc(f1);
        int line=0;
        int ch=0;
        while(c!=EOF){
                if(c=='\n'){
                    ++line;
                }
                else {
                    ++ch;
                }
                c=fgetc(f1);
        }
        printf("Lines %d Characters %d",line,ch);
        fclose(f1);
        return 0;

    }
    return 0;
}