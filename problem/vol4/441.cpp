#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int size, n[ 13 ];
    scanf( "%d", &size );
    for( int i = 0; i < size; ++i )
        scanf( "%d", n+i );
    sort( n, n+size );
    for( int a = 0; a < size; ++a )
        for( int b = a+1; b < size; ++b )
            for( int c = b+1; c < size; ++c )
                for( int d = c+1; d < size; ++d )
                    for( int e = d+1; e < size; ++e )
                        for( int f = e+1; f < size; ++f )
                            printf( "%d %d %d %d %d %d\n", n[ a ], n[ b ], n[ c ], n[ d ], n[ e ], n[ f ] );
    while( scanf( "%d", &size ) && size )
    {
        puts( "" );
        for( int i = 0; i < size; ++i )
            scanf( "%d", n+i );
        sort( n, n+size );
        for( int a = 0; a < size; ++a )
            for( int b = a+1; b < size; ++b )
                for( int c = b+1; c < size; ++c )
                    for( int d = c+1; d < size; ++d )
                        for( int e = d+1; e < size; ++e )
                            for( int f = e+1; f < size; ++f )
                                printf( "%d %d %d %d %d %d\n", n[ a ], n[ b ], n[ c ], n[ d ], n[ e ], n[ f ] );
    }

    return 0;
}
