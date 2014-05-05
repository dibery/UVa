#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    int n, cp;
    char tri[ 32 ] = { 0 };

    while( scanf( "%d", &n ) && n >= 0 )
    {
        cp = n;
        for( int i = 0; i < 31; ++i, n /= 3 )
            tri[ 30 - i ] = n % 3 + '0';
        puts( cp? tri + strcspn( tri, "12" ) : "0" );
    }

	return 0;
}