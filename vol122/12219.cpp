#include<cstdio>
#include<cctype>
#include<cstring>
#include<map>
using namespace std;
char in[ 300000 ];
int bracket[ 300000 ], place[ 50000 ];
class node
{
public:
    int begin, end, len;
    node( int, int );
    bool operator() ( node, node ) const ;
};
bool node::operator() ( node a, node b ) const
{
    return a.len != b.len? a.len < b.len : strncmp( in+a.begin, in+b.begin, a.len ) < 0;
}
node::node( int b = 0, int e = 0 )
{
    begin = b;
    end = e;
    len = e-b+1;
}
inline int next( int i )
{
    for( ++i; !bracket[ i ] && in[ i ] != ',' && in[ i ] != ')'; ++i );
    if( in[ i ] == ',' || in[ i ] == ')' )
        return i-1;
    return bracket[ i ];
}

int main()
{
    int i, j, test, now;
    map<node, int, node> table;
    scanf( "%d\n", &test );

    while( test-- )
    {
        gets( in );
        table.clear();
        memset( bracket, 0, sizeof( bracket ) );
        i = now = 0;
        for( j = 0; in[ j ]; ++j )
            if( in[ j ] == '(' )
                place[ ++i ] = j;
            else if( in[ j ] == ')' )
                bracket[ place[ i-- ] ] = j;
        if( strchr( in, '(' ) == NULL )
        {
            puts( in );
            continue;
        }

        for( ; in[ i ]; ++i )
            if( isalpha( in[ i ] ) )
            {
                node hold( i, next( i ) );
                if( table.find( hold ) != table.end() )
                {
                    printf( "%d", table.at( hold ) );
                    i += table.find( hold )->first.len - 1;
                }
                else
                {
                    table.insert( pair<node, int>( hold, ++now ) );
                    while( in[ i+1 ] != '(' && in[ i+1 ] != ')' && in[ i+1 ] != ',' )
                        putchar( in[ i++ ] );
                    putchar( in[ i ] );
                }
            }
            else
                putchar( in[ i ] );
        puts( "" );
    }

    return 0;
}
