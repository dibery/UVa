#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class item
{
	public:
		int cost, quality;
		item( int c = 0, int g = 0 ) { cost = c; quality = g; }
		bool operator() ( const item& a, const item& b )
		{
			if( a.cost != b.cost )
				return a.cost < b.cost;
			return a.quality < b.quality;
		}
		bool operator() ( char* a, char *b ) { return strcmp( a, b ) < 0; }
};
int spend( int required, map<char*,set<item,item>,item>& price )
{
	int money = 0;
	for( map<char*,set<item,item>,item>::iterator a = price.begin(); a != price.end(); ++a )
		for( set<item,item>::iterator it = a->second.begin(); ; ++it )
		{
			if( it == a->second.end() )
				return INT_MAX;
			if( it->quality >= required )
			{
				money += it->cost;
				break;
			}
		}
	return money;
}

int main()
{
	int t, qnt, budget, cost, quality;
	char type[ 32 ];

	for( scanf( "%d", &t ); t--; )
	{
		map< char*,set<item,item>,item > list;
		set<int>qua;
		set<int>::iterator ans;

		scanf( "%d %d", &qnt, &budget );
		for( int i = 0; i < qnt; ++i )
		{
			scanf( "%s %*s %d %d", type, &cost, &quality );
			qua.insert( quality );
			if( list.find( type ) == list.end() )
			{
				set<item,item> tmp;
				tmp.insert( item( cost, quality ) );
				list.insert( pair< char*,set<item,item> > ( strdup( type ), tmp ) );
			}
			else
				list[ type ].insert( item( cost, quality ) );
		}
		for( ans = qua.begin(); ans != qua.end(); ++ans )
			if( spend( *ans, list ) > budget )
				break;
		printf( "%d\n", *--ans );
	}
	return 0;
}
