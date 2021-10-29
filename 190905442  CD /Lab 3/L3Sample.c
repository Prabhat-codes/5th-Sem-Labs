#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fa,*fb;
    fa=fopen("inp.c","r");
    fb=fopen("output.c","w");
    char ca,cb,buf[10];
    ca=getc(fa);
    cb=getc(fb);
    if(!fa||!fb){
        printf("File doesnt exist");
        exit(0);
    }
    while(ca!=EOF){
        if(ca=='='){
            cb=getc(fa);
            if(cb=='='){
                printf("Relational operator: %c%c\n",ca,cb);
            }
            else{
                printf("Assignment operator: %c\n",ca);
            }
        }
        else if(ca=='>'){
            cb=getc(fa);
            if(cb=='='){
                printf("Relational operator: %c%c\n",ca,cb);
            }
            else{
                printf("Relational operator: %c\n",ca);
            }
        }
        else if(ca=='<'){
            cb=getc(fa);
            if(cb=='='){
                printf("Relational operator: %c%c\n",ca,cb);
            }
            else if(cb=='>'){
                printf("Inequality operator: %c%c\n",ca,cb);
            }
            else{
                printf("Relational operator: %c\n",ca);
            }

        }
       
        ca=getc(fa);
        }

}