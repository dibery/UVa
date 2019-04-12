import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] aa )
	{
		int n;
		Scanner in = new Scanner( System.in );
		BigInteger[] ans;
		ans = new BigInteger[ 1001 ];
		ans[ 0 ] = BigInteger.ONE;
		ans[ 1 ] = BigInteger.valueOf( 2 );

		for( int i = 2; i <= 1000; ++i )
			ans[ i ] = ans[ i-1 ].add( ans[ i-2 ] );
		while( in.hasNext() )
		{
			n = in.nextInt();
			System.out.println( ans[ n ] );
		}
	}
}

