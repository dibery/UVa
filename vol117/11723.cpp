#include<cstdio>
#include<cmath>

int main()
{
    double road, num;
    int ans, t = 0;

    while( scanf( "%lf %lf", &road, &num ) && road )
        if( ( ans = ceil( ( road-num ) / num ) ) <= 26 )
            printf( "Case %d: %d\n", ++t, ans );
        else
            printf( "Case %d: impossible\n", ++t );

	return 0;
}