#include<bits/stdc++.h>
using namespace std;

bool ok;

int check( int n, stringstream& ss )
{
	for( int w = 0, next; ss >> next; )
		if( next == -n )
			return next;
		else
			ok &= ( w += check( next, ss ) ) < -n;
}

bool valid( string& S )
{
	stack<int> s;
	stringstream ss;

	ss << S;
	for( int n; ss >> n; )
		if( n < 0 )
			s.push( n );
		else if( s.empty() || s.top() != -n )
			return false;
		else
			s.pop();
	return s.empty();
}

int main()
{
	for( string s; getline( cin, s ); )
	{
		int n;
		stringstream ss;

		ss << s;
		ok = valid( s );
		ss >> n;
		check( n, ss );
		puts( ok? ":-) Matrioshka!" : ":-( Try again." );
	}
}
