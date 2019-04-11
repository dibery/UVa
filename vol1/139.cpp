#include<bits/stdc++.h>
#define P phone[ index ]
using namespace std;

struct node
{
	string name, loc;
	int rate;
	node( string s, string l, int c ) { name = s; loc = l; rate = c; }
	bool operator == ( char *s )
	{
		int L = strlen( s ), N = name.size();
		if( s[ 0 ] != '0' )
			return false;
		else if( s[ 1 ] == '0' && ( L < N + 4 || L > N + 10 ) )
			return false;
		else if( s[ 1 ] != '0' && ( L < N + 4 || L > N + 7 ) )
			return false;
		return !strncmp( s, name.c_str(), N );
	}
	bool operator != ( char *s ) { return !( *this == s ); }
	double cost() { return rate / 100.0; }
	const char* snum( char* s ) { return s + name.size(); }
};

int main()
{
	vector<node> phone;
	int cost, index;
	char s[ 99 ], loc[ 99 ];

	while( scanf( "%s", s ) && strcmp( s, "000000" ) )
		scanf( " %[^$]$%d", loc, &cost ), phone.push_back( node( s, loc, cost ) );

	while( scanf( "%s %d", s, &cost ) == 2 )
	{
		for( index = 0; index < phone.size() && P != s; ++index );
		if( index < phone.size() )
			printf( "%-16s%-25s%10s%5d%6.2f%7.2f\n", s, P.loc.c_str(), P.snum( s ), cost, P.cost(), cost * P.cost() );
		else if( *s == '0' )
			printf( "%-16s%-25s%10s%5d        -1.00\n", s, "Unknown", "", cost );
		else
			printf( "%-16s%-25s%10s%5d%6.2f%7.2f\n", s, "Local", s, cost, 0., 0. );
	}
}
