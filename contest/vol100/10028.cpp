#include<cstdio>
inline int interval( int y, int m, int d, int py, int pm, int pd )
{
	if( m > pm || m == pm && d >= pd )
		return y - py;
	else return y - py - 1;
}

int main()
{
	int t, year, month, day, penalty, lastyear, lastmonth, lastday, in;
	char demerit[ 30 ];
	scanf( "%d", &t );

	while( t-- )
	{
		int good = 0, bad = 0;
		scanf( "%d", &in );
		getchar();
		lastyear = in / 10000, lastmonth = in / 100 % 100, lastday = in % 100;
		printf( "%04d-%02d-%02d No merit or demerit points.\n", lastyear, lastmonth, lastday );

		while( gets( demerit ) && *demerit )
		{
			sscanf( demerit, "%d %d", &in, &penalty );
			year = in / 10000, month = in / 100 % 100, day = in % 100;
			int diff = interval( year, month, day, lastyear, lastmonth, lastday );

			for( int count = ( bad? 1 : 2 ); count <= diff && good < 5; count += ( bad? 1 : 2 ) )
				if( bad > 2 )
					printf( "%04d-%02d-%02d %d demerit point(s).\n", lastyear+count, lastmonth, lastday, bad = bad / 2 );
				else if( bad <= 2 && bad )
					printf( "%04d-%02d-%02d No merit or demerit points.\n", lastyear+count, lastmonth, lastday ), bad = 0;
				else
					printf( "%04d-%02d-%02d %d merit point(s).\n", lastyear+count, lastmonth, lastday, ++good );

			if( good )
				if( good * 2 > penalty )
					printf( "%04d-%02d-%02d %d merit point(s).\n", year, month, day, good -= ( penalty + 1 ) / 2 );
				else if( good * 2 == penalty )
					printf( "%04d-%02d-%02d No merit or demerit points.\n", year, month, day ), good = 0;
				else
					printf( "%04d-%02d-%02d %d demerit point(s).\n", year, month, day, bad = penalty - good * 2 ), good = 0;
			else
				printf( "%04d-%02d-%02d %d demerit point(s).\n", year, month, day, bad += penalty );

			lastday = day;
			lastmonth = month;
			lastyear = year;
		}
		for( int count = ( bad? 1 : 2 ); good < 5; count += ( bad? 1 : 2 ) )
			if( bad > 2 )
				printf( "%04d-%02d-%02d %d demerit point(s).\n", lastyear+count, lastmonth, lastday, bad = ( bad >= 4? bad / 2 : bad - 2 ) );
			else if( bad <= 2 && bad )
				printf( "%04d-%02d-%02d No merit or demerit points.\n", lastyear+count, lastmonth, lastday ), bad = 0;
			else
				printf( "%04d-%02d-%02d %d merit point(s).\n", lastyear+count, lastmonth, lastday, ++good );
		if( t )
			puts( "" );
	}

	return 0;
}

