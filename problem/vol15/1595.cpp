#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second

int main()
{
  int t, N;

  for( scanf( "%d", &t ); t-- && scanf( "%d", &N ); )
  {
	pii point[ 1000 ];

	for( int i = 0; i < N; ++i )
	  scanf( "%d %d", &point[ i ].x, &point[ i ].y );
	sort( point, point + N );

	double mid = ( point[ 0 ].x + point[ N - 1 ].x ) / 2.;

	puts( all_of( point, point + N, [ point, N, mid ] ( pii p ) {
		  pii tmp( mid + mid - p.x, p.y );
		  return *lower_bound( point, point + N, tmp ) == tmp;
		} )? "YES" : "NO" );
  }
}
