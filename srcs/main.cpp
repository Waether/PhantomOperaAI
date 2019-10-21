//
// Created by waether on 20/10/19.
//

#include <iomanip>
#include "Net.hpp"
#include "Logger.hpp"
#include "KeyEvaluator.hpp"
#include "GameState.hpp"
#include "nlohmann/json.hpp"
#include "FantomAI.hpp"
#include "InspectorAI.hpp"

using json = nlohmann::json;

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

    GameState gState;
    FantomAI Phantom;
    InspectorAI Detective;

    std::string msg_received;
    bool GameOn = true;

    while (GameOn) {
        msg_received = Con.ReceiveMsg();

        Logger::Debug() << msg_received.c_str() << std::endl;

        // Parsing JSON

        json j = json::parse(msg_received.c_str());

        // Reading Data

        std::string gData, gQuestion;

        for (json::iterator it = j.begin(); it != j.end(); ++it) {
            switch (KeyEvaluator::Evaluate(it.key())) {
                case KeyEvaluator::Question :
                    gQuestion = it.value();
                    Logger::Debug() << "gQuestion : " << it.value() << std::endl;
                    break;
                case KeyEvaluator::Data :
                    Logger::Debug() << "gData : " << it.value() << std::endl;
//                    gData = it.value();
                    break;
                case KeyEvaluator::GameState :
                    Logger::Debug() << "gameState : " << it.value() << std::endl;
//                    gState.Update(it.value());
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

//        if (playerType == 0) // Fantom
//            Logger::Debug() << "Fantom choose : " << Phantom.MakeChoice(gQuestion, gData, gState) << std::endl;
//        else // Inspector
//            Logger::Debug() << "Inspector choose : " << Detective.MakeChoice(gQuestion, gData, gState) << std::endl;

        // Send Message Back

    }

    return 0;
}
