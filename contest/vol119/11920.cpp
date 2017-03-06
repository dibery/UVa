#include<iostream>
#include<cstring>
using namespace std;

char inv( char c ) { return c == '0'? '1' : '0'; }

string proc( char *s )
{
	for( char *p = s + strlen( s ) - 1; p >= s && *p == '?'; --p )
		*p = 0;
	while( *s == '?' )
		++s;
	if( !strchr( s, '?' ) )
		return s;
	for( char *p, *next; p = strstr( s, "??" ); )
	{
		for( next = p + 1; *next == '?'; ++next );
		*( next - 1 ) = inv( *next );
		while( p < next - 1 )
			*p = inv( *( p - 1 ) ), ++p;
	}
	for( int i = 0; s[ i ]; ++i )
		if( s[ i ] == '?' && s[ i - 1 ] == s[ i + 1 ] )
			s[ i ] = inv( s[ i - 1 ] );
	return s;
}

bool ok( string s, int max )
{
	char last = 0;
	for( int idx = 0, row = 0; idx < s.size(); ++idx )
		if( s[ idx ] != '?' )
		{
			if( s[ idx ] != last )
				row = 1, last = s[ idx ];
			else if( ++row > max )
				return false;
		}
		else if( row + 1 <= max )
			s[ idx ] = s[ idx - 1 ];
		else
			last = s[ idx ] = s[ idx + 1 ], row = 1;
	return true;
}

int main()
{
	int t, ans;
	char in[ 1001 ];

	cin >> t;
	for( int n = 1; n <= t && cin >> in; ++n )
	{
		string s = proc( in );
		for( ans = 1; !ok( s, ans ); )
			++ans;
		cout << "Case " << n << ": " << ans << endl;
	}
}
