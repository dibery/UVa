import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] aa )
    {
        BigInteger[] gen = new BigInteger[ 81 ];
        gen[ 0 ] = gen[ 1 ] = BigInteger.valueOf( 1 );
        Scanner in = new Scanner( System.in );
        int n;
        for( int i = 2; i <= 80; ++i )
            gen[ i ] = gen[ i-1 ].add( gen[ i-2 ] );

        while( in.hasNext() && ( n = in.nextInt() ) != 0 )
            System.out.println( gen[ n ] );
    }
}