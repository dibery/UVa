#include<bits/stdc++.h>

int main()
{
	for( char s[ 101 ]; gets( s ); )
	{
		int len = strlen( s ), zero = std::count( s, s + len, '0' ), ok = 0;
		for( int i = 0; s[ i ]; ++i )
			ok += s[ i ] == '0' && s[ ( i + 1 ) % len ] == '0';
		puts( ok*len == zero*zero? "EQUAL" : ok*len < zero*zero? "ROTATE" : "SHOOT" );
	}
}
