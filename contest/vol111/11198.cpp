#include<cstdio>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>
#include<cstdlib>
#define t true
#define f false
using namespace std;
const int power10[ 8 ] = { 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
const bool prime[] = { f, f, t, t, f, t, f, t, f, f, f, t, f, t, f, f };
inline int getdig( int num, int dig ) { return num / power10[ dig ] % 10; }
int cov( int *n )
{
    if( n == NULL )
        return -1;
    int back = 0;
    for( int i = 0; i < 8; ++i )
        back += abs( n[ i ] ) * power10[ i ];
    return back;
}
int* cov( int n, int *array )
{
    for( int i = 0; i < 8; ++i )
        array[ i ] = getdig( n, i );
    return array;
}
bool cant( int *n, bool greater )
{
    for( int i = 1; i < 8; ++i )
        if( n[ i ] > 0 != greater )
            return false;
    return true;
}
int* insert( bool *sign, int *array, int from, int to )
{
    int ins = array[ from ], tmp = 0;
    for( int i = 0; i < 8; ++i )
        if( array[ i ] != ins )
            array[ tmp++ ] = array[ i ];
    for( int i = 7; i > to; --i )
        array[ i ] = array[ i-1 ];
    array[ to ] = ins;
    if( to && prime[ array[ to ] + array[ to-1 ] ] )
        if( sign[ array[ to ] ] ^ sign[ array[ to-1 ] ] )
            return array;
    if( to < 7 && prime[ array[ to ] + array[ to+1 ] ] )
        if( sign[ array[ to ] ] ^ sign[ array[ to+1 ] ] )
            return array;
    return NULL;
}

int main()
{
    int dig[ 9 ] = { 0 }, T = 0;

    while( scanf( "%d", dig ) && *dig )
    {
        int status, cp[ 9 ] = { 0 };
        bool sign[ 9 ] = { false };
        queue<int> perm;
        map<int,int> visited;
        for( int i = 1; i < 8; ++i )
            scanf( "%d", dig+i );
        for( int i = 0; i < 8; ++i )
            sign[ dig[ i ] ] = dig[ i ] > 0;
        status = cov( dig );
        perm.push( status );
        visited[ status ] = 1;

        if( cant( dig, *dig > 0 ) && status != 12345678 )
            printf( "Case %d: -1\n", ++T );
        else
        {
            while( !perm.empty() && perm.front() != 12345678 )
            {
                for( int i = 0; i < 8; ++i )
                    for( int j = 0; j < 8; ++j )
                        if( i != j )
                        {
                            int tmp = cov( insert( sign, cov( perm.front(), cp ), i, j ) );
                            if( tmp == -1 )
                                continue;
                            if( visited[ tmp ] == 0 )
                            {
                                visited[ tmp ] = visited[ perm.front() ]+1;
                                perm.push( tmp );
                            }
                            if( tmp == 12345678 )
                                goto ans;
                        }
                perm.pop();
            }
ans:
            printf( "Case %d: %d\n", ++T, visited[ 12345678 ]-1 );
        }
    }
    return 0;
}
