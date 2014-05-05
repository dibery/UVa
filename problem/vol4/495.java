import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] aa )
	{   
		int n;
		Scanner in = new Scanner( System.in );
		BigInteger[] ans;
		ans = new BigInteger[ 5001 ];
		ans[ 0 ] = BigInteger.valueOf( 0 );
		ans[ 1 ] = BigInteger.valueOf( 1 );
		ans[ 2 ] = BigInteger.valueOf( 1 );

		for( int i = 3; i <= 5000; ++i )
			ans[ i ] = ans[ i-1 ].add( ans[ i-2 ] );
		while( in.hasNext() )
		{   
			n = in.nextInt();
			System.out.println( "The Fibonacci number for " + n + " is " + ans[ n ] );
		}   
	}   
}

