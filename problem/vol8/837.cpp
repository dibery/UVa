#include<iostream>
#include<iomanip>
#include<set>
using namespace std;

struct line
{
	double x1, x2, y1, y2, rate;
	line()
	{
		cin >> x1 >> y1 >> x2 >> y2 >> rate;
		if( x1 > x2 )
			swap( x1, x2 ), swap( y1, y2 );
	}
};

int main()
{
	int t, num;

	cout << fixed << setprecision( 3 );
	for( cin >> t; t-- && cin >> num; )
	{
		line *data = new line[ num ];
		set<double> x;

		for( int i = 0; i < num; ++i )
			x.insert( data[ i ].x1 ), x.insert( data[ i ].x2 );
		cout << x.size() + 1 << endl << "-inf " << *x.begin() << " 1.000\n";
		for( auto it = x.begin(); next( it ) != x.end(); ++it )
		{
			double pass = 1, mid = ( *it + *next( it ) ) / 2;
			for( int i = 0; i < num; ++i )
				if( data[ i ].x1 < mid && data[ i ].x2 > mid )
					pass *= data[ i ].rate;
			cout << *it << ' ' << *next( it ) << ' ' << pass << endl;
		}
		cout << *prev( x.end() ) << " +inf 1.000\n";

		if( t )
			cout << endl;
		delete[] data;
	}
}
