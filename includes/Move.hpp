//
// Created by waether on 03/11/19.
//

#ifndef PHANTOMOPERAAI_MOVE_HPP
#define PHANTOMOPERAAI_MOVE_HPP

typedef struct      s_Move {
    int    _characterIdx;
    int    _positionIdx;
    int    _activatePowerIdx;
    int    _handlePowerIdx;
    int    _powerExitIdx;
    int    _powerRoomIdx;
    int    _powerMoveIdx;
    int    _powerMoveTargetIdx;
}                   Move;

#endif //PHANTOMOPERAAI_MOVE_HPP
