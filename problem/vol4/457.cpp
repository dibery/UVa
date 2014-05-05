#include<cstdio>
const char quant[] = { " .xW" };

int main()
{
    int t, dna[ 10 ];
    scanf( "%d", &t );

    while( t-- )
    {
        int dish[ 42 ] = { 0 };
        dish[ 20 ] = 1;
        for( int i = 0; i < 10; ++i )
            scanf( "%d", dna+i );
        for( int i = 0; i < 50; ++i )
        {
            int den[ 42 ] = { 0 };  //density
            for( int i = 1; i <= 40; ++i )
                printf( "%c%s", quant[ dish[ i ] ], i == 40? "\n" : "" );
            for( int i = 1; i <= 40; ++i )
                for( int j = i-1; j <= i+1; ++j )
                    den[ i ] += dish[ j ];
            for( int i = 1; i <= 40; ++i )
                dish[ i ] = dna[ den[ i ] ];
        }
        if( t )
            puts( "" );
    }

	return 0;
}