#include <stdio.h>
#include "../headers/interface.h"

char ghost[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char wall[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char pacman[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};
/*
char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};*/

char empty_space[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

/**
 * Print the elements interface.
 */
void print_element(char element[4][7], int piece)
{
    printf("%s", element[piece]);
}

/**
 * Print the game map in the Terminal.
 */
void print_map(Map map)
{
    for (int i = 0; i < map.rows; i++)
    {
        for (int piece = 0; piece < 4; piece++)
        {
            for (int j = 0; j < map.columns; j++)
            {
                switch (map.matrix[i][j])
                {
                case GHOST:
                    print_element(ghost, piece);
                    break;

                case HORIZONTAL_WALL:
                case VERTICAL_WALL:
                    print_element(wall, piece);
                    break;

                case PACMAN:
                    print_element(pacman, piece);
                    break;

                case EMPTY_SPACE:
                    print_element(empty_space, piece);
                    break;
                    
                default:
                    break;
                }
            }

            printf("\n");
        }
    }
}
