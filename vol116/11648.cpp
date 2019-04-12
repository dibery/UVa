#include<bits/stdc++.h>

double sol( int A, int B, int C )
{
	double judge = sqrt( B*B - 4*A*C ), s1 = ( -B + judge ) / A / 2, s2 = ( -B - judge ) / A / 2;
	return s2 > 0 && s2 < 1? s2 : s1;
}

int main()
{
	int t, up, down, left, right;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d %d", &down, &up, &left, &right );
		double rate = sol( 2*down - 2*up, -4*down, down+up );
		printf( "Land #%d: %f %f\n", n, left*rate, right*rate );
	}
}
