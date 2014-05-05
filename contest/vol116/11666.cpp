#include<cstdio>
#include<cmath>

int main()
{
    int n;

    while( scanf( "%d", &n ) && n )
    {
        int expo = ceil( log( n ) );
        if( n / exp( expo-1 ) <= 2 )
            printf( "%d %.8lf\n", expo-1, 1 - n / exp( expo-1 ) );
        else
            printf( "%d %.8lf\n", expo, 1 - n / exp( expo ) );
    }

	return 0;
}