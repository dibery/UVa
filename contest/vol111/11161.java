import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] arg )
	{
		int n, t = 0;
		Scanner in = new Scanner( System.in );
		BigInteger[] fib = new BigInteger[ 1500 ], sum = new BigInteger[ 1500 ];
		fib[ 0 ] = fib[ 1 ] = BigInteger.ONE;
		sum[ 0 ] = BigInteger.ZERO;
		for( int i = 2; i < 1500; ++i )
			fib[ i ] = fib[ i-1 ].add( fib[ i-2 ] );
        for( int i = 1; i < 1500; ++i )
            sum[ i ] = sum[ i-1 ].add( fib[ i ] );

		while( in.hasNext() )
		{
		    ++t;
			n = in.nextInt();
			if( n == 0 )
				break;
            if( n == 1 )
                System.out.println( "Set " + t + ":\n" + 0 );
            else
                System.out.println( "Set " + t + ":\n" + sum[ n-1 ].add( sum[ n-2 ] ).add( BigInteger.ONE ).divide( BigInteger.valueOf( 2 ) ) );
		}
	}
}
