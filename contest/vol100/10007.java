//problem 10007
import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] arg )
	{
		Scanner in = new Scanner( System.in );
		BigInteger[] catalan = new BigInteger[ 301 ], fact = new BigInteger[ 601 ];
		int n;
		fact[ 0 ] = BigInteger.ONE;

		for( int i = 1; i <= 600; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );
		for( int i = 0; i <= 300; ++i )
			catalan[ i ] = fact[ i*2 ].divide( fact[ i+1 ] ).divide( fact[ i ] );

		while( ( n = in.nextInt() ) != 0 )
			System.out.println( catalan[ n ].multiply( fact[ n ] ) );
	}
}
