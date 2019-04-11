#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int shift;
	string s;

	while( cin >> shift && shift )
	{
		cin.get();
		shift = ( shift % 26 + 26 ) % 26;
		getline( cin, s );
		for( char c: s )
			if( islower( c ) )
				putchar( 'a' + ( c - 'a' + shift ) % 26 );
			else if( isupper( c ) )
				putchar( 'A' + ( c - 'A' + shift ) % 26 );
			else
				putchar( c );
		puts( "" );
	}
}
