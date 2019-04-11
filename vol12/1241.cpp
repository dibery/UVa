#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, people, absent;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &people, &absent ); )
	{
		bool exist[ 1 << people ];
		int ans = 0;

		fill( exist, exist + ( 1 << people ), true );
		for( int n; absent-- && scanf( "%d", &n ); )
			exist[ n - 1 ] = false;

		for( int lv = 1; lv <= people; ++lv )
			for( int i = 0, d = 1 << lv; i < 1 << people; i += d )
				ans += *max_element( exist + i, exist + i + d / 2 ) != *max_element( exist + i + d / 2, exist + i + d );
		printf( "%d\n", ans );
	}
}
