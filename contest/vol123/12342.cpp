#include<cstdio>
#include<cmath>
int calc( int income )
{
	double tax = 0;
	if( income > 1180000 )
		tax = ( income - 1180000 ) * .25 + 150000;
	else if( income > 880000 )
		tax = ( income - 880000 ) * .2 + 90000;
	else if( income > 480000 )
		tax = ( income - 480000 ) * .15 + 30000;
	else if( income > 180000 )
		tax = ( income - 180000 ) * .1;
	return ceil( tax );
}

int main()
{
	int t, income, tax;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d", &income );
		tax = calc( income );
		if( tax > 0 && tax < 2000 )
			tax = 2000;
		printf( "Case %d: %d\n", n, tax );
	}
}
