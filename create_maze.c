#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// sx = columns && sy = rows
// please don't put these values less than 10
int sx, sy; // size of full grid

int **mat; // all corner points
_Bool **path; // all center points
int *cp; // all checkpoints

int **a; // in helpme, coordinates of all possible ways

int ncp; //no. of checkpoints

int vkg = 0; // while creating, my current location

void printmaze();

void make();

_Bool incomplete();

int helpme( int );

void createmaze();

int main()
{
    while ( 1 ) {
        printf("\nEnter number of rows : \n");
        scanf("%d", &sy);
        if ( sy < 10 ) {
            printf("Please Enter a Value greater than 10\n");
            continue;
        }
        printf("\nEnter number of columns : \n");
        scanf("%d", &sx);
        if ( sy < 10 ) {
            printf("Please Enter a Value greater than 10\n");
            printf("Try Again\n");
            continue;
        }
        break;
    }
    srand(time(0));
    mat = (int**)malloc( sx * sizeof(int*) );
    for ( int i=0; i<sx; i++ ) {
        mat[i] = (int*)malloc( sy * sizeof(int) );
    }
    path = (_Bool**)malloc( (sx-1)* sizeof(_Bool*) );
    for ( int i=0; i<sx-1; i++ ) {
        path[i] = (_Bool*)calloc( sy-1, sizeof(_Bool) );
    }
    cp = (int*)malloc( (sx-1)*(sy-1) * sizeof(int) );
    // for helpme function
        a = (int**)malloc( 3 * sizeof(int*) );
        for (int i=0; i<3; i++) {
            a[i] = (int*)malloc( 2 * sizeof(int) );
        }
    make();
    while ( incomplete() ) {
        createmaze();
    }
    // print result for now
    printmaze();
    printf("%d\n%d\n", sy, sx);
    for ( int i=0; i<sy; i++ ) {
        for ( int j=0; j<sx; j++ ) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    // Free all allocated memory
    for ( int i=0; i<sx; i++ ) {
        free( mat[i] );
    }
    free( mat );
    for ( int i=0; i<sx-1; i++ ) {
        free( path[i] );
    }
    free( path );
    free( cp );
    for ( int i=0; i<3; i++ ) {
        free(a[i]);
    }
    free(a);
    return 0;
}

// print maze to file data.txt
void printmaze() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    fprintf(fp, "%d\n", sy);
    fprintf(fp, "%d\n", sx);
    for ( int i=0; i<sy; i++ ) {
        for ( int j=0; j<sx; j++ ) {
            fprintf(fp, "%d ", mat[j][i]);
        }
        fprintf(fp, "%s", " \n");
    }
}

// start with a very closed plane
void make() {
    for (int i=0; i<sx; i++) {
        for (int j=0; j<sy; j++) {
            mat[i][j] = 3;
        }
    }
    mat[0][0] = 1;
}

// true if any pathpoint is false
_Bool incomplete(){
    for (int i=0; i<sx-5; i++) {
        for (int j=0; j<sy-5; j++) {
            if(!path[i][j])
                return true;
        }
    }
    return false;
}

// hard way to create something
void createmaze(){
    int togo;
    path[vkg%(sx-1)][vkg/(sx-1)] = true;
    togo = helpme(vkg);
    if ( togo > 0 ) {
        vkg = togo;
    }
    else {
        for ( int i=ncp-1; i>=0;i-- ) {
            togo = helpme(cp[i]);
            if ( togo > 0 ) {
                vkg = cp[i];
                ncp = i;
                break;
            }
        }
    }
}


// The backbone of createmaze
// does everything
int helpme( int boy ) {
    int x = boy%(sx-1), y = boy/(sx-1); // get x & y co-ordinates
    int t = 0; // No. of ways
    int z; // one of the possible ways
    // int **a contains coordinates of all possible ways
    if ( y-1 >= 0 ) {
        if ( !path[x][y-1] ) {
            a[t][0] = x;
            a[t][1] = y-1;
            t++;
        }
    }
    if ( y+1 < sy-1 ) {
        if ( !path[x][y+1] ) {
            a[t][0] = x;
            a[t][1] = y+1;
            t++;
        }
    }
    if ( x-1 >= 0 ) {
        if ( !path[x-1][y] ) {
            a[t][0] = x-1;
            a[t][1] = y;
            t++;
        }
    }
    if ( x+1 < sx-1 ) {
        if ( !path[x+1][y] ) {
            a[t][0] = x+1;
            a[t][1] = y;
            t++;
        }
    }
    if ( t==0 ) {
        return 0;
    }
    else {
        if ( t > 1 ) {
            cp[ncp] = y*(sx-1) + x;
            ncp++;
        }
        z = rand()%t;
        // printf("%d %d %d %d\n", a[z][0], a[z][1], x, y);
        if ( a[z][0] > x ) {
            if ( mat[a[z][0]][y]==3 )
                mat[a[z][0]][y] = 1;
            if ( mat[a[z][0]][y]==2 )
                mat[a[z][0]][y] = 0;
        }
        if ( a[z][0] < x ) {
            if ( mat[x][y]==3 )
                mat[x][y] = 1;
            if ( mat[x][y]==2 )
                mat[x][y] = 0;
        }
        if ( a[z][1] > y ) {
            if ( mat[x][a[z][1]]==3 )
                mat[x][a[z][1]] = 2;
            if ( mat[x][a[z][1]]==1 )
                mat[x][a[z][1]] = 0;
        }
        if ( a[z][1] < y ) {
            if ( mat[x][y]==3 )
                mat[x][y] = 2;
            if ( mat[x][y]==1 )
                mat[x][y] = 0;
        }
        return a[z][1]*(sx-1) + a[z][0];
    }
}
