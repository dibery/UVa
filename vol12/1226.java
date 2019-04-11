import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] argv )
	{
		Scanner in = new Scanner( System.in );
		int t = in.nextInt();
		BigInteger divisor, dividend; //dividend / divisor

		for( int i = 0; i < t; ++i )
		{
			divisor = new BigInteger( in.next() );
			dividend = new BigInteger( in.next() );
			System.out.println( dividend.mod( divisor ) );
		}
	}
}
