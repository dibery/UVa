#include<cstdio>

int main()
{
    int n;

    while( scanf( "%d", &n ) != EOF )
        if( n <= 9 )
            puts( "Stan wins." );
        else if( n <= 18 )
            puts( "Ollie wins." );
        else if( n <= 162 )
            puts( "Stan wins." );
        else if( n <= 324 )
            puts( "Ollie wins." );
        else if( n <= 2916 )
            puts( "Stan wins." );
        else if( n <= 5832 )
            puts( "Ollie wins." );
        else if( n <= 52488 )
            puts( "Stan wins." );
        else if( n <= 104976 )
            puts( "Ollie wins." );
        else if( n <= 944784 )
            puts( "Stan wins." );
        else if( n <= 1889568 )
            puts( "Ollie wins." );
        else if( n <= 17006112 )
            puts( "Stan wins." );
        else if( n <= 34012224 )
            puts( "Ollie wins." );
        else if( n <= 306110016 )
            puts( "Stan wins." );
        else if( n <= 612220032 )
            puts( "Ollie wins." );
        else
            puts( "Stan wins." );

	return 0;
}