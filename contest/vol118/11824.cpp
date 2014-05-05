#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp( double a, double b )
{
    return a > b;
}

int main()
{
    int test, i;
    double money, land[ 40 ];
    scanf( "%d", &test );

    while( test )
    {
        i = -1;
        money = 0;
        while( scanf( "%lf", &land[ ++i ] ) )
            if( !land[ i ] )
            {
                sort( land, land+i, cmp );
                for( int k = 0; k < i; ++k )
                    money += 2 * pow( land[ k ], double(k+1) );
                break;
            }
        if( money > 5000000 )
            puts( "Too expensive" );
        else
            printf( "%.0f\n", money );
        --test;
    }
}
