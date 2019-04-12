#include<cstdio>
int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int leap[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void next( int& d, int& m, int&y )
{
	if( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ) )
		if( d == leap[ m ] )
		{
			d = 1;
			if( m == 12 )
				m = 1, ++y;
			else
				++m;
		}
		else
			++d;
	else//
		if( d == day[ m ] )
		{
			d = 1;
			if( m == 12 )
				m = 1, ++y;
			else
				++m;
		}
		else
			++d;
}

int main()
{
	int diff, yy, dd, mm;

	while( scanf( "%d %d %d %d", &diff, &dd, &mm, &yy ) == 4 && dd )
	{
		yy += diff / 146097 * 400;
		for( diff %= 146097; diff; --diff )
			next( dd, mm, yy );
		printf( "%d %d %d\n", dd, mm, yy );
	}
}
