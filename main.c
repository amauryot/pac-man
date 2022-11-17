#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "headers/map.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Map map;
    Pacman pacman;

    start_game(&map, &pacman);
    
    while (!endgame())
    {
        system("cls");
        print_map(map);
        move(&map, &pacman);
    }

    free_memory(&map);
    
    return 0;
}
