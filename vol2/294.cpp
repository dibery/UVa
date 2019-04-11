#include<cstdio>
#include<cmath>
int factor( int n )
{
    int root = sqrt( n ), ans = 2;
    for( int i = 2; i <= root; ++i )
        if( n % i == 0 )
            ans += 2;
    return root * root == n? ans-1 : ans;
}

int main()
{
    int t, low, high, ans, div, fact;
    scanf( "%d", &t );

    while( t-- )
    {
        int now = 0;
        scanf( "%d %d", &low, &high );
        for( int i = low; i <= high; ++i )
            if( ( fact = factor( i ) ) > now )
                ans = i, now = fact;
        printf( "Between %d and %d, %d has a maximum of %d divisors.\n", low, high, ans, now );
    }

	return 0;
}