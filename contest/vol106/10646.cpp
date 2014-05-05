#include<cstdio>
#include<list>
#include<cstring>
using namespace std;
inline int det( char *a ){ return ( *a >= '2' && *a <= '9'? *a-'0' : 10 ); }

int main()
{
    char in[ 200 ];
    int t = 0, test;
    scanf( "%d", &test );

    for( int i = 1; i <= test; ++i )
    {
        list<char*> pile;
        list<char*>::iterator it;
        int y = 0;
        for( int k = 0; k < 27; ++k )
        {
            scanf( "%s", in );
            pile.push_back( strdup( in ) );
        }
        for( int q = 0; q < 3; ++q )
        {
            int x = det( pile.back() );
            y += x;
            for( int m = 11-x; m; --m )
                pile.pop_back();
        }
        for( int k = 0; k < 25; ++k )
        {
            scanf( "%s", in );
            pile.push_back( strdup( in ) );
        }
        for( t = 1, it = pile.begin(); t < y; ++t, ++it );
        printf( "Case %d: %s\n", i, *it );
        pile.clear();
    }

    return 0;
}
