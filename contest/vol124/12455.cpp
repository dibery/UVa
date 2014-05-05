#include<cstdio>
void bt( const int *len, const int &now, const int &all, const int left, bool &found )
{
	if( !left )
		found = true;
	if( left < 0 || found )
		return;
	for( int i = now; i < all; ++i )
		bt( len, i+1, all, left - len[ i ], found );
}

int main()
{
	int t, goal, bar, len[ 20 ] = { 0 };
	scanf( "%d", &t );

	while( t-- )
	{
		bool found = false;

		scanf( "%d %d", &goal, &bar );
		for( int i = 0; i < bar; ++i )
			scanf( "%d", len+i );

		for( int i = 0; i < bar; ++i )
			bt( len, i, bar, goal, found );
		puts( found? "YES" : "NO" );
	}

	return 0;
}
