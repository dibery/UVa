#include<cstdio>
const int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, zodst[] = { 20, 50, 79, 110, 141, 172, 203, 233, 266, 296, 326, 356, 365 };
const char* zodiac[] = { "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn", "capricorn" };

bool leapyear( int y ) { return y % 400 == 0 || y % 4 == 0 && y % 100 != 0; }
bool leap( int m, int d, int y )
{
	if( leapyear( y ) && m <= 2 )
		return true;
	else if( leapyear( y+1 ) ) // 5/25 born at 2/29
		return m >= 6 || m == 5 && d >= 25;
	return false;
}

int main()
{
	int t, dtos[ 12 ][ 31 ], stod[ 365 ], date = -1, d, m, y, start, end, sign = 0;
	for( int i = 0; i < 12; ++i )
		for( int j = 0; j < day[ i ]; ++j )
		{
			dtos[ i ][ j ] = ++date;
			stod[ date ] = i*100 + j;
		}
	dtos[ 1 ][ 28 ] = dtos[ 2 ][ 0 ];
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%2d%2d%4d", &m, &d, &y );
		start = dtos[ m-1 ][ d-1 ];
		end = start + 280;
		if( leap( m, d, y ) )
			--end;
		if( end >= 365 )
			end -= 365, ++y;
		for( sign = 0; sign < 12; ++sign )
			if( zodst[ sign ] <= end && zodst[ sign+1 ] > end )
				break;
		if( m == 5 && d == 25 && leapyear( y ) )
			printf( "%d 02/29/%04d pisces\n", i, y );
		else
			printf( "%d %02d/%02d/%04d %s\n", i, stod[ end ] / 100 + 1, stod[ end ] % 100 + 1, y, zodiac[ sign ] );
	}
}
