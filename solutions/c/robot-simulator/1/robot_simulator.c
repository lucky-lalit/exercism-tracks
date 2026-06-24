#include "robot_simulator.h"
#include <stdio.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    printf("debug1 %d\n",direction);
    printf("debug2 %i\n",x);
    printf("debug3 %i\n",y);
    robot_status_t result;
    result.direction = direction;
    result.position.x = x;
    result.position.y = y;
    return result;
    
}
void robot_move(robot_status_t *robot, const char *commands)
{   
    printf("debug5 %s\n",commands);
    printf("debug 6 %i\n",(*robot).direction);
    for (int i = 0; commands[i] != '\0'; i++)
    {
        if (commands[i] == 'R')
            (*robot).direction = ((*robot).direction + 1) % DIRECTION_MAX;
        else if (commands[i] == 'L')
            (*robot).direction = ((*robot).direction + 3) % DIRECTION_MAX;
    
        else if (commands[i] == 'A')
        {
        if ((*robot).direction == DIRECTION_NORTH)
            (*robot).position.y += 1;
        else if ((*robot).direction == DIRECTION_EAST)
            (*robot).position.x++;
        else if ((*robot).direction == DIRECTION_SOUTH)
            (*robot).position.y--;
        else if ((*robot).direction == DIRECTION_WEST)
            (*robot).position.x--;
    }
    }   
}