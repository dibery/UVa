#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int dragon, knight, pay, head[ 20000 ], kill[ 20000 ], d, k;
    char no[ 10 ];

    while( scanf( "%d %d", &dragon, &knight ) && dragon )
    {
        if( dragon > knight )
        {
            for( int i = dragon+knight; i; --i )
                scanf( "%*d" );
            printf( "Loowater is doomed!\n" );
            continue;
        }
        d = k = pay = 0;
        for( int i = 0; i < dragon; ++i )
            scanf( "%d", head+i );
        for( int i = 0; i < knight; ++i )
            scanf( "%d", kill+i );
        sort( head, head+dragon );
        sort( kill, kill+knight );
        while( dragon-d <= knight-k && d != dragon )
            if( kill[ k ] >= head[ d ] )
            {
                pay += kill[ k ];
                ++k;
                ++d;
            }
            else
                ++k;
        if( d != dragon )
            printf( "Loowater is doomed!\n" );
        else
            printf( "%d\n", pay );
    }

    return 0;
}
