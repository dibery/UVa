#include<cstdio>
#include<algorithm>
using namespace std;
struct man
{
    int y, m, d;
    char name[ 15 ];
} array[ 100 ];
bool cmp( man a, man b )
{
    if( a.y != b.y )
        return a.y > b.y;
    if( a.m != b.m )
        return a.m > b.m;
    return a.d > b.d;
}

int main()
{
    int in;

    while( scanf( "%d", &in ) != EOF )
    {
        for( int i = 0; i < in; ++i )
            scanf( "%s %d %d %d", array[ i ].name, &array[ i ].d, &array[ i ].m, &array[ i ].y );
        sort( array, array+in, cmp );
        puts( array->name );
        puts( array[ in-1 ].name );
    }
}
