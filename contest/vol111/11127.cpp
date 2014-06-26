#include<cstdio>
#include<cstring>
void fill( char* str, int now, int len, int& ans )
{
	if( len > 2 )
	{
		for( int L = 1; 3*L <= now+1; ++L )
			if( !strncmp( str+now-L, str+now-2*L, L ) && !strncmp( str+now-L, str+now-3*L, L ) )
				return;
	}
	if( now == len )
	{
		++ans;
		return;
	}
	if( str[ now ] != '*' )
		fill( str, now+1, len, ans );
	else
	{
		str[ now ] = '0';
		fill( str, now+1, len, ans );
		str[ now ] = '1';
		fill( str, now+1, len, ans );
		str[ now ] = '*';
	}
}

int main()
{
	int len, T = 0;
	char str[ 32 ];

	while( scanf( "%d", &len ) && len )
	{
		int ans = 0;
		scanf( "%s", str );
		fill( str, 0, len, ans );
		printf( "Case %d: %d\n", ++T, ans );
	}
}
