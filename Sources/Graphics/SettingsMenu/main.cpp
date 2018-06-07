//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#include <memory>
#include "../LocalMenu/localMenu.hpp"
#include <string>
#include <cstdio>
#include <iostream>

/*using namespace std;

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
}*/

int main()
{

    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    graphic::localMenu menu(lib);
    menu.display();
    std::unordered_map <graphic::controllerUser, std::function<void()>>eventTab = menu.getEventTab();
    while (lib->getDevice()->run()) {
        menu.updateDisplay();
        for (auto button = eventTab.begin(); button != eventTab.end(); button++) {
            if (lib->getEventManager()->IsButtonClicked(static_cast<graphic::controllerUser>(button->first)) == true) {
                button->second();
            }
        }
        lib->displayAll(true);
    }
    return (0);
}