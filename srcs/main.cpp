//
// Created by waether on 20/10/19.
//

#include <iomanip>
#include <GameData.hpp>
#include "Net.hpp"
#include "Logger.hpp"
#include "KeyEvaluator.hpp"
#include "GameState.hpp"
#include "FantomAI.hpp"
#include "InspectorAI.hpp"

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

    FantomAI Phantom;
    InspectorAI Detective;

    std::string msg_received;
    bool GameOn = true;

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

        // Parsing JSON

        Logger::Log() << "Parsing JSON ..." << std::endl;
        nlohmann::json j = nlohmann::json::parse(msg_received.c_str());
        Logger::Log() << "JSON Parsed." << std::endl;

        // Reading Data

        Question::Questions gQuestion;
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

        // AI Part

        Logger::Log() << "Choosing Answer ..." << std::endl;

//        if (playerType == 0) // Fantom
//            Logger::Debug() << "Fantom choose : " << Phantom.MakeChoice(gQuestion, gData, gState) << std::endl;
//        else // Inspector
//            Logger::Debug() << "Inspector choose : " << Detective.MakeChoice(gQuestion, gData, gState) << std::endl;

        Logger::Log() << "Sending Answer ..." << std::endl;

        Con.SendMsg("1");

        // Send Message Back

        Logger::Log() << "Done. Waiting for Server ..." << std::endl;

    }

    Logger::Log() << "Client Now Closing." << std::endl;

    return 0;
}
