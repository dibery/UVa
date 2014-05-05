#include<cstdio>
#include<algorithm>
using namespace std;
bool accom( int Try, int number, int vessle, int *vol )
{
    int filled = 0, now = 0;
    for( int i = 0; i < vessle && filled <= number; ++i )
        if( now + vol[ i ] <= Try )
            now += vol[ i ];
        else
        {
            if( !now )
                return false;
            ++filled;
            now = 0;
            --i;
        }
    return filled < number;
}

int main()
{
    int n, m, vol[ 1000 ];

    while( scanf( "%d %d", &n, &m ) != EOF )
    {
        for( int i = 0; i < n; ++i )
            scanf( "%d", vol+i );
        int low = 1, high = 1000000*n, mid;
        while( low < high )
        {
            mid = ( low+high ) / 2;
            if( accom( mid, m, n, vol ) )
                high = mid;
            else
                low = mid+1;
        }
        printf( "%d\n", low );
    }

	return 0;
}