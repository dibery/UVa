#include<cstdio>

int main()
{
    long long int earn, tax, tmp;

    while( scanf( "%lld %lld", &earn, &tax ) && earn )
    {
        if( tax >= 100 || tax <= 0 )
        {
            puts( "Not found" );
            continue;
        }
        tmp = ( earn - 1 ) * 100 / ( 100 - tax );
        if( tmp * ( 100 - tax ) == ( earn - 1 ) * 100 )
            --tmp;
        if( tmp < earn )
        {
            puts( "Not found" );
            continue;
        }
        printf( "%lld\n", tmp );
    }

    return 0;
}
