#include <stdio.h>
#include <stdlib.h>
#include "../headers/map.h"

/**
 * Check if the file is in the path resources/map.txt.
 */
void check_file(FILE *file)
{
    if (file == NULL)
    {
        printf("\nArquivo n�o encontrado!");
        exit(1);
    }
}

/**
 * Allocate memory for the map matrix.
 */
void allocate_memory(Map *map)
{
    map->matrix = malloc(sizeof(char *) * map->rows);

    for (int i = 0; i < map->rows; i++)
    {
        map->matrix[i] = malloc(sizeof(char) * (map->columns + 1));
    }
}

/**
 * Free the memory allocated for the map matrix.
 */
void free_memory(Map *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        free(map->matrix[i]);
    }

    free(map->matrix);
}

/**
 * Copy the file content into map matrix.
 */
void copy_file(FILE *file, Map *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        fscanf(file, "%s", map->matrix[i]);
    }
}

/**
 * Load the game map.
 */
void load_map(Map *map)
{
    FILE *file = fopen(FILE_ADDRESS, "r");

    check_file(file);

    fscanf(file, "%d %d", &(map->rows), &(map->columns));
    allocate_memory(map);

    copy_file(file, map);

    fclose(file);
}

/**
 * Find the pacman in the map.
 */
void find_pacman(Map *map, Pacman *pacman)
{
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->columns; j++)
        {
            if (map->matrix[i][j] == PACMAN)
            {
                pacman->x = i;
                pacman->y = j;

                return;
            }
        }
    }
}

/**
 * Initialize the game.
 */
void start_game(Map *map, Pacman *pacman)
{
    load_map(map);
    find_pacman(map, pacman);
}

/**
 * Returns if the game is over.
 */
int endgame()
{
    return 0;
}

/**
 * Print the game map in the Terminal.
 */
void print_map(Map map)
{
    for (int i = 0; i < map.rows; i++)
    {
        printf("%s\n", map.matrix[i]);
    }
}

/**
 * Move the pacman through the map.
 */
void move(Map *map, Pacman *pacman)
{
    char move;
    scanf(" %c", &move);

    map->matrix[pacman->x][pacman->y] = EMPTY_SPACE;

    switch (move)
    {
    case UP:
        (pacman->x)--;
        break;
    case LEFT:
        (pacman->y)--;
        break;
    case DOWN:
        (pacman->x)++;
        break;
    case RIGHT:
        (pacman->y)++;
        break;
    default:
        break;
    }

    map->matrix[pacman->x][pacman->y] = PACMAN;
}
