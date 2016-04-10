#include<cstdio>
#include<cstdlib>

int main()
{
	for( int n; scanf( "%d", &n ) && n; )
	{
		bool used[ 10000 ] = { false };
		char buf[ 9 ];
		int ans = 0;

		do
		{
			used[ n ] = true;
			++ans;
			sprintf( buf, "%08d", n * n );
			n = atoi( buf ) / 100 % 10000;
		}
		while( !used[ n ] );

		printf( "%d\n", ans );
	}
}
