//
// Created by waether on 20/10/19.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "Move.hpp"
#include "GameData.hpp"
#include "Question.hpp"
#include "Net.hpp"
#include "KeyEvaluator.hpp"
#include "GameState.hpp"

int main(int argc, char const *argv[]) {

    // Handling Player Type (Fantom / Inspector)

//    int playerType = -1;
//    if (argc < 2) {
//        Logger::Error() << "Need on parameter : Fantom / Inspector." << std::endl;
//        return -1;
//    }
//
//    if (std::string(argv[1]) == "Fantom")
//        playerType = 0;
//    else if (std::string(argv[1]) == "Inspector")
//        playerType = 1;
//    else {
//        Logger::Error() << "Parameter need to be : Fantom / Inspector." << std::endl;
//        return -1;
//    }

    // Program Setup

    Net Con("127.0.0.1", 12000);

    Con.Connect();

    std::string msg_received;
    bool GameOn = true;
    Move currentMove = {42, 42, 42, 42, 42, 42, 42};

    while (GameOn) {

        try {
            msg_received = Con.ReceiveMsg();
        } catch (NetException::PearDisconnected & e) {
            Logger::Error() << "Pear Disconnected." << std::endl;
            GameOn = false;
            continue;
        }

        if (msg_received.empty())
        {
            Logger::Log() << "Skipping message since empty." << std::endl;
            continue;
        }

        Logger::Log() << "Parsing JSON ..." << std::endl;

        nlohmann::json j = nlohmann::json::parse(msg_received.c_str());

        Logger::Log() << "JSON Parsed." << std::endl;

        Question::Questions gQuestion = Question::Unknown;
        GameState gState;
        GameData gData;

        for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
            switch (KeyEvaluator::Evaluate(it.key())) {
                case KeyEvaluator::Question :
                    Logger::Log() << "Question Key Found." << std::endl;
                    gQuestion = Question::Evaluate(it.value());
                    break;
                case KeyEvaluator::Data :
                    Logger::Log() << "Data Key Found." << std::endl;
                    gData.Update(it.value());
                    break;
                case KeyEvaluator::GameState :
                    Logger::Log() << "GameState Key Found." << std::endl;
                    gState.Update(it.value());
                    break;
                case KeyEvaluator::Unknown :
                    Logger::Error() << "Found Unknown Key : " << it.key() << std::endl;
                    break;
                default :
                    Logger::Error() << "Found Unknown Key : " << it.key() << std::endl;
                    break;
            }
        }

        Logger::Log() << "Choosing Answer ..." << std::endl;

        Logger::Error() << "Current Player : " << gState.getCurrentPlayer() << std::endl;

//*/
            switch (gQuestion) {
                case Question::CharacterSelection :

                    // Move = MoveGenerator.Generate(GameState, GameData);

                    if (currentMove._characterIdx == 42)
                        Logger::Error() << "Character Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._characterIdx));
                    break;
                case Question::PositionSelection:
                    if (currentMove._positionIdx == 42)
                        Logger::Error() << "Position Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._positionIdx));
                    break;
                case Question::ActivatePower:
                    if (currentMove._activatePowerIdx == 42)
                        Logger::Error() << "Activate Power Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._activatePowerIdx));
                    break;
                case Question::HandlePower:
                    if (currentMove._handlePowerIdx == 42)
                        Logger::Error() << "Handle Power Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._handlePowerIdx));
                    break;
                case Question::PowerExit:
                    if (currentMove._powerExitIdx == 42)
                        Logger::Error() << "Power Exit Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._powerExitIdx));
                    break;
                case Question::PowerRoom:
                    if (currentMove._powerRoomIdx == 42)
                        Logger::Error() << "Power Room Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._powerRoomIdx));
                    break;
                case Question::PowerMove:
                    if (currentMove._powerMoveIdx == 42)
                        Logger::Error() << "Power Move Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._powerMoveIdx));
                    break;
                case Question::PowerMoveTarget:
                    if (currentMove._powerMoveTargetIdx == 42)
                        Logger::Error() << "Power Move Target Index Answer Uninitialized" << std::endl;
                    Logger::Log() << "Sending Answer ..." << std::endl;
                    Con.SendMsg(std::to_string(currentMove._powerMoveTargetIdx));
                    break;
                case Question::Unknown:
                    Logger::Error() << "Invalid Question Received." << std::endl;
                    break;
                default:
                    Logger::Error() << "Invalid Question Received." << std::endl;
                    break;
            }
//*/

        Con.SendMsg("1"); // Temporary Answer

        Logger::Log() << "Done. Waiting for Server ..." << std::endl;

    }

    Logger::Log() << "Client Now Closing." << std::endl;

    return 0;
}
