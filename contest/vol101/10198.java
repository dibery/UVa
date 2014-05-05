import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] arg )
    {
        int t;
        Scanner in = new Scanner( System.in );
        BigInteger[] ans = new BigInteger[ 1001 ];
        ans[ 1 ] = BigInteger.valueOf( 2 );
        ans[ 2 ] = BigInteger.valueOf( 5 );
        ans[ 3 ] = BigInteger.valueOf( 13 );
        for( int i = 4; i <= 1000; ++i )
            ans[ i ] = ans[ i-1 ].add( ans[ i-1 ] ).add( ans[ i-2 ] ).add( ans[ i-3 ] );

        while( in.hasNext() )
        {
            t = in.nextInt();
            System.out.println( ans[ t ] );
        }
    }
}