//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#ifndef IRRLICHTLIB_HPP
#define IRRLICHTLIB_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>

namespace graphic {
    class IrrlichtLib {
        irr::video::IVideoDriver* _driver;
        irr::scene::ISceneManager* _managerScene;
    public:
        irr::IrrlichtDevice *_device;
        irr::gui::IGUIEnvironment* _guiEnv;
        IrrlichtLib();
        ~IrrlichtLib();
        void displayAll();
        int setMesh();
        void drawText(std::string const&);
    };
    void driverChoiceConsole(irr::video::E_DRIVER_TYPE &);
}
#endif //IRRLICHTLIB_HPP
