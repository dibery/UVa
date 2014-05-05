#include<cstdio>
bool rep( long long int n )
{
    int has[ 10 ] = { 0 };
    while( n )
    {
        if( has[ n % 10 ] )
            return true;
        ++has[ n % 10 ];
        n /= 10;
    }
    return false;
}

int main()
{
    long long int t, n;
    scanf( "%lld", &t );

    while( t-- )
    {
        scanf( "%lld", &n );
        for( long long int i = 1; i * n <= 9876543210; ++i )
            if( !rep( i ) && !rep( i * n ) )
                printf( "%lld / %lld = %lld\n", i * n, i, n );
        if( t )
            puts( "" );
    }

    return 0;
}