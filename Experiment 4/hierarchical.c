#include <stdio.h>
#include <conio.h>

struct folder
{
    struct folder *f[5];
    char *files[10];
};

struct folder root;

int main()
{
    fileHandler();
    return 0;
}