#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "headers/map.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Map map;
    Character pacman;
    Character ghost;

    pacman.symbol = PACMAN;
    ghost.symbol = GHOST;

    start_game(&map, &pacman);

    while (!endgame())
    {
        //system("cls");
        print_map(map);
        move_pacman(map, &pacman);
        move_ghosts(map, &ghost);
    }

    free_memory(&map);

    return 0;
}
