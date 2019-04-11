#include<cstdio>
int a, b, c, d, l;
inline int f( int n ) { return a*n*n + b*n + c; }

int main()
{
    while( scanf( "%d %d %d %d %d", &a, &b, &c, &d, &l ) && d )
    {
        int ans = 0;
        for( int i = 0; i <= l; ++i )
            if( f( i ) % d == 0 )
                ++ans;
        printf( "%d\n", ans );
    }

    return 0;
}
//11934