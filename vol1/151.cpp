#include<cstdio>
inline int joseph( int total, int per, int serial ) { return serial == 1? per % total : ( joseph( total-1, per, serial-1 ) + per ) % total; }

int main()
{
    int city, ans;

    while( scanf( "%d", &city ) && city )
    {
        for( ans = 1; ; ++ans )
            if( joseph( city-1, ans, city-1 ) == 11 )
                break;
        printf( "%d\n", ans );
    }

	return 0;
}