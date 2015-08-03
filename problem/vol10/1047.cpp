#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

long long fact[ 21 ] = { 1 };
bool ok( char* a, char* b, int l )
{
	for( int i = l - 1; i; --i )
		if( a[ i ] > b[ i ] )
			return true;
		else if( a[ i ] < b[ i ] )
			return false;
	return false;
}
int bit1( int n ) { return !n? 0 : 1 + bit1( n ^ ( n & -n ) ); }
long long C( int n, int m ) { return fact[ n ] / fact[ m ] / fact[ n-m ]; }

int main()
{
	int tower, select, single[ 20 ], set, t = 0;

	for( int i = 1; i <= 20; ++i )
		fact[ i ] = i * fact[ i-1 ];
	while( scanf( "%d %d", &tower, &select ) && tower )
	{
		int grp[ 10 ] = { 0 }, serve[ 10 ] = { 0 }, ans_man = -1;
		char s[ 30 ] = { 0 }, ans_str[ 30 ] = { 0 };

		for( int i = 0; i < tower; ++i )
			scanf( "%d", single + i );
		scanf( "%d", &set );
		for( int i = 0; i < set; ++i )
		{
			int size, id = 0, n;
			for( scanf( "%d", &size ); size--; )
				scanf( "%d", &n ), id |= 1 << --n;
			scanf( "%d", serve + i );
			grp[ i ] = id;
		}

		for( int i = 0; i < tower; ++i )
			s[ i ] = i < tower - select? '0' : '1';
		do
		{
			int id = strtol( s, NULL, 2 ), This = 0;
			for( int i = 0, overlap = *grp & id, one = bit1( overlap ); i < set; one = bit1( overlap = grp[ ++i ] & id ) )
				if( one > 1 )
					for( int j = 2; j <= one; ++j )
						This += C( one, j ) * serve[ i ] * ( j & 1? 1 : -1 );
			for( int i = 0; i < tower; ++i )
				if( id & 1 << i )
					This += single[ i ];
			if( This > ans_man - ok( s, ans_str, tower ) )
				ans_man = This, strcpy( ans_str, s );
		}
		while( std::next_permutation( s, s + tower ) );

		printf( "Case Number  %d\nNumber of Customers: %d\nLocations recommended:", ++t, ans_man );
		for( int i = tower - 1; i >= 0; --i )
			if( ans_str[ i ] == '1' )
				printf( " %d", tower - i );
		puts( "\n" );
	}
}
