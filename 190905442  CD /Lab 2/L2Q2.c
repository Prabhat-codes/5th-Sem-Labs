#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fa,*fb;
    int ca,cb;
    int cflag=1;
    fa=fopen("prog.c","r");
    fb=fopen("L2Q1out.c","w");
    if(fa==NULL){
        printf("no input file");
        exit(0);
    }
    ca=getc(fa);
    while(ca!=EOF){
        if(ca=='"'){
            // putc(ca,fb);
            ca=getc(fa);
            while(ca!='"'){
                putc(ca,fb);
                ca=getc(fa);
            }
            putc(ca,fb);
        }
        
        if(ca=='/'){
            ca=getc(fa);
            putc(ca,fb);
            if(ca=='/'){
                putc(ca,fb);
                ca=getc(fa);
                while(ca!='\n'){
                    putc(ca,fb);
                    ca=getc(fa);
                }
                putc(ca,fb);
            }
            if(ca=='*'){
                // putc(ca,fb);
                ca=getc(fa);
                while(ca!='*'){
                    putc(ca,fb);
                    ca=getc(fa);
                }
                putc(ca,fb);
                ca=getc(fa);
                
                ca=getc(fa);
                putc(ca,fb);
            }
        }




        if(ca=='#'){
            while(ca!='\n'){
                ca=getc(fa);
            }
            putc('\n',fb);
        }
        else{
            ca=getc(fa);
            putc(ca,fb);
        }
    }
    fclose(fa);
    fclose(fb);
    return 0;
}