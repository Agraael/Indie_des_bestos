//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include "IrrlichtLib.hpp"

graphic::IrrlichtLib::IrrlichtLib() {
    _device = irr::createDevice( irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, //deviceType: Type of the device, windowSize,
                       false, false, false, 0); //bits: Amount of color bits per pixel. This should be 16 or 32, fullscreen,
    // stencilbuffer: Specifies if we want to use the stencil buffer (for drawing shadows).
    //vsync: Specifies if we want to have vsync enabled, this is only useful in fullscreen mode.
    //eventReceiver: An object to receive events. We do not want to use this parameter here, and set it to 0.
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


