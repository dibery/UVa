import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
	public static void main( String args[] )
	{
		Scanner in = new Scanner( System.in );
		BigDecimal x, y, THREE = BigDecimal.valueOf( 3 ), T = BigDecimal.ONE.divide( THREE, 100, BigDecimal.ROUND_HALF_DOWN ), T2 = T.add( T ), ZERO = BigDecimal.ZERO, ONE = BigDecimal.ONE;
		int t = in.nextInt(), ans;

		for( int n = 1; n <= t; ++n )
		{
			x = in.nextBigDecimal();
			y = in.nextBigDecimal();
			BigDecimal x1 = ZERO, y1 = ZERO, x2 = ONE, y2 = ONE, Lx = T, Ly = T, Hx = T2, Hy = T2;

			for( ans = 0; !( in( x, Lx, Hx ) && in( y, Ly, Hy ) ) && ans < 100; ++ans )
			{
				if( x.compareTo( Lx ) < 0 )
					x2 = Lx;
				else if( x.compareTo( Hx ) > 0 )
					x1 = Hx;
				else
				{
					x1 = Lx;
					x2 = Hx;
				}
				if( y.compareTo( Ly ) < 0 )
					y2 = Ly;
				else if( y.compareTo( Hy ) > 0 )
					y1 = Hy;
				else
				{
					y1 = Ly;
					y2 = Hy;
				}
				Lx = x1.add( x2.subtract( x1 ).divide( THREE, 100, BigDecimal.ROUND_HALF_DOWN ) );
				Ly = y1.add( y2.subtract( y1 ).divide( THREE, 100, BigDecimal.ROUND_HALF_DOWN ) );
				Hx = x2.subtract( x2.subtract( x1 ).divide( THREE, 100, BigDecimal.ROUND_HALF_DOWN ) );
				Hy = y2.subtract( y2.subtract( y1 ).divide( THREE, 100, BigDecimal.ROUND_HALF_DOWN ) );
			}

			System.out.println( "Case " + n + ": " + ( ans == 100? -1 : ans ) );
		}
	}

	public static boolean in( BigDecimal a, BigDecimal b, BigDecimal c )
	{ return a.compareTo( b ) >= 0 && a.compareTo( c ) <= 0; }
}
