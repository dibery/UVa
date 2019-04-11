#include<stdio.h>
int thelength( int start );

int main()
{
    int i, j, length, max = 0, counter, hold;

    while( scanf( "%d %d", &i, &j ) != EOF )
    {
        printf( "%d %d", i, j );
        if( i > j )
        {
            hold = i;
            i = j;
            j = hold;
        }

        for( counter = i; counter <= j; counter++ )
        {
            length = thelength( counter );
            if( length > max )
                max = length;
        }
        printf( " %d\n", max+1 );
        max = 0;
    }
    return 0;
}

int thelength( int start )
{
    int length = 0;

    while( start != 1 )
    {
        if( start % 2 == 0 )
            start /= 2;
        else
            start = 3 * start + 1;
        length++;
    }
    return length;
}