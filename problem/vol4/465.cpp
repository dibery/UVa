#include<cstdio>
#include<cstdlib>
#include<climits>

int main()
{
    char in[ 1000 ], a[ 1000 ], b[ 1000 ], op;

    while( gets( in ) )
    {
        bool first = false, second = false, result = false;
        sscanf( in, "%s %c %s", a, &op, b );
        puts( in );
        long long int x = strtoll( a, NULL, 10 ), y = strtoll( b, NULL, 10 );
        if( x > INT_MAX )
            first = true;
        if( y > INT_MAX )
            second = true;
        if( op == '*' )
            if( first && second || x && y && x * y > INT_MAX || first && y || second && x )
                result = true;
            else;
        else//
            if( first || second || x + y > INT_MAX )
                result = true;
        if( first )
            puts( "first number too big" );
        if( second )
            puts( "second number too big" );
        if( result )
            puts( "result too big" );
    }
    return 0;
}
