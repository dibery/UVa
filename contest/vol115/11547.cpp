#include<cstdio>
inline int abs( int a ) { return a < 0? -a : a; }

int main()
{
    int in;
    scanf( "%*d" );

    while( scanf( "%d", &in ) != EOF )
        printf( "%d\n", abs( ( 315 * in + 36962 ) / 10 % 10 ) );

    return 0;
}
