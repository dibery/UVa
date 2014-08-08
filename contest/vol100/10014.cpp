#include<cstdio>

int main()
{
    int t, size;
    double begin, end, c;

    for( scanf( "%d", &t ); t; printf( --t? "\n" : "" ) )
    {
        scanf( "%d %lf %lf", &size, &begin, &end );
        double ans = size * begin + end;
        for( int i = 0; i < size; ++i )
            scanf( "%lf", &c ), ans -= ( size - i ) * 2 * c;
        printf( "%.2f\n", ans / ( size+1 ) );
    }
}
