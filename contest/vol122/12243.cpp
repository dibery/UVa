#include<cstdio>
#include<cctype>

int main()
{
    char last, word[ 21 ], begin;
    bool newline = true, tau = true;

    while( scanf( "%s%c", word, &last ) && *word != '*' )
    {
        if( newline )
            begin = tolower( *word );
        else//
            if( tolower( *word ) != begin )
                tau = false;
        newline = last == '\n';
        if( last == '\n' )
            puts( tau? "Y" : "N" ), tau = true;
    }

    return 0;
}