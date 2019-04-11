import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] aa )
	{
		int n;
		Scanner in = new Scanner( System.in );
		BigInteger[] ans = new BigInteger[ 4001 ];
		ans[ 0 ] = BigInteger.ZERO;
		ans[ 1 ] = BigInteger.ONE;
		for( int i = 2; i <= 4000; ++i )
			ans[ i ] = ans[ i-1 ].add( ans[ i-2 ] );

		while( in.hasNext() )
		{
			n = in.nextInt();
			if( n == 0 )
				break;
			System.out.println( ans[ n*2 ] );
		}
	}
}
