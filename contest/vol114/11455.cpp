#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int test, len[ 4 ];
    scanf( "%d", &test );

    while( test-- )
    {
        scanf( "%d %d %d %d", len, len+1, len+2, len+3 );
        sort( len, len+4 );
        if( len[ 0 ] == len[ 1 ] && len[ 2 ] == len[ 3 ] )
            puts( len[ 1 ] == len[ 2 ]? "square" : "rectangle" );
        else
            puts( len[ 0 ]+len[ 1 ]+len[ 2 ] > len[ 3 ]? "quadrangle" : "banana" );
    }

	return 0;
}