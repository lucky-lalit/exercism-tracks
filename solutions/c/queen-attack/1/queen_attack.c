#include "queen_attack.h"
#include <stdio.h>
#include <stdlib.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    int row_diff = abs(queen_1.row - queen_2.row);
    int col_diff = abs(queen_1.column - queen_2.column);
    // printf("debug 1 %i\n",row_diff);
    if (queen_1.row > 7 || queen_1.column > 7 || queen_2.row > 7 || queen_2.column > 7 || ((queen_1.row == queen_2.row) && (queen_1.column == queen_2.column)))
        return INVALID_POSITION;
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column || row_diff == col_diff)
    {
        printf("attack");
        return CAN_ATTACK;
    }
    
    return CAN_NOT_ATTACK;
}