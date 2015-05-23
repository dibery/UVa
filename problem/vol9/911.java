import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		BigInteger[] fact = new BigInteger[ 101 ];
		Scanner in = new Scanner( System.in );

		fact[ 0 ] = BigInteger.ONE;
		for( int i = 1; i <= 100; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );

		while( in.hasNext() )
		{
			int pow = in.nextInt(), item = in.nextInt();
			BigInteger ans = fact[ pow ];

			for( int i = 0; i < item; ++i )
				ans = ans.divide( fact[ in.nextInt() ] );
			System.out.println( ans );
		}
	}
}
