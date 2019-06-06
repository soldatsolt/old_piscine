#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int x;
    int s;
    int k;
    int y;
    int nach_zn;
    int flag_er;
    int temp;
    
    x = 0;
    y = 1;
    nach_zn = 0;
    flag_er = 0;
    
    
    // ТУТ СЕЙЧАС БУДЕМ ПРОВЕРЯТЬ НА ВСЯКИЕ УСЛОВИЯ ЧТОБЫ ВЫДАТЬ ЭРОР ЕСЛИ ЧТО
    
    
    while (y < 10)
    {
        while (x < 9)
        {
            if (argv[y][x] != '.' && (argv[y][x] > '9' || argv[y][x] < '1'))
                flag_er = 1;
            x++;                                    // ПРОВЕРЯЕМ НА ТО, ЕСТЬ ЛИ ПОСТОРОННИЕ СИМВОЛЫ
        }                                           // НУ КРОМЕ 1-9 И .
        x = 0;
        y++;
    }
    if (flag_er)
        printf("Error\n");
    x = 0;
    y = 1;
    
    
    
    while (y < 10)
    {
        while (x < 9)
        {
            if (argv[y][x] == '.') // ПРОВЕРЯЕМ СКОЛЬКО СНАЧАЛА ТОЧЕК (КОЛВО ЦИФР = 81 - КОЛВО ТОЧЕК)
                nach_zn++;         // ЕСЛИ < 17, ТО ВЫДАЕМ ОШИБКУ
            x++;
        }
        x = 0;
        y++;
    }
    nach_zn = 81 - nach_zn; // ВОТ ТУТ ЭТО УЖЕ КОЛВО ЦИФР
    if (nach_zn < 17)
        printf("Error\n");
    
    printf("%i\n", nach_zn);
    x = 0;
    y = 1;
    
    
                                    //СЕЙЧАС БУДЕМ НАХОДИТЬ ПОВТОРЕНИЯ ЦИФР В СТОЛБАХ И СТРОКАХ (их не дб)
    
    
    while (y < 10)
    {
        while (x < 9)
        {
            temp = x;
            if (x < 8)
            {
                while (argv[y][x++])
                {
                    if ((argv[y][temp] == argv[y][x]) && argv[y][temp] != '.')     //ПРОВЕРЯЕМ ПО СТРОКАМ
                        flag_er = 1;
                }
            }
            x = temp;
            
            printf("%c ", argv[y][x]);
           
            x++;
        }                                       //ВОТ ТУТ ПРОВЕРЯЕМ НА ПОВТОРЕНИЯ В СТРОКАХ И СТОЛБИКАХ
        x = 0;
        printf("\n");
        y++;
    }
    if (flag_er)
        printf("Error\n");
    
    x = 0;
    y = 1;
    
    while (y < 10)
    {
        while (x < 9)
        {
        
            printf("%c ", argv[y][x]);
            
            temp = y;
            if (y < 9)
            {
                while (argv[y++][x])
                {
                    if ((argv[temp][x] == argv[y][x]) && argv[temp][x] != '.')     //ПРОВЕРЯЕМ ПО СТОЛБЦАМ - TYT PROBLEMA
                        flag_er = 1;
                }
            }
            y = temp;
            
            
            x++;
        }                                       //ВОТ ТУТ ПРОВЕРЯЕМ НА ПОВТОРЕНИЯ В СТРОКАХ И СТОЛБИКАХ
        x = 0;
        printf("\n");
        y++;
    }
    if (flag_er)
        printf("Error\n");
    
    
    
    // ВЫВОДИМ НАЧАЛЬНУЮ МАТРИЦУ НА ВСЯКИЙ
    /*
    while (y < 10)
    {
        while (x < 9)
        {
            printf("%c ", argv[y][x]);
            x++;
        }
        printf("\n");
        x = 0;
        y++;
    }*/
    
    return (0);
}
