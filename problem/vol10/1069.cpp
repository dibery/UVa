#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[ 10000 ] = { 0 }, content[ 10000 ] = { 0 }, *begin;
	int div, t = 0;

	while( fgets( s, 10000, stdin ) && *s != '.' )
	{
		sscanf( s, "(%[^)])/%d", begin = content, &div );
		if( *content == '-' ) // make 1st item +
		{
			++begin;
			for( int i = 0; content[ i ]; ++i )
				if( content[ i ] == '-' )
					content[ i ] = '+';
				else if( content[ i ] == '+' )
					content[ i ] = '-';
		}

		// parsing
		int pow[ 101 ] = { 0 }, limit = -1;
		string expr = begin, item;

		for( size_t i = 0; i < expr.size(); ++i )
			if( expr[ i ] == '+' || expr[ i ] == '-' )
				expr.insert( i++, " " );

		for( stringstream ss( expr ); ss >> item; )
		{
			bool neg = item[ 0 ] == '-';
			int C, E = 0;

			if( neg || item[ 0 ] == '+' )
				item.erase( item.begin() );

			if( isdigit( item[ 0 ] ) )
				if( item.find( "n" ) == item.npos ) // C
					sscanf( item.c_str(), "%d", pow );
				else if( item.find( "^" ) == item.npos ) // C*n
					sscanf( item.c_str(), "%d", pow + ( E = 1 ) );
				else // C*n^e
					sscanf( item.c_str(), "%dn^%d", &C, &E ), pow[ E ] = C;
			else if( item.find( "^" ) == item.npos ) // n
				pow[ E = 1 ] = 1;
			else // n^e
				sscanf( item.c_str(), "n^%d", &E ), pow[ E ] = 1;

			if( neg )
				pow[ E ] = -pow[ E ];
			if( limit == -1 )
				limit = E;
		}

		// calc
		bool ok = true;

		for( int x = 1; x <= limit+1 && ok; ++x )
		{
			long long sum = 0, mod[ 101 ] = { 1 };
			
			for( int i = 1; i <= 100; ++i )
				mod[ i ] = mod[ i-1 ] * x % div;
			for( int i = 0; i <= 100; ++i )
				sum = ( sum + pow[ i ] * mod[ i ] ) % div;
			ok &= sum % div == 0;
		}

		if( ok )
			printf( "Case %d: Always an integer\n", ++t );
		else
			printf( "Case %d: Not always an integer\n", ++t );
	}
}
