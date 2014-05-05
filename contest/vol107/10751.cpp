#include<cstdio>

int main()
{
    double sqrtwo = 1.41421356237, pathLength;
    int times, n;

    scanf("%d",&times);

    while( times-- )
    {
        scanf( "%d",&n );
        pathLength = (n-1)*4 +( n-2>0? (n-2)*(n-2)*sqrtwo : 0 );
        printf( "%.4f\n", pathLength );
        if( times )
            printf("\n");
    }
    return 0;
}
