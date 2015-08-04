#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const char face[] = "A23456789TJQK", suit[] = "CDHS";

inline int card( char* p ) { return ( strchr( face, *p ) - face ) * 4 + ( strchr( suit, *(p+1) ) - suit ); }

int judge( int hold[] )
{
	int count[ 13 ] = { 0 };

	for( int i = 0; i < 5; ++i )
		++count[ hold[ i ] / 4 ];
	for( int i = 0; i < 13; ++i )
		if( count[ i ] && count[ (i+12) % 13 ] && count[ (i+11) % 13 ] && count[ (i+10) % 13 ] && count[ (i+9) % 13 ] )
			return 100;
	for( int i = 0; i < 13; ++i )
		if( count[ i ] && count[ (i+12) % 13 ] && count[ (i+11) % 13 ] && count[ (i+10) % 13 ] )
			return 10;
	for( int i = 0; i < 13; ++i )
		if( count[ i ] && count[ (i+12) % 13 ] && count[ (i+11) % 13 ] )
		{
			--count[ i ], --count[ (i+12) % 13 ], --count[ (i+11) % 13 ];
			for( int j = 0; j < 13; ++j )
				if( count[ j ] && count[ (j+12) % 13 ] )
					return 5;
			++count[ i ], ++count[ (i+12) % 13 ], ++count[ (i+11) % 13 ];
		}
	for( int i = 0; i < 13; ++i )
		if( count[ i ] && count[ (i+12) % 13 ] && count[ (i+11) % 13 ] )
			return 3;
	for( int i = 0; i < 13; ++i )
		if( count[ i ] && count[ (i+12) % 13 ] )
		{
			--count[ i ], --count[ (i+12) % 13 ];
			for( int j = 0; j < 13; ++j )
				if( count[ j ] && count[ (j+12) % 13 ] )
					return 1;
			++count[ i ], ++count[ (i+12) % 13 ];
		}
	return 0;
}

int main()
{
	char in[ 30 ];
	int hold[ 50 ], goal;

	while( fgets( in, 30, stdin ) && *in != '#' )
	{
		for( int i = 0; i < 5; ++i )
			hold[ i ] = card( in+i*3 );

		bool used[ 100 ] = { false };
		for( int i = 0; i < 5; ++i )
			used[ hold[ i ] ] = true;

		double change = 0, now = judge( hold );

		for( int i = 0; i < 5; ++i )
		{
			int This = hold[ i ];
			double Try = 0;

			for( int j = 0; j < 52; ++j )
				if( !used[ j ] )
					hold[ i ] = j, Try += judge( hold ) / 47.0;
			if( Try > change )
				change = Try, goal = i;
			hold[ i ] = This;
		}

		if( change-1 > now )
			printf( "Exchange %c%c\n", face[ hold[ goal ] / 4 ], suit[ hold[ goal ] % 4 ] );
		else
			puts( "Stay" );
	}
}  
