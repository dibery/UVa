import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger[] ans = new BigInteger[ 251 ];
		int n;

		ans[ 0 ] = ans[ 1 ] = BigInteger.valueOf( 1 );
		for( int i = 2; i <= 250; ++i )
			ans[ i ] = ans[ i-1 ].add( ans[ i-2 ].add( ans[ i-2 ] ) );

		while( in.hasNext() )
		{
			n = in.nextInt();
			System.out.println( ans[ n ] );
		}
	}
}
