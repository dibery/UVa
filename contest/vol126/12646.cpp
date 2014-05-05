#include<cstdio>

int main()
{
    int a, b, c;

    while( scanf( "%d %d %d", &a, &b, &c ) != EOF )
    {
        int sum = a*100 + b*10 + c;

        if( sum == 0 || sum == 111 )
            puts( "*" );
        else if( sum == 100 || sum == 11 )
            puts( "A" );
        else if( sum == 10 || sum == 101 )
            puts( "B" );
        else
            puts( "C" );
    }

    return 0;
}
