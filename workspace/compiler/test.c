#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fd;
    int size = 1024;
    char *src = malloc(size);

    while (argc-- > 1)
        printf("%s\n", *++argv);

    if ((fd=fopen(*argv, "r")) == NULL) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if ((fread(src, size-1, 1, fd)) <=0 ) {
        printf("read() returned\n");
        return -1;
    }

    fclose(fd);

    printf("%s\n", src);

    return 0;
}
