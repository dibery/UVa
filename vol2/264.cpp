#include<cstdio>
#include<cmath>

int main()
{
    int n;
    while( scanf( "%d", &n ) != EOF )
    {
        int sum = ceil( ( sqrt( 1 + 8*n ) - 1 ) / 2 ) + 1, full = sum * ( sum - 1 ) / 2;
        if( sum % 2 )
            printf( "TERM %d IS %d/%d\n", n, n - ( sum - 1 ) * ( sum - 2 ) / 2, full - n + 1 );
        else
            printf( "TERM %d IS %d/%d\n", n, full - n + 1, n - ( sum - 1 ) * ( sum - 2 ) / 2 );
    }

    return 0;
}