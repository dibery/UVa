#include<cstdio>
#include<cctype>

int main()
{
	int t, qnt;
	double mass[ 26 ];
	char atom[ 100 ], *pos, type;
	mass[ 2 ] = 12.01, mass[ 7 ] = 1.008, mass[ 14 ] = 16, mass[ 13 ] = 14.01;

	for( scanf( "%d\n", &t ); t; --t )
	{
		double ans = 0;
		gets( pos = atom );
		while( *pos )
		{
			if( sscanf( pos, "%c%d", &type, &qnt ) == 1 )
				qnt = 1;
			ans += mass[ type - 'A' ] * qnt;
			for( ++pos; isdigit( *pos ); ++pos );
		}
		printf( "%.3f\n", ans );
	}
}
