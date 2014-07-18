import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	static BigInteger[] fact = new BigInteger[ 201 ];
	public static void main( String[] arg )
	{
		Scanner in = new Scanner( System.in );
		int t = in.nextInt();
		fact[ 0 ] = BigInteger.ONE;

		for( int i = 1; i <= 200; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );

		for( int q = 0; q < t; ++q )
		{
			int len = in.nextInt(), black = in.nextInt(), white = len;
			int[] code = new int[ black ];

			for( int i = 0; i < black; ++i )
			{
				code[ i ] = in.nextInt();
				white -= code[ i ];
			}
			System.out.println( H( black+1, white-black+1 ) );
		}
	}
	public static BigInteger H( int m, int n )
	{
		if( n < 0 )
			return BigInteger.ZERO;
		return C( m+n-1, n );
	}
	public static BigInteger C( int m, int n )
	{ return fact[ m ].divide( fact[ n ] ).divide( fact[ m-n ] ); }
}
