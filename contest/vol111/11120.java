import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigDecimal ans, two = BigDecimal.valueOf( 2 );

		while( in.hasNext() )
		{
			int N = in.nextInt(), p;
			if( N == 0 )
				break;
			ans = BigDecimal.valueOf( N );
			BigDecimal n = ans;
			ans = BigDecimal.valueOf( Math.sqrt( N ) );
			for( int i = 0; i < 7; ++i )
				ans = ans.add( n.divide( ans, 1400, RoundingMode.HALF_UP ) ).divide( two );
			String s = ans.toPlainString().replaceFirst( "\\x2E", "" );
			for( p = 0; ; ++p )
				if( s.charAt( p ) == s.charAt( p + 1 ) && s.charAt( p ) == s.charAt( p + 2 ) )
					break;
			System.out.println( N + " " + p + " " + s.charAt( p ) );
		}
	}
}
