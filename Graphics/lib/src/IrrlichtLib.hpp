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
        irr::IrrlichtDevice *_device;
        irr::gui::IGUIEnvironment* _guiEnv;
    public:
        IrrlichtLib();
        ~IrrlichtLib();
        irr::IrrlichtDevice *getDevice() { return _device; }
        irr::video::IVideoDriver *getDriver() { return _driver; }
        irr::gui::IGUIEnvironment *getGuiEnv() { return _guiEnv; }
        irr::scene::ISceneManager* getManagerScene() { return _managerScene; }
        void displayAll();
        int setMesh();
        void drawText(size_t x, size_t y, size_t fontSize, std::string const&);
    };
    void driverChoiceConsole(irr::video::E_DRIVER_TYPE &);
}
#endif //IRRLICHTLIB_HPP
