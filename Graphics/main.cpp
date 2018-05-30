//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#include "Menu.hpp"

int main()
{

    graphic::IrrlichtLib *lib = new graphic::IrrlichtLib;
    graphic::Menu menu(lib);
    menu.display();
    while (lib->getDevice()->run()) {
        menu.updateDisplay();
        lib->displayAll();
    }
    return (0);
}