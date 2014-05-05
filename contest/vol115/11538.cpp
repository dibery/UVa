#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long int row, col;

	while( scanf( "%lld %lld", &row, &col ) && row )
	{
		if( row < col )
			swap( row, col );
		long long int ans = row * col * ( row + col - 2 );
		if( row == col )
			ans += 2 * ( col * ( col+1 ) * ( 2*col+1 ) / 3 - ( 1+col ) * col - row * ( row - 1 ) );
		else
			ans += 2 * ( col * ( col+1 ) * ( 2*col+1 ) / 3 - ( 1+col ) * col + ( col-1 ) * ( row - col - 1 ) * col );
		printf( "%lld\n", ans );
	}

	return 0;
}
