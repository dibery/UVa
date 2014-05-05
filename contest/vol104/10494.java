import java.util.Scanner;
import java.math.BigInteger;
import java.lang.String;

public class Main
{
	public static void main( String[] argv )
	{
		Scanner in = new Scanner( System.in );
		BigInteger a, b;
		String sign;

		while( in.hasNext() )
		{
			a = new BigInteger( in.next() );
			sign = in.next();
			b = new BigInteger( in.next() );

			if( sign.equals( "%" ) )
				System.out.println( a.mod( b ) );
			else
				System.out.println( a.divide( b ) );
		}
	}
}				
