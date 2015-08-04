#include<cstdio>
#include<climits>
#include<map>
using namespace std;

int main()
{
	int h, w, t = 0, lv[ 30 ][ 30 ];
	double water, flood;

	while( scanf( "%d %d", &h, &w ) && h+w )
	{
		map<int,int> stat;
		double count = 0;
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				scanf( "%d", lv[ i ]+j ), ++stat[ lv[ i ][ j ] ];

		scanf( "%lf", &water );
		flood = stat.begin()->first;

		for( map<int,int>::iterator i = stat.begin(); water; ++i )
			if( i->second * 100 * ( next( i )->first - i->first ) > water || next( i ) == stat.end() )
			{
				flood += water / i->second / 100;
				water = 0;
			}
			else
			{
				water -= i->second * 100 * ( next( i )->first - i->first );
				next( i )->second += i->second;
				flood = next( i )->first;
			}
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				count += flood > lv[ i ][ j ];

		printf( "Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n", ++t, flood, count * 100 / h / w );
	}
}
