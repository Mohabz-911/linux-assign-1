#include <unistd.h>
#define MAX_STR_LENGTH 1000

int get_string_length(char * str)
{
    char * ptr = str;
    int length = 0;

    if(ptr == NULL) return -1;

    while(*ptr != '\0')
    {
        length++;
        ptr++;
        if(length > MAX_STR_LENGTH) return -1;
    }

    return length;
}

int main(void)
{
    char * dir_name;
    int dir_length, write_check;
    
    dir_name = getcwd(NULL, 0);
    if(dir_name == NULL)
    {
        write(STDOUT_FILENO, "ERROR: Couldn't get current directory name\n", 44);
        return 0;
    }

    dir_length = get_string_length(dir_name);
    if(dir_length == -1)
    {
        write(STDOUT_FILENO, "ERROR: Directory name too long\n", 32);
        return 0;
    }

    write_check = write(STDOUT_FILENO, dir_name, dir_length);
    if(write_check == -1)
    {
        write(STDERR_FILENO, "STDOUT ERROR: Failed to write output\n", 38);
        return 0;
    }
    write_check = write(STDOUT_FILENO, "\n", 1);
    if(write_check == -1)
    {
        write(STDERR_FILENO, "STDOUT ERROR: Failed to write output\n", 38);
        return 0;
    }

    return 0;
}