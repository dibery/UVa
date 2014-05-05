#include<cstdio>
#include<cmath>
#include<list>
using namespace std;

int main()
{
    int n;
    while( scanf( "%d", &n ) && n )
    {
        int x = 0, y = 0;
        list<int>a, b;
        for( int i = 0; n; ++i, n >>= 1 )
            if( n & 1 )
                if( a.size() == b.size() )
                    a.push_back( i );
                else
                    b.push_back( i );
        while( !a.empty() )
        {
            x += pow( 2.0, a.front() );
            a.pop_front();
        }
        while( !b.empty() )
        {
            y += pow( 2.0, b.front() );
            b.pop_front();
        }
        printf( "%d %d\n", x, y );
    }

	return 0;
}