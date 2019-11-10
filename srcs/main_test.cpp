//
// Created by waether on 20/10/19.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <TreeHandler.hpp>
#include "Move.hpp"
#include "GameData.hpp"
#include "Question.hpp"
#include "Net.hpp"
#include "KeyEvaluator.hpp"
#include "GameState.hpp"

int main(int argc, char const *argv[]) {

    int playerType = -1;

    if (argc < 2) {
        Logger::Error() << "Need on parameter : Ghost / Inspector." << std::endl;
        return -1;
    }

    if (std::string(argv[1]) == "Ghost" || std::string(argv[1]) == "-g")
        playerType = 0;
    else if (std::string(argv[1]) == "Inspector" || std::string(argv[1]) == "-i")
        playerType = 1;
    else {
        Logger::Error() << "Parameter need to be : Ghost -g / Inspector -i." << std::endl;
        return -1;
    }

    // Program Setup

    Net Con("127.0.0.1", 12000);

    Con.Connect();

    std::string msg_received;
    bool GameOn = true;
    Move currentMove = {-1, -1, -1, -1, -1, -1, -1};

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

        if (gQuestion == Question::CharacterSelection) {
            TreeHandler Hdl;
            Move move = Hdl.GetBestMove(gState, playerType);
        }

        std::string to_send;
        std::cout << "[IPT] Please Enter Answer : ";

        std::cin >> to_send;

        Con.SendMsg(to_send);

        Logger::Log() << "Done. Waiting for Server ..." << std::endl;

    }

    Logger::Log() << "Client Now Closing." << std::endl;

    return 0;
}
