#include<cstdio>

int main()
{
    int test, len, last, digit, sum, in;
    scanf( "%d", &test );

    while( test-- )
    {
        scanf( "%d", &len );
        digit = last = sum = 0;
        for( int i = 0; i < len; ++i )
        {
            scanf( "%d", &in );
            if( in < sum )
            {
                sum += in - last;
                last = in;
            }
            else
            {
                sum += in;
                last = in;
                ++digit;
            }
        }
        printf( "%d\n", digit );
    }

	return 0;
}