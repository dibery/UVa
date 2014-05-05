#include<cstdio>
#include<cstring>
#include<algorithm>
struct node
{
    int times, letter;
};
bool cmp( node a, node b )
{
    return ( a.times == b.times? a.letter > b.letter : a.times < b.times );
}

int main()
{
    node count[ 128 ];
    char in[ 1000 ];
    bool start = false;

    while( gets( in ) )
    {
        for( int i = 0; i < 128; ++i )
        {
            count[ i ].letter = i;
            count[ i ].times = 0;
        }
        if( start )
            puts( "" );
        start = true;
        for( int i = strlen( in )-1; i >= 0; --i )
            ++count[ in[ i ] ].times;
        std::stable_sort( count, count+128, cmp );
        for( int i = 0; i <= 127 /*&& count[ i ].times*/; ++i )
            if( count[ i ].times )
                printf( "%d %d\n", count[ i ].letter, count[ i ].times );
    }

    return 0;
}
