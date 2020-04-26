#include<bits/stdc++.h>

int main()
{
	int t;
	for( scanf( "%d%*c%*c", &t ); t--; )
	{
		std::stack<char> exp;
		for( char input[ 2 ], c; gets( input ) && ( c = *input ); )
			if( isdigit( c ) )
				putchar( c );
			else if( c == '(' )
				exp.push( c );
			else if( c == ')' )
			{
				while( exp.top() != '(' )
					putchar( exp.top() ), exp.pop();
				exp.pop();
			}
			else
			{
				auto pred = []( char in ) { return strchr( "*/", in )? 1 : 0; };
				while( !exp.empty() && exp.top() != '(' && pred( exp.top() ) >= pred( c ) )
					putchar( exp.top() ), exp.pop();
				exp.push( c );
			}
		while( !exp.empty() )
			putchar( exp.top() ), exp.pop();
		puts( t? "\n" : "" );
	}
}
