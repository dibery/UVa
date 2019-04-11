#include<cstdio>
#include<algorithm>
using namespace std;
inline bool later( int *seq, int src, int cmp ) { return find( seq, seq+25, src ) > find( seq, seq+25, cmp ); }

int main()
{
    int n, bef[ 25 ], aft[ 25 ];

    while( scanf( "%d", &n ) != EOF )
    {
        int inv = 0;
        for( int i = 0; i < n; ++i )
            scanf( "%d", bef+i );
        for( int i = 0; i < n; ++i )
            scanf( "%d", aft+i );
        for( int i = 0; i < n-1; ++i )
            for( int j = i+1; j < n; ++j )
                inv += later( bef, aft[ i ], aft[ j ] );
        printf( "%d\n", inv );
    }
}
