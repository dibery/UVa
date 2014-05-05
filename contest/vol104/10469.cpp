#include<cstdio>

int main()
{
    unsigned int a, b;

    while( scanf( "%u %u", &a, &b ) != EOF )
    {
        unsigned int ans = 0;
        for( int i = 0; i < 32; ++i )
            ans |= ( ( 1 << i ) & a ) ^ ( ( 1 << i ) & b );
        printf( "%u\n", ans );
    }
    return 0;
}
