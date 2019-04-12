#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<map>
using namespace std;
const char MAP[] = { "22233344455566677778889999" };
int trans( char *in )
{
	char tmp[ 8 ] = { 0 };
	int len = -1;
	for( int i = 0; in[ i ]; ++i )
		if( isalpha( in[ i ] ) )
			tmp[ ++len ] = MAP[ in[ i ] - 'A' ];
		else if( isdigit( in[ i ] ) )
			tmp[ ++len ] = in[ i ];
	return atoi( tmp );
}

int main()
{
	int t, qnt;
	char in[ 20000 ] = { 0 };
	scanf( "%d", &t );

	while( t-- )
	{
		map<int,int>times;
		bool out = false;
		scanf( "%d\n", &qnt );
		while( qnt-- )
		{
			gets( in );
			++times[ trans( in ) ];
		}
		for( map<int,int>::iterator it = times.begin(); it != times.end(); ++it )
			if( it->second > 1 && ( out = true ) )
				printf( "%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second );
        if( !out )
            puts( "No duplicates." );
		if( t )
			puts( "" );
	}

	return 0;
}
