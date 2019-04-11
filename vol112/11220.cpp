#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	int t;
	string s;

	scanf( "%d\n", &t );
	for( int n = 1; n <= t; ++n )
	{
		printf( "%sCase #%d:\n", n == 1? "" : "\n", n );
		for( ; getline( cin, s ) && s.size(); puts( "" ) )
		{
			stringstream ss( s );
			for( int i = 1; ss >> s; ++i )
				if( s.size() >= i )
					cout << s[ i - 1 ];
				else
					--i;
		}
	}
}
