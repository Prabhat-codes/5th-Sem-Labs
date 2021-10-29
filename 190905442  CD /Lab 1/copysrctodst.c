#include<stdio.h>
#include<stdlib.h>

int main()
{
    char file_name[20];
    printf("Enter your file name: ");
    scanf("%s", file_name);
    FILE *f1,*f2;
    f1=fopen(file_name,"r");
    if(f1==NULL){
        printf("File doesnt exist");
    }
    else {
        printf("File to write in");
        char file_name2[20];
        scanf("%s",file_name2);
        f2=fopen(file_name2,"w+");
        char c=fgetc(f1);
        while(c!=EOF){
                fputc(c,f2);
                c=fgetc(f1);
        }
        printf("Content copied");
        fclose(f1);
        fclose(f2);
        return 0;

    }
    return 0;
}