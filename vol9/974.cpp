#include<bits/stdc++.h>

int main()
{
	int t, low, up, N[] = { 1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962 };
	scanf( "%d", &t );
	
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &low, &up );
		if( n != 1 )
			puts( "" );
		bool out = false;
		printf( "case #%d\n", n );
		for( int i = 1; i < 20; ++i )
			if( N[ i ] >= low && N[ i ] <= up )
				printf( "%d\n", N[ i ] ), out = true;
		if( !out )
			puts( "no kaprekar numbers" );
	}
}
