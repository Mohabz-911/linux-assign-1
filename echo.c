#include <unistd.h>

int main(int argc, char ** argv)
{
    char * word_ptr;
    int i = 1;
    int size_counter;

    for(; i < argc; i++){
        size_counter = 0;
        word_ptr = argv[i];
        while(*word_ptr != '\0'){
            size_counter++;
            word_ptr++;
        }
        write(STDOUT_FILENO, argv[i], size_counter);
        write(STDOUT_FILENO, " ", 1);
    }
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}