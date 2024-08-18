#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 100000

int main(int argc, char ** argv)
{
    int i;
    int og_fd, copy_fd;
    char buffer[MAX_BUF];
    int read_count;
    if(argc != 3){
        printf("ERROR: Incorrect number of arguments\nUse: cp file1 file2\n");
        return -1;
    }

    // Open the original file and the copy file
    og_fd = open(argv[1], O_RDONLY);
    if(og_fd == -1){
        printf("ERROR: File \"%s\" does not exist\n", argv[1]);
        return -1;
    }
    copy_fd = open(argv[2], O_CREAT|O_WRONLY, S_IRWXU);

    // Copy the content
    while(1){
        read_count = read(og_fd, buffer, MAX_BUF);

        if(read_count == -1){
            printf("ERROR: Reading from file \"%s\" failed\n", argv[1]);
            return -1;
        }
        
        if(read_count == 0) // reached EOF
            break;
        
        write(copy_fd, buffer, read_count);
    }

    // Remove the original file
    remove(argv[1]);

    printf("Moved file: \"%s\" into file: \"%s\" successfuly\n", argv[1], argv[2]);
    return 0;
}