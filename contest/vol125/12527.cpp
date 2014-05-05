#include<cstdio>
inline bool check( int i )
{
    int exist[ 10 ] = { 0 };
    while( i )
    {
        ++exist[ i % 10 ];
        if( exist[ i % 10 ] == 2 )
            return false;
        i /= 10;
    }
    return true;
}

int main()
{
    int low, high;
    bool not_repeat[ 5001 ];
    for( int i = 1; i <= 5000; ++i )
        not_repeat[ i ] = check( i );

    while( scanf( "%d %d", &low, &high ) != EOF )
    {
        int n = 0;
        for( int i = low; i <= high; ++i )
            if( not_repeat[ i ] )
                ++n;
        printf( "%d\n", n );
    }

	return 0;
}