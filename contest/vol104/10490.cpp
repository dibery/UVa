#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	long long int pow2[ 64 ] = { 1 };
	char ans[] = { "FFPPFPFPFFFTFPFFFPFPFFFTFFFFFTFP" };

	for( int i = 1; i < 64; ++i )
		pow2[ i ] = pow2[ i-1 ] * 2;

	while( scanf( "%d", &n ) && n )
		if( ans[ n ] == 'P' )
			printf( "Perfect: %lld!\n", pow2[ n-1 ] * ( pow2[ n ] - 1 ) );
		else if( ans[ n ] == 'T' )
			puts( "Given number is prime. But, NO perfect number is available." );
		else
			puts( "Given number is NOT prime! NO perfect number is available." );
}
