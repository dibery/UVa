#include<cstdio>
#define friend FRIEND

int main()
{
	int t, friend, box, has, size;

	for( scanf( "%d", &t ); t--; )
	{
		int res = 0;
		for( scanf( "%d %d", &friend, &box ); box--; )
		{
			int now = 1;
			for( scanf( "%d", &size ); size--; )
				scanf( "%d", &has ), now = now * has % friend;
			res = ( res + now ) % friend;
		}
		printf( "%d\n", res );
	}
}
