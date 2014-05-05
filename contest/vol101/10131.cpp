#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class elephant
{
	public:
		int id, weight, iq, next, len;
		static int ticket;
		elephant( int w, int i ) { weight = w; iq = i; id = ++ticket; next = -1; len = 1; }
		bool operator< ( const elephant& cmp ) const { return weight != cmp.weight? weight < cmp.weight : iq < cmp.iq; }
		void operator= ( elephant& rhs ) { weight = rhs.weight; iq = rhs.iq; id = rhs.id; }
};
int elephant::ticket = 0;

int main()
{
	int weight, iq, start, cmp = 0;
	vector<elephant> data;

	while( scanf( "%d %d", &weight, &iq ) == 2 )
		data.push_back( elephant( weight, iq ) );
	sort( data.begin(), data.end() );

	for( int i = data.size() - 1; i >= 0; --i )
		for( int j = i + 1; j < data.size(); ++j )
			if( data[ j ].iq < data[ i ].iq && data[ j ].len >= data[ i ].len )
				data[ i ].len = 1 + data[ j ].len, data[ i ].next = j;
	for( int i = 0; i < data.size(); ++i )
		if( cmp < data[ i ].len )
			cmp = data[ i ].len, start = i;
	printf( "%d\n", cmp );
	while( start > 0 )
		printf( "%d\n", data[ start ].id ), start = data[ start ].next;
}
