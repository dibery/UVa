import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] oops )
	{
		BigInteger a, b;
		Scanner in = new Scanner( System.in );
		int t = in.nextInt();

		for( int i = 0; i < t; ++i )	
		{
			a = new BigInteger( in.next() );
			b = new BigInteger( in.next() );
			System.out.println( a.subtract( b ) );
		}
	}
}
