#include<cstdio>
#include<algorithm>
using namespace std;
int all[] = { 12, 13, 15, 23, 25, 34, 35, 45 };
bool ok( char *s )
{
	int use[ 9 ] = { 0 };
	for( int i = 0; i < 8; ++i )
		++use[ find( all, all+8, max( s[i], s[i+1] ) + min( s[i], s[i+1] ) * 10 - 528 ) - all ];
	for( int i = 0; i < 8; ++i )
		if( use[ i ] != 1 )
			return false;
	return true;
}

int main()
{
	char order[] = { "112334552" };
	do
		if( ok( order ) )
			printf( "%s\n", order );
	while( next_permutation( order+1, order+8 ) );

	return 0;
}
