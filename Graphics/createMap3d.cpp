//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include <irrlicht/irrlicht.h>

int main()
{
    irr::video::E_DRIVER_TYPE driverType;

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
        default: return 1;
    }

    // create device and exit if creation failed

    irr::IrrlichtDevice *device =
            irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(640, 480));

    if (device == 0)
        return 1; // could not create selected driver.

    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();

    device->getFileSystem()->addFileArchive("./media/map-20kdm2.pk3");
    irr::scene::IAnimatedMesh* mesh = smgr->getMesh("20kdm2.bsp");
    irr::scene::ISceneNode* node = 0;

    if (mesh)
        node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
//      node = smgr->addMeshSceneNode(mesh->getMesh(0));
    if (node)
        node->setPosition(irr::core::vector3df(-1300,-144,-1249));
    smgr->addCameraSceneNodeFPS();
    device->getCursorControl()->setVisible(false);
    int lastFPS = -1;

    while(device->run())
    {
       if (device->isWindowActive())
        {
            driver->beginScene(true, true, irr::video::SColor(255,200,200,200));
            smgr->drawAll();
            driver->endScene();

            int fps = driver->getFPS();

            if (lastFPS != fps)
            {
                irr::core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
                str += driver->getName();
                str += "] FPS:";
                str += fps;

                device->setWindowCaption(str.c_str());
                lastFPS = fps;
            }
        }
        else
            device->yield();
    }
    device->drop();
    return 0;
}
