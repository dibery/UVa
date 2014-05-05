#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
int number[ 100000 ], quant, target, sum[ 100000 ];

int main()
{
    while( scanf( "%d %d", &quant, &target ) != EOF )
    {
        int ans = INT_MAX;
        *sum = 0;
        for( int i = 0; i < quant; ++i )
            scanf( "%d", number+i ), sum[ i+1 ] = sum[ i ] + number[ i ];
        for( int i = 0; i <= quant && ans; ++i )
            if( sum[ quant ] - sum[ i ] < target )
                break;
            else
                ans = min( (long int)ans, lower_bound( sum+i, sum+quant+1, target+sum[ i ] ) - sum - i );
        printf( "%d\n", ans == INT_MAX? 0 : ans );
    }

	return 0;
}