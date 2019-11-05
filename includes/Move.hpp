//
// Created by waether on 03/11/19.
//

#ifndef PHANTOMOPERAAI_MOVE_HPP
#define PHANTOMOPERAAI_MOVE_HPP

typedef struct      s_Move {
    int    _characterIdx; // 0 - 3 NEED CHECK
    int    _positionIdx; // 0 - 9 NEED CHECK
    int    _activatePowerIdx; // 0 - 1
    int    _handlePowerIdx; // NEED CHECK
    int    _powerExitIdx; // NEED CHECK
    int    _powerRoomIdx; // 0 - 9 NEED CHECK
    int    _powerMoveIdx; // NEED CHECK
    int    _powerMoveTargetIdx; // NEED CHECK
}                   Move;

#endif //PHANTOMOPERAAI_MOVE_HPP
