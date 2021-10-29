#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *f1,*f2;
    char ch, buffer[1024];
    int i=0;
    f1=fopen("src","r");
    f2=fopen("output.txt","w+");
    if(!f1 || !f2){
        printf("File doesnt exist");
    }
    while(ch!=EOF){
        ch=fgetc(f1);
        if(ch!='\n'){
        buffer[i++]=ch;
        }
    }
    printf("File size: %d",i-1);
    for(int j=i-2;j>=0;j--){
        ch=buffer[j];
        fputc(ch,f2);
    }

}