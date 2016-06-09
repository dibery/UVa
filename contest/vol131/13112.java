// 13112
import java.util.Scanner;
import java.awt.Polygon;
import java.awt.geom.Line2D;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int[] x = new int[ 500 ], y = new int[ 500 ];
		int side, pt, ans, px, py;

		for( int t = in.nextInt(); t-- > 0; )
		{
			side = in.nextInt();
			pt = in.nextInt();
			ans = 0;
			for( int i = 0; i < side; ++i )
			{
				x[ i ] = in.nextInt();
				y[ i ] = in.nextInt();
			}
			Polygon p = new Polygon( x, y, side );
			for( int i = 0; i < pt; ++i )
			{
				px = in.nextInt();
				py = in.nextInt();
				boolean ok = p.contains( px, py );
				for( int j = 0; j < side; ++j )
					ok &= Line2D.ptSegDist( x[ j ], y[ j ], x[ ( j + 1 ) % side ], y[ ( j + 1 ) % side ], px, py ) > 0;
				if( ok )
					++ans;
			}
			System.out.println( ans );
		}
	}
}
