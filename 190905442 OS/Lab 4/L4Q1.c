#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct stat file;
    int r_val=lstat(argv[1],&file);
    if(r_val==-1){
        printf("ERROR");
        exit(1);
    }
    printf("Inode number: %ld File size: %d\n",file.st_ino,file.st_size);
}