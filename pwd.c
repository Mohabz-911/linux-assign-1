#include <unistd.h>
#define MAX_STR_LENGTH (__INT_MAX__ - 1)

int get_string_length(char * str)
{
    char * ptr = str;
    int length = 0;

    while(*ptr != '\0')
    {
        length++;
        ptr++;
        if(length > MAX_STR_LENGTH) return -1;
    }

    return length;
}

void main(void)
{
    char * dir_name;
    int dir_length;
    
    dir_name = getcwd((void*)0, 0);
    dir_length = get_string_length(dir_name);

    write(STDOUT_FILENO, dir_name, dir_length);
    write(STDOUT_FILENO, "\n", 1);
}