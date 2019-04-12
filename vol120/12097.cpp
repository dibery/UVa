#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
double PI = 3.1415926535897;
class cake
{
	public:
		double r, div;
		cake( int radius = 0 ) { r = radius; div = 0; }
		bool operator() ( const cake& a, const cake& b ) const { return a.r*a.r/(a.div+1) < b.r*b.r/(b.div+1); }
		double area() { return r * r * PI / div; }
		double cmp() { return r * r * PI / ( div + 1 ); }
};

int main()
{
	int t, qnt, man, r;

	for( scanf( "%d", &t ); t--; )
	{
		double area = 1000000000;
		priority_queue<cake,vector<cake>,cake> seq;
		scanf( "%d %d", &qnt, &man );
		for( int i = 0; i < qnt; ++i )
		{
			scanf( "%d", &r );
			seq.push( cake( r ) );
		}
		for( int i = 0; i <= man; ++i )
		{
			cake tmp = seq.top();
			++tmp.div;
			seq.pop();
			seq.push( tmp );
		}
		while( !seq.empty() )
		{
			cake tmp = seq.top();
			area = min( area, tmp.area() );
			seq.pop();
		}
		printf( "%.4f\n", area );
	}
	return 0;
}
