#include<cstdio>

int main()
{
    int bottle, take, exchange, t, total, tmp;
    scanf( "%d", &t );

    while( t-- )
    {
        int drink = 0;
        scanf( "%d %d %d", &bottle, &take, &exchange );
        total = bottle + take;
        while( total / exchange )
        {
            tmp = total / exchange;
            drink += tmp;
            total = total - tmp * exchange;
            total += tmp;
        }
        printf( "%d\n", drink );
    }

    return 0;
}
//11689 a536