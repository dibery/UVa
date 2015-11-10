#include<cstdio>
#include<ctime>
const char* week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}, *month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int mday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool operator!= ( const tm& a, const tm& b )
{ return a.tm_year != b.tm_year || a.tm_mon != b.tm_mon || a.tm_mday != b.tm_mday; }

bool leap( int y ) { return y % 4 == 0 && ( y <= 1700 || y % 100 != 0 || y % 400 == 0 ); }

int offset( int y, int m, int d )
{
	const int sub[] = { 13, 12, 11, 10, 10, 9, 8, 7, 7, 6, 5, 4, 4, 3, 2, 1, 1 };

	if( m == 1 || ( m == 2 && d <= 29 ) )
		--y;
	return y / 100 < 17? sub[ y / 100 ] % 7 : 0;
}

bool valid( int y, int m, int d )
{
	if( y < 1 || m > 12 || y == 1752 && m == 9 && d > 2 && d < 14 || mday[ m-1 ] + ( m == 2 && leap( y ) ) < d )
		return false;
	return true;
}

int main()
{
	for( int y, m, d; scanf( "%d %d %d", &m, &d, &y ) && ( y || m || d ); )
	{
		time_t t;
		struct tm T, copy;

		time( &t );
		T = *localtime( &t );

		T.tm_year = y - 1900;
		T.tm_mon = m - 1;
		T.tm_mday = d;
		T.tm_sec = T.tm_min = T.tm_hour = 0;
		copy = T;

		mktime( &T );

		if( !valid( y, m, d ) )
			printf( "%d/%d/%d is an invalid date.\n", m, d, y );
		else if( y > 1752 || ( y == 1752 && m > 9 ) || ( y == 1752 && m == 9 && d >= 14 ) )
			printf( "%s %d, %d is a %s\n", month[ m - 1 ], d, y, week[ T.tm_wday ] );
		else
			printf( "%s %d, %d is a %s\n", month[ m - 1 ], d, y, week[ ( T.tm_wday + 4 - offset( y, m, d ) + 7 ) % 7 ] );
	}
}
