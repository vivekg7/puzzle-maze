#include <stdio.h>
#include <stdlib.h>

int main()
{
    // compile the c-code 
    system("gcc -o maze create_maze.c");
    // run the c-code which creates data.txt file
    system("./maze");
    // ask which python code to run
    char c;
    printf("\nPress Key 'g' and then Enter for black-n-white output\n");
    printf("Else any Key or Enter for Colored output : ");
    scanf("%c", &c);
    if ( c == 'g' || c == 'G' ) {
        system("python3 show_maze_gray.py < data.txt");
    }
    else {
        system("python3 show_maze_color.py < data.txt");
    }
    return 0;
}
