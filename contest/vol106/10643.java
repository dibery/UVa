// 10643
import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		BigInteger[] fact = new BigInteger[ 1001 ], catalan = new BigInteger[ 501 ];
		BigInteger[][] dp = new BigInteger[ 501 ][ 501 ]; // [tree][edges]
		Scanner in = new Scanner( System.in );

		fact[ 0 ] = BigInteger.ONE;
		for( int i = 1; i <= 1000; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );
		for( int i = 0; i <= 500; ++i )
			catalan[ i ] = fact[ i*2 ].divide( fact[ i ] ).divide( fact[ i+1 ] );

		for( int i = 0; i <= 500; ++i )
			for( int j = 0; j <= 500; ++j )
				dp[ i ][ j ] = BigInteger.ZERO;
		for( int i = 0; i <= 500; ++i )
			dp[ i ][ 0 ] = BigInteger.ONE;
		for( int i = 1; i <= 500; ++i )
			for( int j = 2; j+i <= 500; j += 2 )
				for( int k = 0; k <= j; k += 2 )
					dp[ i ][ j ] = dp[ i ][ j ].add( catalan[ k/2 ].multiply( dp[ i-1 ][ j-k ] ) );

		int T = in.nextInt(), n;
		for( int N = 1; N <= T; ++N )
		{
			n = in.nextInt();
			BigInteger ans = BigInteger.ZERO;
			for( int i = 2; i <= n; i += 2 )
				ans = ans.add( dp[ i ][ n-i ] );
			System.out.println( "Case " + N + ": " + ans );
		}
	}
}
