import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int t = 0;

		while( in.hasNext() )
		{
			int c = in.nextBigDecimal().compareTo( in.nextBigDecimal() );
			if( c == 1 )
				System.out.println( "Case " + ++t + ": Bigger" );
			else if( c == 0 )
				System.out.println( "Case " + ++t + ": Same" );
			else
				System.out.println( "Case " + ++t + ": Smaller" );
		}
	}
}
