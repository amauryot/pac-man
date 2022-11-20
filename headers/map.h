#ifndef _MAP_H_
#define _MAP_H_

#define FILE_ADDRESS "resources/map.txt"

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

#define EMPTY_SPACE '.'
#define PACMAN 'P'
#define GHOST 'G'
#define HORIZONTAL_WALL '-'
#define VERTICAL_WALL '|'

typedef struct map
{
    char **matrix;
    int rows;
    int columns;
} Map;

typedef struct character
{
    char symbol;
    int previous_x;
    int previous_y;
    int actual_x;
    int actual_y;
} Character;

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
 * Find pacman in the map.
 */
void find_pacman(Map *map, Character *pacman);

/**
 * Initialize the game.
 */
void start_game(Map *map, Character *pacman);

/**
 * Returns if the game is over.
 */
int endgame();

/**
 * Returns the char (w, a, s, d) that represents the movement (up, left, down, right).
 */
char get_move();

/**
 * Check if the character collide with a wall or others characters.
 */
int collide(Map map, Character *character);

/**
 * Update the character position.
 */
void update_position(Map map, Character *character);

/**
 * Move the pacman through the map.
 */
void move_pacman(Map map, Character *pacman);

/**
 * Replicate the map.
 */
void copy_map(Map *replica, Map original);

/**
 * Generate a random move for the ghosts.
 */
void random_move(Character *ghost);

/**
 * Move the ghosts.
 */
void move_ghosts(Map map, Character *ghost);

#endif
