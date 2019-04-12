#include<stdio.h>
#include<stdlib.h>
typedef struct possible_answer
{
    int sum, first, second; //a+b, a, b
} possible_answer;
int comp( const void *a, const void *b )
{
    return ( (*(possible_answer*)a).sum - (*(possible_answer*)b).sum );
}
int compint( const void *a, const void *b )
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int total, counter, counter2;

    while( scanf( "%d", &total ) == 1 && total != 0 )  //how many numbers?
    {
        int allnum[ total ], result[ total * total ];
        int two_sum = 0, in_result = 0, sq = total * total, out;
        possible_answer addsum[ total * ( total-1 ) / 2 ], *find_success;
        for( counter = 0; counter < sq; counter++ )
            result[ counter ] = 0;

        for( counter = 0; counter < total; counter++ )
            scanf( "%d", &allnum[ counter ] );   //input all numbers

        for( counter = 0; counter < total-1; counter++ )
            for( counter2 = counter+1; counter2 < total; counter2++ )
            {
                addsum[ two_sum ].first = allnum[ counter ];
                addsum[ two_sum ].second = allnum[ counter2 ];
                addsum[ two_sum++ ].sum = allnum[ counter ] + allnum[ counter2 ];
            }   //all possible conditions for a+b (n^2 here)
        qsort( addsum, total * ( total-1 ) / 2, sizeof(possible_answer), comp );

        for( counter = 0; counter < total; counter++ )
            for( counter2 = 0; counter2 < total; counter2++ )
            {
                if( counter == counter2 )
                    continue;   //make it distinct
                int key = allnum[ counter ] - allnum[ counter2 ];   //d-c

                find_success = (possible_answer*) bsearch( &key, addsum, total * ( total-1 ) / 2, sizeof(possible_answer), comp );  //binary search
                if( find_success == NULL )
                    continue;   //result not found
                while( (find_success-1)->sum == key )
                    find_success--; //to the first of the keys
                while( find_success->sum == key && ( find_success->first == allnum[ counter ] || find_success->second == allnum[ counter ] || find_success->first == allnum[ counter2 ] || find_success->second == allnum[ counter2 ] ) )
                    find_success++;
                if( find_success->sum == key )
                    result[ in_result++ ] = allnum[ counter ];  //one of the solutions
            }   //all possible conditions for d-c (n^2 log n here)
        if( in_result )
            qsort( result, in_result, sizeof(int), compint );  //sorting (n log n here)

        if( in_result == 0 )
            printf( "no solution\n" );
        else
        {
            for( counter = 0; counter < sq && result[ counter ] != 0; counter++ )
                if( result[ counter+1 ] == 0 )
                    printf( "%d\n", result[ counter ] );	//output
            if( !counter )
                puts( "0" );
        }
    }
    return 0;
}
