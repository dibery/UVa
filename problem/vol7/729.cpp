#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    int t, len, one;

    for( scanf( "%d", &t ); t--; )
    {
        char str[ 20 ] = { 0 };
        scanf( "%d %d", &len, &one );
        memset( str, '0', len-one );
        memset( str+len-one, '1', one );
        do
            puts( str );
        while( std::next_permutation( str, str+len ) );
        printf( t? "\n" : "" );
    }
}
