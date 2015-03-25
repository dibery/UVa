import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger[] ans = new BigInteger[ 2001 ];

		for( int i = 0; i <= 2000; ++i )
			ans[ i ] = BigInteger.ZERO;
		for( int i = 1; i <= 2000; ++i )
			for( int j = 2; j <= 7; ++j )
				ans[ i ] = ans[ i ].add( calc( ans, i, j ) );

		for( int n; in.hasNext(); )
			System.out.println( ans[ n = in.nextInt() ].subtract( ans[ n-6 > 0? n-6 : 0 ] ) );
	}

	public static BigInteger calc( BigInteger[] ans, int index, int offset )
	{
		if( index < offset )
			return BigInteger.ZERO;
		else if( offset == 5 || offset == 6 )
			return BigInteger.ONE.add( ans[ index-offset ] ).multiply( BigInteger.valueOf( 3 ) );
		else
			return BigInteger.ONE.add( ans[ index-offset ] );
	}
}
