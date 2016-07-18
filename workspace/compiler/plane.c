#include <stdio.h>
#define hight   20
#define wright  14
int main()
{
    int     i, j;
    static int  a[hight][wright];
    for ( i = 0; i < hight; i++ )
    {
        for ( j = 0; j < wright; j++ )
        {
            if ( j == 0 || j == (wright - 1) || i == 0 || i == (hight - 1) )
                a[i][j] = 1;
        }
    }
    for ( i = 0; i < hight; i++ )
    {
        for ( j = 0; j < wright; j++ )
        {
            if ( a[i][j] == 1 )
                printf( "»Ø" );
            else
                printf( "  " );
        }
        printf( "\n" );
    }

    return 0;
}
