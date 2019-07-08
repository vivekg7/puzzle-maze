#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("gcc -o maze create_maze.c");
    system("./maze");
    system("python3 show_maze_color.py < data.txt");
    return 0;
}
