#include <stdio.h>

int up, down, r;

void  CompFraction(int up, int down)
{
    printf( "[%d;", (int) up/down );
    r = up % down;
    up = down;
    down = r; //output integer

    while( r != 1 && r != 0 )
    {
        printf( "%d,", (int) up/down );
        r = up % down;
        up = down;
        down = r;
    }
    if( r == 0)
        printf( "]\n");
    else
        printf( "%d]\n", up);   //last one
}

int main(void)
{
    while( scanf( "%d %d", &up, &down ) != EOF)
        CompFraction( up, down);

    return 0;
}
