#include<cstdio>
#include<algorithm>
inline bool isupper( char a )
{
    return ( a <= 'Z' && a >= 'A' );
}
inline bool islower( char a )
{
    return ( a <= 'z' && a >= 'a' );
}
struct node
{
    int times;
    char letter;
};
bool cmp( node a, node b )
{
    return ( a.times > b.times );
}

int main()
{
    node count[ 26 ];
    char in;
    for( int i = 0; i < 26; ++i )
    {
        count[ i ].letter = 'A'+i;
        count[ i ].times = 0;
    }

    while( scanf( "%c", &in ) == 1 )
        if( isupper( in ) )
            ++count[ in-'A' ].times;
        else if( islower( in ) )
            ++count[ in-'a' ].times;
    std::stable_sort( count, count+26, cmp );
    for( int i = 0; i < 26 && count[ i ].times; ++i )
        printf( "%c %d\n", count[ i ].letter, count[ i ].times );

    return 0;
}
