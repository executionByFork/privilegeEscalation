#include <stdio.h>

int main(int argc, char** argv) {
    int c;
    FILE *file;
    file = fopen(argv[1], "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}
