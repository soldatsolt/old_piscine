#include    <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int g_x;
int g_y;

void    free_mass(char m[g_y][g_x], int x, int y)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < y)
    {
        while (j < x)
        {
            m[i][j] = ' ';
            j++;
        }
        j = 0;
        i++;
    }
}

void    put_horiz(char m[g_y][g_x], int x, int y)
{
    int i;
    
    i = 1;
    while (i < x)
    {
        m[0][i] = '*';
        m[y - 1][i] = '*';
        i++;
    }
}

void    put_vertic(char m[g_y][g_x], int x, int y)
{
    int i;
    
    i = 0;
    while (i < y)
    {
        m[i][0] = '*';
        m[i][x - 1] = '*';
        i++;
    }
    m[0][x - 1] = '\\';
    m[y - 1][x - 1] = '/';
    m[0][0] = '/';
    m[y - 1][0] = '\\';
}

void    rush01(int x, int y)
{
    char    m[y][x];
    int        i;
    int        j;
    
    g_x = x;
    g_y = y;
    i = 0;
    j = 0;
    free_mass(m, x, y);
    put_horiz(m, x, y);
    put_vertic(m, x, y);
    while (i < y)
    {
        while (j < x)
        {
            ft_putchar(m[i][j]);
            j++;
        }
        j = 0;
        ft_putchar('\n');
        i++;
    }
}

int main()
{
    rush01(2,5);
    return (0);
}
