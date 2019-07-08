#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("gcc -o maze create_maze.c");
    system("./maze | python3 show_maze_color.py");
    return 0;
}
