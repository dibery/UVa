#include<cstdio>
#include<cstdlib>
#include<cstring>

int prime[ 5000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	char str[ 50 ];
	int begin, end, part;

	for( int i = 3; i*i <= 2000000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	while( gets( str ) )
		if( strchr( str, ' ' ) )
		{
			sscanf( str, "%d %d", &begin, &end );
			if( begin > 0 && end > 0 )
				printf( "%d\n", ( end + 2 ) / 4 - ( begin + 1 ) / 4 );
			else if( begin < 0 && end < 0 )
				printf( "%d\n", ( -begin + 2 ) / 4 - ( -end + 1 ) / 4 );
			else
				printf( "%d\n", ( end + 2 ) / 4 + ( -begin + 2 ) / 4 );
		}
		else
		{
			bool neg = ( begin = atoi( str ) ) < 0;
			begin = abs( begin );
			part = begin & 1? 1 : 2;
			long long int a = part + begin / part >> 1, b = begin / part - part >> 1;
			if( ( begin % 4 == 0 || begin % 2 == 1 ) )
				if( !neg )
					printf( "%lld %lld\n", a, b );
				else
					printf( "%lld %lld\n", b, a );
			else
				puts( "Bachelor Number." );
		}
}
