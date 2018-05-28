//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include <irrlicht/irrlicht.h>
#include "IrrlichtLib.hpp"

int main()
{
    graphic::IrrlichtLib Lib;

    Lib.setMesh();
    while(Lib._device->run())
    {
        Lib._guiEnv->addStaticText(L"WRITE SOMETHING", irr::core::rect<irr::s32>(10,10,260,22), true);
        Lib.displayAll();
    }
    return 0;
}
