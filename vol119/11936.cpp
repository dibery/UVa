#include<cstdio>
#include<algorithm>

int main()
{
	int n[ 3 ], t;

	for( scanf( "%d", &t ); t; --t )
	{
		scanf( "%d %d %d", n, n+1, n+2 );
		std::sort( n, n+3 );
		puts( n[ 0 ] + n[ 1 ] > n[ 2 ]? "OK" : "Wrong!!" );
	}
}
