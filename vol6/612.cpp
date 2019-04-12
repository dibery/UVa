#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
class node
{
public:
    node();
    char dna[ 51 ], dna_cp[ 51 ];
    int inv;
} *data = NULL;
node::node()
{
    for( int i = 0; i <= 50; ++i )
        dna[ i ] = 0;
    inv = 0;
}
bool cmp( node a, node b ) { return a.inv < b.inv; }

int main()
{
    int size, test, len;
    scanf( "%d", &test );

    while( test-- )
    {
        scanf( "%d %d", &len, &size );
        data = new node [ size ];
        for( int i = 0; i < size; ++i )
        {
            scanf( "%s",data[ i ].dna );
            for( int k = 0; k < len; ++k )
                for( int j = k+1; j < len; ++j )
                    if( data[ i ].dna[ k ] > data[ i ].dna[ j ] )
                        ++data[ i ].inv;
        }
        stable_sort( data, data+size, cmp );
        for( int i = 0; i < size; ++i )
            printf( "%s\n", data[ i ].dna, data[ i ].inv );
        if( test )
            puts( "" );
        delete[] data;
    }

    return 0;
}
