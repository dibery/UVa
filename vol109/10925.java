import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] argv )
	{
		Scanner in = new Scanner( System.in );
		BigInteger sum, each, alloc, friend;
		long item, t = 1;

		while( in.hasNext() )
		{
			item = in.nextLong();
			if( item == 0 )
				break;
			friend = new BigInteger( in.next() );
			sum = BigInteger.ZERO;

			for( int i = 0; i < item; ++i )
			{
				each = new BigInteger( in.next() );
				sum = sum.add( each );
			}
			alloc = sum.divide( friend );
			System.out.println( "Bill #"+ t + " costs " + sum + ": each friend should pay " + alloc + "\n" );
			++t;
		}
	}
}
