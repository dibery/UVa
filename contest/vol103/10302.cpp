#include<cstdio>
inline long long int sq( long long int n ) { return n*n; }

int main()
{
    long long int n;
    while( scanf( "%lld", &n ) != EOF )
        printf( "%lld\n", sq( ( n+1 ) * n / 2 ) );
    return 0;
}
