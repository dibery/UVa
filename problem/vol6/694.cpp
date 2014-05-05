#include<cstdio>

int main()
{
    long long int n, lim, tmp, t = 0;

    while( scanf( "%lld %lld", &n, &lim ) && n >= 0 && lim >= 0 )
    {
        int len;
        tmp = n;
        for( len = 1; tmp != 1 && tmp <= lim; len += tmp <= lim )
            tmp = tmp % 2? tmp * 3 + 1 : tmp >> 1;
        printf( "Case %lld: A = %lld, limit = %lld, number of terms = %d\n", ++t, n, lim, len );
    }

	return 0;
}