#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
void main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        return;
    }
 
    char new_path[100]="q1l3.c";
    struct stat start;
    int tmp1 = stat(argv[1],&start);
    printf("Number of hard links:%ld\n", start.st_nlink);
    system("ls");
    printf("Linking..\n");
    int tmp2 = link(argv[1],new_path);
    struct stat intermediate;
    int tmp3 = stat(argv[1],&intermediate);
    printf("Number of hard links:%ld\n", intermediate.st_nlink);
    printf("New path:%s\n",new_path);
    system("ls");
    int tmp4 = unlink(argv[1]);
    struct stat ending;
    int tmp5 = stat(new_path,&ending);
    printf("Unlinking...\n");
    printf("Number of hard links after unlinking:%ld\n", ending.st_nlink);
    system("ls");
}
