#ifndef _MAP_H_
#define _MAP_H_

#define FILE_ADDRESS "resources/map.txt"

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

#define EMPTY_SPACE '.'
#define PACMAN 'P'

typedef struct map
{
    char **matrix;
    int rows;
    int columns;
} Map;

typedef struct pacman
{
    int x;
    int y;
} Pacman;

/**
 * Check if the file is in the path resources/map.txt.
 */
void check_file(FILE *file);

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
 * Find the pacman in the map.
 */
void find_pacman(Map *map, Pacman *pacman);

/**
 * Initialize the game.
 */
void start_game(Map *map, Pacman *pacman);

/**
 * Returns if the game is over.
 */
int endgame();

/**
 * Print the game map in the Terminal.
 */
void print_map(Map map);

/**
 * Move the pacman through the map.
 */
void move(Map *map, Pacman *pac);

#endif
