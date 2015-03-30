#include<bits/stdc++.h>
#define A coef[0]
#define B coef[1]
#define C coef[2]
using namespace std;

void div( vector<double>& coef, double n )
{
	vector<double> tmp;
	tmp.push_back( coef.front() );
	for( vector<double>::iterator i = next( coef.begin() ); next( i ) != coef.end(); ++i )
		tmp.push_back( *i + tmp.back() * n );
	coef = tmp;
}

int main()
{
	int t, deg;
	double n;
	char s[ 10 ];

	for( scanf( "%d", &t ); t--; )
	{
		vector<double> coef;

		scanf( "%s", s );
		deg = atoi( s );
		for( double i = 0; i <= deg; ++i )
			scanf( "%lf", &n ), coef.push_back( n );
		for( double i = 0; i < deg-2; ++i )
			scanf( "%lf", &n ), div( coef, n );
		printf( "%.1f\n%.1f\n", ( -B + sqrt( B*B - 4*A*C ) ) / A / 2, ( -B - sqrt( B*B - 4*A*C ) ) / A / 2 );
	}
}
