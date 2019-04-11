#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int allcir[] = { 113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331 };
/*bool isprime[ 1000000 ] = { false, false, true, true }, cir[ 1000000 ];
int allprime[ 1000000 ] = { 2, 3 }, allcir[ 50 ], size = 2, sizecir = 0;
void rotate( char* begin, char* end )
{
	char tmp[ 10 ] = { 0 };
	int index = 0;
	for( char* t = begin+1; t != end; ++t )
		tmp[ index++ ] = *t;
	tmp[ index ] = *begin;
	strcpy( begin, tmp );
}
bool judge( int n )
{
	for( int i = 1; allprime[ i ] * allprime[ i ] <= n; ++i )
		if( n % allprime[ i ] == 0 )
			return false;
	return true;
}
bool Judge( int n )
{
	char tmp[ 10 ] = { 0 };
	sprintf( tmp, "%d", n );
	int len = strlen( tmp );
	for( rotate( tmp, tmp + len ); atoi( tmp ) != n; rotate( tmp, tmp + len ) )
		if( !isprime[ atoi( tmp ) ] )
			return false;
	return true;
}*/

int main()
{
	int begin, end;
/*	for( int i = 5; i <= 1000000; i += 2 )
		if( isprime[ i ] = judge( i ) )
			allprime[ size++ ] = i;
	for( int i = 101; i < 1000000; i += 2 )
		if( isprime[ i ] && !cir[ i ] && Judge( i ) )
		{
			char tmp[ 10 ] = { 0 };
			sprintf( tmp, "%d", i );
			while( !cir[ atoi( tmp ) ] )
				cir[ atoi( tmp ) ] = true, rotate( tmp, tmp + strlen( tmp ) );
		}
	for( int i = 1; i < 1000000; i += 2 )
		if( cir[ i ] )
			allcir[ sizecir++ ] = i;
    for( int i = 0; i < sizecir; ++i )
        printf( "%d, ", allcir[ i ] );return 0;*/

	while( scanf( "%d %d", &begin, &end ) == 2 )
	{
/*		int ans = 0;
		for( int i = 0; i < sizecir; ++i )
			if( allcir[ i ] >= begin && allcir[ i ] <= end )
				++ans;*/
        int ans = upper_bound( allcir, allcir + 42, end ) - lower_bound( allcir, allcir + 42, begin );
		if( !ans )
			puts( "No Circular Primes." );
		else if( ans == 1 )
			puts( "1 Circular Prime." );
		else
			printf( "%d Circular Primes.\n", ans );
	}
}
