#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
bool big( char a, char b ) { return a > b; }
inline int next( char *str )
{
    for( int i = 1; ; ++i )
        if( str[ i ] != '0' )
            return i;
}

int main()
{
    char num[ 15 ] = { 0 };
    long long int large, small;

    while( scanf( "%s", num ) != EOF )
    {
        int len = strlen( num );
        sort( num, num+len, big );
        large = strtoll( num, NULL, 10 );
        reverse( num, num+len );
        if( *num == '0' )
            swap( num[ 0 ], num[ next( num ) ] );
        small = strtoll( num, NULL, 10 );
        printf( "%lld - %lld = %lld = 9 * %lld\n", large, small, large-small, ( large-small ) / 9 );
    }

    return 0;
}