#include<cstdio>
const double a = 315146.743627721, b = 511299.166334352, c = 173554.090037928;

int main()
{
    double in;
    while( scanf( "%lf", &in ) == 1 )
        printf( "%.3f %.3f %.3f\n", a*(in/1000)*(in/1000), b*(in/1000)*(in/1000), c*(in/1000)*(in/1000) );

	return 0;
}