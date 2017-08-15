#include<bits/stdc++.h>
const int MOD = 1000000007, N = 1001;

bool vis[ N ][ N ];
int way[ N ][ N ];

int cal( char* sig, int up, int down )
{
	if( !*sig )
		return 1;
	if( vis[ up ][ down ] )
		return way[ up ][ down ];

	vis[ up ][ down ] = true;
	int ans = 0;

	if( *sig == 'I' or *sig == '?' )
		for( int i = 1; i <= up; ++i )
			ans = ( ans + cal( sig + 1, up - i, down + i - 1 ) ) % MOD;
	if( *sig == 'D' or *sig == '?' )
		for( int i = 1; i <= down; ++i )
			ans = ( ans + cal( sig + 1, up + i - 1, down - i ) ) % MOD;

	return way[ up ][ down ] = ans;
}

int main()
{
	for( char in[ N ]; scanf( "%s", in ) == 1; )
	{
		memset( vis, false, sizeof( vis ) );
		memset( way, 0, sizeof( way ) );
		int ans = 0, len = strlen( in );

		for( int i = 0; i <= len; ++i )
			ans = ( ans + cal( in, i, len - i ) ) % MOD;
		printf( "%d\n", ans );
	}
}
