#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#define x first
#define y second
#define LAST ( i + size - 1 ) % size
#define NEXT ( i + 1 ) % size
using namespace std;
typedef pair<int,int> Point;
typedef pair<int,int> Vector;

double rev( Point pnt[], int size )
{
	Point *p = min_element( pnt, pnt+size ), *next = p == pnt+size-1? pnt : p+1, *last = p == pnt? pnt+size-1 : p-1;
	return ( last->x - p->x ) * ( next->y - p->y ) - ( last->y - p->y ) * ( next->x - p->x ) > 0;
}

int main()
{
	for( int size; scanf( "%d", &size ) && size >= 3; )
	{
		double m = M_PI, M = 0;
		Point pos[ size ];

		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &pos[ i ].x, &pos[ i ].y );

		if( rev( pos, size ) )
			reverse( pos, pos+size );

		for( int i = 0; i < size; ++i )
		{
			Vector p1 = make_pair( pos[ LAST ].x - pos[ i ].x, pos[ LAST ].y - pos[ i ].y ),
						 p2 = make_pair( pos[ NEXT ].x - pos[ i ].x, pos[ NEXT ].y - pos[ i ].y );
			double angle = acos( ( p1.x * p2.x + p1.y * p2.y ) / hypot( p1.x, p1.y ) / hypot( p2.x, p2.y ) );

			if( p1.x * p2.y - p1.y * p2.x <= 0 )
				M = max( M, angle ), m = min( m, angle );
			else
				M = max( M, M_PI*2 - angle );
		}
		printf( "%f %f\n", m / M_PI * 180, M / M_PI * 180 );
	}
}
