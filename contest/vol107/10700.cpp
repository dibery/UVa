#include<cstdio>
#include<cstdlib>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    int t;

    for( scanf( "%d", &t ); t--; )
    {
        int size = 0, num[ 12 ] = { 0 };
        long long int small = 0, large = 1;
        char op[ 11 ] = { 0 }, verbal[ 3 ] = { 0 };
        list<string> m, M;
        while( scanf( "%d%c", num+size, op+size ) == 2 && op[ size ] != '\n' )
            ++size;
        for( int i = 0; i <= size; ++i )
        {
            sprintf( verbal, "%d", num[ i ] );
            m.push_back( string( verbal ) );
            M.push_back( string( verbal ) );
            if( op[ i ] != '\n' && op[ i ] )
                m.push_back( string( 1, op[ i ] ) ), M.push_back( string( 1, op[ i ] ) );
        }
        while( !m.empty() )
        {
            if( find( m.begin(), m.end(), "*" ) == m.end() )
                for( ; !m.empty(); m.pop_front() )
                    if( m.front() != "+" )
                        small += stoll( m.front() );
            if( !m.empty() )
            {
                list<string>::iterator s = find( m.begin(), m.end(), "*" );
                long long int c = stoll( *prev( s ) ) * stoll( *next( s ) );
                char tmp[ 20 ];
                sprintf( tmp, "%lld", c );
                m.insert( m.erase( prev( s ), next( next( s ) ) ), string( tmp ) );
            }
        }
        while( !M.empty() )
        {
            if( find( M.begin(), M.end(), "+" ) == M.end() )
                for( ; !M.empty(); M.pop_front() )
                    if( M.front() != "*" )
                        large *= stoll( M.front() );
            if( !M.empty() )
            {
                list<string>::iterator s = find( M.begin(), M.end(), "+" );
                long long int c = stoll( *prev( s ) ) + stoll( *next( s ) );
                char tmp[ 20 ];
                sprintf( tmp, "%lld", c );
                M.insert( M.erase( prev( s ), next( next( s ) ) ), string( tmp ) );
            }
        }
        printf( "The maximum and minimum are %lld and %lld.\n", large, small );
    }
}
