#include<cstdio>
#include<climits>
#include<cstring>
long long int Kadane_1d( long long int[], long long int ), Kadane_2d( long long int[][ 20 ], long long int, long long int );
long long int max( long long int a, long long int b ) { return a<b? b : a; }

int main()
{
	long long int x, y, z, t, n[ 20 ][ 20 ][ 20 ] = { 0 };
	long long int array[ 20 ][ 20 ] = { 0 };
	for( scanf( "%lld", &t ); t--; )
	{
		long long int Max = 0, ext = INT_MIN;
		scanf( "%lld %lld %lld", &x, &y, &z );
		for( long long int i = 0; i < x; ++i )
			for( long long int j = 0; j < y; ++j )
				for( long long int k = 0; k < z; ++k )
				{
					scanf( "%lld", &n[ i ][ j ][ k ] );
					ext = max( ext, n[ i ][ j ][ k ] );
				}
		if( ext > 0 )
			for( long long int i = 0; i < z; ++i )
			{
				for( long long int j = i; j < z; ++j )
				{
					for( long long int k = 0; k < x; ++k )
						for( long long int l = 0; l < y; ++l )
							array[ k ][ l ] += n[ k ][ l ][ j ];
					Max = max( Kadane_2d( array, x, y ), Max );
				}
				memset( array, 0, sizeof( array ) );
			}
		else
			Max = ext;
		printf( "%lld\n", Max );
		if( t )
			puts( "" );
	}
	return 0;
}

long long int Kadane_2d( long long int array[ 20 ][ 20 ], long long int x, long long int y )
{
	long long int Max = 0, calc[ y ];
	memset( calc, 0, sizeof( calc ) );

	for( long long int i = 0; i < x; i++ )
	{
		for( long long int j = i; j < x; j++ )
		{
			for( long long int k = 0; k < y; k++ )
				calc[ k ] += array[ j ][ k ];
			Max = max( Kadane_1d( calc, y ), Max );
		}
		memset( calc, 0, sizeof( calc ) );
	}
	return Max;
}

long long int Kadane_1d( long long int array[ 20 ], long long int size )
{
	long long int sum = 0, Max = 0;
	for( long long int i = 0; i < size; i++ )
	{
		sum += array[ i ];
		if( sum > Max )
			Max = sum;
		if( sum < 0 )
			sum = 0;
	}
	return Max;
}
