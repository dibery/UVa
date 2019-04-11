#include<cstdio>
#include<list>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int student, tmp[ 5 ];
    char trans[ 16 ] = { 0 };

    while( scanf( "%d", &student ) && student )
    {
        int M = 0, win = 0;
        list<long long int>all;
        map<long long int,int>popularity;

        for( int s = 0; s < student; ++s )
        {
            for( int i = 0; i < 5; ++i )
                scanf( "%d", tmp+i );
            sort( tmp, tmp+5 );
            sprintf( trans, "%d%d%d%d%d", tmp[ 0 ], tmp[ 1 ], tmp[ 2 ], tmp[ 3 ], tmp[ 4 ] );
            ++popularity[ strtoll( trans, NULL, 10 ) ];
            all.push_back( strtoll( trans, NULL, 10 ) );
        }
        all.sort();
        all.unique();
        for( list<long long int>::iterator it = all.begin(); it != all.end(); ++it )
            if( popularity[ *it ] == M )
                win += popularity[ *it ];
            else if( popularity[ *it ] > M )
                win = popularity[ *it ], M = popularity[ *it ];
        printf( "%d\n", win );
    }

    return 0;
}