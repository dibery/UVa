import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String arg[] )
	{
		int n;
		Scanner in = new Scanner( System.in );
		BigInteger[] fact = new BigInteger[ 2001 ];

		fact[ 0 ] = BigInteger.ONE;
		for( int i = 1; i <= 2000; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );

		while( in.hasNext() )
		{
			n = in.nextInt();
			System.out.println( fact[ 2*n ].divide( fact[ n ] ).divide( fact[ n+1 ] ) );
		}
	}
}
