#include<cstdio>
#include<cstring>
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
	int diff, yy, dd, mm, t = 0;
	char m[12], month[][12] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	for( scanf( "%*d" ); scanf( "%d-%[a-z,A-Z]-%d %d", &yy, m, &dd, &diff ) == 4; )
	{
		for( mm = 0; strcmp( month[ mm ], m ); ++mm );
		for( ; diff; --diff )
			next( dd, mm, yy );
		printf( "Case %d: %d-%s-%02d\n", ++t, yy, month[ mm ], dd );
	}
}
