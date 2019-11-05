//
// Created by waether on 03/11/19.
//

#ifndef PHANTOMOPERAAI_MOVE_HPP
#define PHANTOMOPERAAI_MOVE_HPP

typedef struct      s_Move {
    unsigned int    _characterIdx; // 0 - 3 NEED CHECK
    unsigned int    _positionIdx; // 0 - 9 NEED CHECK
    unsigned int    _activatePowerIdx; // 0 - 1
    unsigned int    _handlePowerIdx; // NEED CHECK
    unsigned int    _powerExitIdx; // NEED CHECK
    unsigned int    _powerRoomIdx; // 0 - 9 NEED CHECK
    unsigned int    _powerMoveIdx; // NEED CHECK
    unsigned int    _powerMoveTargetIdx; // NEED CHECK
}                   Move;

#endif //PHANTOMOPERAAI_MOVE_HPP
