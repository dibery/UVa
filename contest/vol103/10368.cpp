#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,bool> stat;

bool win( int a, int b )
{
	if( a < b )
		swap( a, b );
	if( a % b == 0 )
		return true;
	if( stat.find( make_pair( a, b ) ) != stat.end() )
		return stat[ make_pair( a, b ) ];
	if( a / b == 1 )
		return !win( b, a - b );
	return !win( b, a % b + b ) || !win( b, a % b );
}

int main()
{
	for( int a, b; cin >> a >> b && a; )
		cout << ( win( a, b )? "Stan" : "Ollie" ) << " wins\n";
}
