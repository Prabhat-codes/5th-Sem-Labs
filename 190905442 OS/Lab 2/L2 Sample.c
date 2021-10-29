#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void printdir(char *dir, int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if((dp=opendir(dir))==NULL){
        fprintf(stderr,"cannot open director %s \n",dir);
        return;
    }

    chdir(dir);
    
    while((entry=readdir(dp))!=NULL){
        printf("%s\n",entry->d_name);
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name)==0){
                continue;
            }
        
        printf("%*s%s\n",depth,"",entry->d_name);
        printdir(entry->d_name,depth+4);
        }
        else{
            printf("%*s%s\n",depth,"",entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}

int main(){
    // printf("Enter directory to check");
    printdir("/home/Student/Desktop/Check",0);
}