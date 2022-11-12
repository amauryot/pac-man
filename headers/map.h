#ifndef _MAP_H_
#define _MAP_H_

typedef struct map
{
    char **matrix;
    int rows;
    int columns;
} Map;

/**
 * Allocate memory for the map matrix.
 */
void allocate_memory(Map *map);

/**
 * Free the memory allocated for the map matrix.
 */
void free_memory(Map *map);

/**
 * Copy the file content into map matrix.
 */
void copy_file(FILE *file, Map *map);

/**
 * Load the game map.
 */
void load_map(Map *map);

/**
 * Print the game map in the Terminal.
 */
void print_map(Map map);

#endif
