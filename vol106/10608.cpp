#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    int t, people, edge, a, b;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d", &people, &edge );
        list<int>link[ people ];
        unsigned int ans = 0;
        for( int i = 0; i < edge; ++i )
        {
            scanf( "%d %d", &a, &b );
            link[ a - 1 ].push_back( b - 1 );
            link[ b - 1 ].push_back( a - 1 );
        }
        for( int i = 0; i < people; ++i )
            for( list<int>::iterator it = link[ i ].begin(); it != link[ i ].end(); ++it )
                while( !link[ *it ].empty() )
                {
                    if( link[ *it ].front() != i )
                        link[ i ].push_back( link[ *it ].front() );
                    link[ *it ].pop_front();
                }
        for( int i = 0; i < people; ++i )
            link[ i ].sort();
        for( int i = 0; i < people; ++i )
            link[ i ].unique();
        for( int i = 0; i < people; ++i )
            if( link[ i ].size() > ans )
                ans = link[ i ].size();
        printf( "%d\n", ans+1 );
    }

	return 0;
}