import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] aa )
	{   
		int n;
		Scanner in = new Scanner( System.in );
		BigInteger[] ans;
		ans = new BigInteger[ 51 ];
		ans[ 0 ] = BigInteger.valueOf( 0 );
		ans[ 1 ] = BigInteger.valueOf( 1 );
		ans[ 2 ] = BigInteger.valueOf( 2 );

		for( int i = 3; i <= 50; ++i )
			ans[ i ] = ans[ i-1 ].add( ans[ i-2 ] );
		while( in.hasNext() )
		{   
			n = in.nextInt();
			if( n == 0 )
				break;
			System.out.println( ans[ n ] );
		}   
	}   
}

