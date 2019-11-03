//
// Created by waether on 03/11/19.
//

#ifndef PHANTOMOPERAAI_MOVE_HPP
#define PHANTOMOPERAAI_MOVE_HPP

typedef struct s_Move {
    unsigned int    _characterIdx;
    unsigned int    _positionIdx;
    unsigned int    _activatePowerIdx;
    unsigned int    _handlePowerIdx;
    unsigned int    _powerExitIdx;
    unsigned int    _powerRoomIdx;
    unsigned int    _powerMoveIdx;
} Move;

#endif //PHANTOMOPERAAI_MOVE_HPP
