#include<cstdio>
#include<cctype>

int main()
{
    char in, convert[] = { "22233344455566677778889999" };

    while( scanf( "%c", &in ) != EOF )
        putchar( isalpha( in )? convert[ in-'A' ] : in );

	return 0;
}