#include<cstdio>
#include<algorithm>

int main()
{
    int a[ 3 ];

    while( scanf( "%d %d %d", a, a+1, a+2 ) && *a )
    {
        std::sort( a, a+3 );
        puts( a[ 0 ]*a[ 0 ] + a[ 1 ]*a[ 1 ] == a[ 2 ]*a[ 2 ]? "right" : "wrong" );
    }

	return 0;
}