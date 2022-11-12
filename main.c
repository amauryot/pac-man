#include <stdio.h>
#include <locale.h>
#include "headers/map.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Map map;

    load_map(&map);
    
    print_map(map);

    free_memory(&map);

    return 0;
}
