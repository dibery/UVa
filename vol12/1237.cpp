#include<cstdio>
using namespace std;
struct node
{
    char name[ 21 ];
    int min, max;
} people[ 10000 ];

int main()
{
    int test, data, query, in;
    scanf( "%d", &test );

    while( test-- )
    {
        scanf( "%d", &data );
        for( int i = 0; i < data; ++i )
            scanf( "%s %d %d", people[ i ].name, &people[ i ].min, &people[ i ].max );
        scanf( "%d", &query );
        for( int i = 0; i < query; ++i )
        {
            int found = 0, target;
            scanf( "%d", &in );
            for( int k = 0; k < data; ++k )
                if( in <= people[ k ].max && in >= people[ k ].min )
                {
                    ++found;
                    target = k;
                }
            puts( found == 1? people[ target ].name : "UNDETERMINED" );
        }
        if( test )
            puts( "" );
    }

    return 0;
}
