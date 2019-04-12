#include<cstdio>

int main()
{
    double man, woman, candy, yes, no;

    while( scanf( "%lf %lf %lf", &man, &woman, &candy ) && ( man + woman ) )
    {
        double odd[ 101 ] = { 0 }, even[ 101 ] = { 1 };
        yes = man / ( man + woman );
        no = 1 - yes;
        for( int i = 1; i <= candy; ++i )
        {
            odd[ i ] = even[ i-1 ] * yes + odd[ i-1 ] * no;
            even[ i ] = even[ i-1 ] * no + odd[ i-1 ] * yes;
        }
        printf( "%.7f\n", even[ (int)candy ] );
    }

	return 0;
}