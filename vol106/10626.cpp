#include<bits/stdc++.h>
using namespace std;

int One( int coke, int one )
{
	return coke * 8;
}

int Five( int coke, int five, int one )
{
	if( !five )
		return One( coke, one );
	else if( five >= coke * 2 )
		return coke * 2;
	else if( five <= coke )
		return 4 * five + One( coke - five, one - 3 * five );
	else
		return 2 * ( five - coke ) + 4 * ( 2 * coke - five );
}

int Ten( int coke, int ten, int five, int one )
{
	if( !ten )
		return Five( coke, five, one );
	if( ten >= coke )
		return coke;
	int ans = INT_MAX;
	for( int i = 0; i <= ten; ++i )
		if( one - 3 * i + 2 * ( ten - i ) >= 0 )
			ans = min( ans, ten + 3 * i + Five( coke - ten, five + i, one - 3 * i + 2 * ( ten - i ) ) );
	return ans;
}

int main()
{
	int t, C, one, five, ten;
	for( scanf( "%d", &t ); t-- && scanf( "%d %d %d %d", &C, &one, &five, &ten ); )
		printf( "%d\n", Ten( C, ten, five, one ) );
}
