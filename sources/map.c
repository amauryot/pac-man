#include <stdio.h>
#include <stdlib.h>
#include "../headers/map.h"

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
    FILE *file = fopen("resources/map.txt", "r");

    if (file != NULL)
    {
        fscanf(file, "%d %d", &(map->rows), &(map->columns));
        allocate_memory(map);
        copy_file(file, map);
    }
    else
    {
        printf("\nArquivo não encontrado!");
        exit(1);
    }
}

/**
 * Print the game map into Terminal.
 */
void print_map(Map map)
{
    for (int i = 0; i < map.rows; i++)
    {
        printf("%s\n", map.matrix[i]);
    }
}
