#include<cstdio>
#include<ctime>

int main()
{
	int size, d, m, y, power;
	time_t zero = 0, prev = 0;
	tm *now = gmtime( &zero );

	while( scanf( "%d", &size ) && size )
	{
		int use = 0, last = 0, day = 0;
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d %d %d", &d, &m, &y, &power );
			now -> tm_mday = d;
			now -> tm_mon = m - 1;
			now -> tm_year = y - 1900;
			if( difftime( mktime( now ), prev ) == 86400 )
				++day, use += power - last;
			prev = mktime( now );
			last = power;
		}
		printf( "%d %d\n", day, use );
	}
}
