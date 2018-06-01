//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#include <memory>
//#include "settingsMenu.hpp"

#include <string>
#include <cstdio>
#include <iostream>
#include "irrKlang.h"

using namespace std;
int main()
{

    irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

    if (!engine) return 1; // could not start engine

    engine->setSoundVolume(1.0f);
    engine->play2D("./media/bombermanMenu.mp3"); // play some mp3 file

    cout<<"hello\n";

    std::cin.get(); // wait until user presses a key

    engine->drop(); // delete engine
    return 0;
}

/*int main()
{

    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    graphic::settingsMenu menu(lib);
    menu.display();
    AudioDevicePtr deviceA(OpenDevice());

    OutputStreamPtr mySound(OpenSound(deviceA, "./media/bombermanMenu.mp3", true)); // Your sound path
    mySound->setVolume(0.5f); // 0.0 to 1.0
    mySound->setPan(0);       // 0 Left, 1 Right
    mySound->setRepeat(1);    // 1 loop, 0 don't loop
    mySound->play();
    while (lib->getDevice()->run()) {
        menu.updateDisplay();
        mySound->setVolume(abs(100-1000)/1000.0);
        lib->displayAll();
    }
    return (0);
}*/