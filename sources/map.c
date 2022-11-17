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
        printf("\nArquivo não encontrado!");
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
                pacman->actual_x = i;
                pacman->actual_y = j;

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
 * Check if the pacman collide with a wall or ghosts.
 */
int collide(Map *map, Pacman *pacman)
{
    return (map->matrix[pacman->actual_x][pacman->actual_y] != EMPTY_SPACE);
}

/**
 * Update the pacman position.
 */
void update_pacman(Map *map, Pacman *pacman)
{
    map->matrix[pacman->previous_x][pacman->previous_y] = EMPTY_SPACE;
    map->matrix[pacman->actual_x][pacman->actual_y] = PACMAN;
}

/**
 * Move the pacman through the map.
 */
void move(Map *map, Pacman *pacman)
{
    char move;
    scanf(" %c", &move);

    pacman->previous_x = pacman->actual_x;
    pacman->previous_y = pacman->actual_y;

    switch (move)
    {
    case UP:
        (pacman->actual_x)--;
        break;
    case LEFT:
        (pacman->actual_y)--;
        break;
    case DOWN:
        (pacman->actual_x)++;
        break;
    case RIGHT:
        (pacman->actual_y)++;
        break;
    default:
        break;
    }

    if (collide(map, pacman))
    {
        pacman->actual_x = pacman->previous_x;
        pacman->actual_y = pacman->previous_y;
    }

    update_pacman(map, pacman);
}
