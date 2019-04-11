#include<cstdio>
#include<algorithm>
long long int thelength( long long int start );

int main()
{
    long long int i, j, length, max = 0, counter, hold, ans;

    while( scanf( "%lld %lld", &i, &j ) && i+j )
    {
        if( i > j )
            std::swap( i, j );

        for( counter = i; counter <= j; counter++ )
            if( ( length = thelength( counter ) ) > max )
            {
                max = length;
                ans = counter;
            }
        printf( "Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", i, j, ans, max );
        max = 0;
    }
    return 0;
}

long long int thelength( long long int start )
{
    long long int length = 0;
    if( start == 1 )
        return 3;

    while( start != 1 )
    {
        if( start % 2 == 0 )
            start /= 2;
        else
            start = 3 * start + 1;
        length++;
    }
    return length;
}
