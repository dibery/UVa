#include<cstdio>
#include<algorithm>
using namespace std;
inline int abs( int a ) { return a < 0? -a : a; }

int main()
{
    int len;
    char road[ 2000000 ];

    while( scanf( "%d ", &len ) && len )
    {
        int dist = 1e9, last = -1e9, D = -1, R = -1;
        gets( road );
        for( int i = 0; dist && i < len; ++i )
        {
            if( road[ i ] == 'Z' )
                dist = 0;
            if( road[ i ] == 'D' )
                D = i;
            if( road[ i ] == 'R' )
                R = i;
            if( D != -1 && R != -1 )
                dist = min( dist, abs( D-R ) );
        }
        printf( "%d\n", dist );
    }

	return 0;
}