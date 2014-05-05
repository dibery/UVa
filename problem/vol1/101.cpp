#include<cstdio>
#include<list>
#include<cstring>
using namespace std;

int main()
{
    int size, a, b, pile[ 25 ];
    char command[ 5 ], command2[ 5 ];
    while( scanf( "%d", &size ) != EOF )
    {
        list<int> block[ size ];
        list<int>::iterator A, B;
        for( int i = 0; i < size; ++i )
            pile[ i ] = i;
        for( int i = 0; i < size; ++i )
            block[ i ].push_back( i );

        while( scanf( "%s", command ) && strcmp( command, "quit" ) )
        {
            scanf( "%d %s %d", &a, command2, &b );
            if( a == b || pile[ a ] == pile[ b ] )
                continue;
            for( A = block[ pile[ a ] ].begin(); *A != a; ++A );
            for( B = block[ pile[ b ] ].begin(); *B != b; ++B );
            ++A;
            ++B;
            if( !strcmp( command, "move" ) )
            {
                for( list<int>::iterator it = A; it != block[ pile[ a ] ].end(); ++it )
                {
                    pile[ *it ] = *it;
                    block[ *it ].push_back( *it );
                }
                if( !strcmp( command2, "onto" ) )
                {
                    for( list<int>::iterator it = B; it != block[ pile[ b ] ].end(); ++it )
                    {
                        pile[ *it ] = *it;
                        block[ *it ].push_back( *it );
                    }
                    block[ pile[ b ] ].erase( B, block[ pile[ b ] ].end() );
                }
                block[ pile[ a ] ].erase( --A, block[ pile[ a ] ].end() );
                block[ pile[ b ] ].push_back( a );
                pile[ a ] = pile[ b ];
            }
            else
            {
                if( !strcmp( command2, "onto" ) )
                {
                    for( list<int>::iterator it = B; it != block[ pile[ b ] ].end(); ++it )
                    {
                        pile[ *it ] = *it;
                        block[ *it ].push_back( *it );
                    }
                    block[ pile[ b ] ].erase( B, block[ pile[ b ] ].end() );
                }
                block[ pile[ b ] ].push_back( a );
                for( list<int>::iterator it = A; it != block[ pile[ a ] ].end(); ++it )
                {
                    pile[ *it ] = pile[ b ];
                    block[ pile[ b ] ].push_back( *it );
                }
                block[ pile[ a ] ].erase( --A, block[ pile[ a ] ].end() );
                pile[ a ] = pile[ b ];
            }
        }
        for( int i = 0; i < size; ++i )
        {
            printf( "%d:", i );
            for( list<int>::iterator it = block[ i ].begin(); it != block[ i ].end(); ++it )
                printf( " %d", *it );
            puts( "" );
        }
    }

    return 0;
}
