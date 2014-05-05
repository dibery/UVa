import java.util.Scanner;
import java.math.BigInteger;
import java.lang.String;
public class Main
{
    public static void main( String[] arg )
    {
        BigInteger[][] comb = new BigInteger[ 101 ][ 101 ];
        Scanner in = new Scanner( System.in );
        String input, a, b, Exp;
        int exp, t;
        for( int i = 0; i <= 100; ++i )
            for( int j = 0; j <= 100; ++j )
                comb[ i ][ j ] = BigInteger.ZERO;
        for( int i = 0; i <= 100; ++i )
            comb[ i ][ 0 ] = BigInteger.ONE;
        for( int i = 1; i <= 100; ++i )
            for( int j = 1; j <= 100 && j <= i; ++j )
                comb[ i ][ j ] = comb[ i-1 ][ j-1 ].add( comb[ i-1 ][ j ] );
        t = in.nextInt();

        for( int k = 1; k <= t; ++k )
        {
            input = in.next();
            int i = 1, j;
            for( ; input.charAt( i ) != '+'; ++i );
            a = input.substring( 1, i );
            for( j = i+1; input.charAt( j ) != ')'; ++j );
            b = input.substring( i+1, j );
            Exp = input.substring( j+2 );
            exp = Integer.valueOf( Exp );
            System.out.print( "Case " + k + ": " );
            if( exp == 1 )
            {
                System.out.println( a + "+" + b );
                continue;
            }
            for( i = 0; i <= exp; ++i )
            {
                if( exp - i == 0 );
                else if( exp - i == 1 )
                    System.out.print( comb[ exp ][ i ] + "*" + a + "*" );
                else if( i == 0 )
                    System.out.print( a + "^" + exp + "+" );
                else
                    System.out.print( comb[ exp ][ i ] + "*" + a + "^" + (exp - i) + "*" );
                if( i == 0 );
                else if( i == exp )
                    System.out.println( b + "^" + exp );
                else if( i != 1 )
                    System.out.print( b + "^" + i + "+" );
                else if( i == 1 )
                    System.out.print( b + "+" );
            }
        }
    }
}