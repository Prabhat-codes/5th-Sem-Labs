#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h> 
#include <grp.h>

int main(int argc, char *argv[]){
    struct stat file;
    int r_val=lstat(argv[1],&file);
    if(r_val==-1){
        printf("ERROR");
        exit(1);
    }
    printf("Stat for File Name:  %s\n",argv[1]);
    printf("Inode number: %ld\nFile size: %d\n",file.st_ino,file.st_size);
    printf("Blocks: %d\n",file.st_blocks);
    printf("Number of hard links: %d\n",file.st_nlink);
    printf("Inode: %d\n",file.st_ino);
    printf("GID: %d\n",file.st_gid);
    printf("UID: %d\n",file.st_uid);
    printf("Mode: %lo\n",file.st_mode);
    printf("Last access time: %s", ctime(&file.st_atime)); 
    printf("Last modified time: %s", ctime(&file.st_mtime));
    printf("Last status change time: %s", ctime(&file.st_ctime));
    printf("Block size: %d\n",file.st_blksize);
}