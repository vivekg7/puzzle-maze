#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("gcc -o maze realmaze.c");
    system("./maze | python3 opencvmaze.py");
    return 0;
}
