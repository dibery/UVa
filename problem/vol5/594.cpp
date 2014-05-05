#include<cstdio>
#include<algorithm>

int main()
{
	char n[ 4 ];
	while( scanf( "%d", (int*)n ) == 1 )
	{
		int ori = *(int*)n;
		std::swap( n[ 0 ], n[ 3 ] );
		std::swap( n[ 1 ], n[ 2 ] );
		printf( "%d converts to %d\n", ori, *(int*)n );
	}
	return 0;
}
