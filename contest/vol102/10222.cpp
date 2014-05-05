#include<cstdio>
#include<cctype>
#include<cstring>

int main()
{
    char input, map[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    while( ( input = getchar() ) != EOF )
            putchar( input != ' ' && input != '\n' ? *( strchr( map, tolower( input ) ) - 2 ) : input );

    return 0;
}
