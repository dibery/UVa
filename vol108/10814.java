import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] argv )
	{
		Scanner in = new Scanner( System.in );
		int test = in.nextInt();
		BigInteger a, b, GCD;

		for( int i = 0; i < test; ++i )
		{
			a = new BigInteger( in.next() );
			in.next();
			b = new BigInteger( in.next() );
			GCD = a.gcd( b );
			System.out.println( a.divide( GCD ) + " / " + b.divide( GCD ) );
		}
	}
}
