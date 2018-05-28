//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include "IrrlichtLib.hpp"

//deviceType: Type of the device, windowSize,
//bits: Amount of color bits per pixel. This should be 16 or 32, fullscreen,
// stencil buffer: Specifies if we want to use the stencil buffer (for drawing shadows).
//vsync: Specifies if we want to have vsync enabled, this is only useful in fullscreen mode.
//eventReceiver: An object to receive events. We do not want to use this parameter here, and set it to 0.

graphic::IrrlichtLib::IrrlichtLib() {
    irr::video::E_DRIVER_TYPE driverType;
    graphic::driverChoiceConsole(driverType);
    _device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
    if (!_device)
        std::cout << "error device" << std::endl;
    _device->setWindowCaption(L"INDIE DES BESTOS");
    _driver = _device->getVideoDriver();
    _managerScene = _device->getSceneManager();
    _guiEnv = _device->getGUIEnvironment();
}

graphic::IrrlichtLib::~IrrlichtLib()
{
    _device->drop();
}

void    graphic::IrrlichtLib::displayAll()
{
    _driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
    _managerScene->drawAll();
    _guiEnv->drawAll();
    _driver->endScene();
}

void    graphic::IrrlichtLib::drawText(size_t x, size_t y, size_t fontSize, const std::string &text)
{
    std::wstring wideStr = std::wstring(text.begin(), text.end());
    const wchar_t* wideCStr = wideStr.c_str();
    _guiEnv->addStaticText(wideCStr, irr::core::rect<irr::s32>(x,y, 100,22), true); //position (x,y) as top left corner and (260,22) as lower right corner.
}

int     graphic::IrrlichtLib::setMesh()
{
    irr::scene::IAnimatedMesh* mesh = _managerScene->getMesh("./media/sydney.md2");
    if (!mesh)
    {
        _device->drop();
        return 1;
    }
    irr::scene::IAnimatedMeshSceneNode* node = _managerScene->addAnimatedMeshSceneNode( mesh );
    if (node)
    {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMD2Animation(irr::scene::EMAT_STAND);
        node->setMaterialTexture( 0, _driver->getTexture("./media/sydney.bmp") );
    }
    _managerScene->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));
}

void    graphic::driverChoiceConsole(irr::video::E_DRIVER_TYPE &driverType)
{
    printf("Please select the driver you want for this example:\n"\
        " (a) OpenGL 1.5\n (b) Direct3D 9.0c\n (c) Direct3D 8.1\n"\
        " (d) Burning's Software Renderer\n (e) Software Renderer\n"\
        " (f) NullDevice\n (otherKey) exit\n\n");

    char i;
    std::cin >> i;

    switch(i)
    {
        case 'a': driverType = irr::video::EDT_OPENGL;   break;
        case 'b': driverType = irr::video::EDT_DIRECT3D9;break;
        case 'c': driverType = irr::video::EDT_DIRECT3D8; break;
        case 'd': driverType = irr::video::EDT_BURNINGSVIDEO;break;
        case 'e': driverType = irr::video::EDT_SOFTWARE; break;
        case 'f': driverType = irr::video::EDT_NULL;     break;
        default: break;
    }
}
