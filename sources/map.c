#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
 * Find pacman in the map.
 */
void find_pacman(Map *map, Character *pacman)
{
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->columns; j++)
        {
            if (map->matrix[i][j] == pacman->symbol)
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
void start_game(Map *map, Character *pacman)
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
 * Returns the char (w, a, s, d) that represents the movement (up, left, down, right).
 */
char get_move()
{
    char move;
    scanf(" %c", &move);

    return move;
}

/**
 * Check if the character collide with a wall or others character.
 */
int collide(Map map, Character *character)
{
    return (map.matrix[character->actual_x][character->actual_y] != EMPTY_SPACE);
}

/**
 * Update the character position.
 */
void update_position(Map map, Character *character)
{
    map.matrix[character->previous_x][character->previous_y] = EMPTY_SPACE;
    map.matrix[character->actual_x][character->actual_y] = character->symbol;
}

/**
 * Move the pacman through the map.
 */
void move_pacman(Map map, Character *pacman)
{
    pacman->previous_x = pacman->actual_x;
    pacman->previous_y = pacman->actual_y;

    switch (get_move())
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

    update_position(map, pacman);
}

/**
 * Replicate the map.
 */
void copy_map(Map *replica, Map original)
{
    replica->rows = original.rows;
    replica->columns = original.columns;

    allocate_memory(replica);

    for (int i = 0; i < original.rows; i++)
    {
        strcpy(replica->matrix[i], original.matrix[i]);
    }
}

/**
 * Generate a random move for the ghosts.
 */
void random_move(Character *ghost)
{
    int possibilities[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int random = rand() % 4;

    ghost->actual_x += possibilities[random][0];
    ghost->actual_y += possibilities[random][1];
}

/**
 * Move the ghosts.
 */
void move_ghosts(Map map, Character *ghost)
{
    Map replica;

    copy_map(&replica, map);

    srand(time(0));

    for (int i = 0; i < replica.rows; i++)
    {
        for (int j = 0; j < replica.columns; j++)
        {
            if (replica.matrix[i][j] == ghost->symbol)
            {
                ghost->actual_x = i;
                ghost->actual_y = j;

                ghost->previous_x = ghost->actual_x;
                ghost->previous_y = ghost->actual_y;

                //random_move(ghost);

                do
                {
                    ghost->actual_x = ghost->previous_x;
                    ghost->actual_y = ghost->previous_y;

                    random_move(ghost);

                } while (collide(replica, ghost));

                update_position(map, ghost);
            }
        }
    }

    free_memory(&replica);
}
