#include<cstdio>

int main()
{
	int t, len, pos;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &len, &pos ); )
	{
		int ans = 0;
		for( int i = 0; i < len; ++i )
		{
			long long rep = 1ll << i + 2, grp = pos % rep / ( 1 << i );
			if( grp == 1 || grp == 2 )
				ans |= 1 << i;
		}
		printf( "%d\n", ans );
	}
}
