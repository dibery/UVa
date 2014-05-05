#include<cstdio>
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }

int main()
{
    int m, n;

    while( scanf( "%d %d", &m, &n ) != EOF )
        printf( "%10d%10d    %s Choice\n\n", m, n, gcd( m, n ) == 1? "Good" : "Bad" );

    return 0;
}
