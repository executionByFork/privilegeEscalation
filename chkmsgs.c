#include <stdlib.h>
#include <unistd.h>

int main() {
    setuid(0);
    system("cat ./msgs.txt");
}
