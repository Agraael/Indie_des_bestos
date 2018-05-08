//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#include "customScene.hpp"

/*
* Les paramètres du constructeur seront le parent du nœud de scène, un pointeur sur le gestionnaire de scène
* et un identifiant pour le nœud de scène. Le constructeur appellera le constructeur de la classe parente,
* fixera quelques propriétés du matériel et créera les quatre vertex du tétraèdre que nous dessinerons plus tard.
*
* Le moteur Irrlicht a besoin de connaître la boîte délimitant le tétraèdre.
*/

CSampleSceneNode::CSampleSceneNode(irr::scene::ISceneNode *parent, irr::scene::ISceneManager* mgr, irr::s32 id) : irr::scene::ISceneNode(parent, mgr, id)
{
    Material.Wireframe = false;
    Material.Lighting = false;
    Vertices[0] = irr::video::S3DVertex(0, 0, 10, 1, 1, 0, irr::video::SColor(255, 0, 255, 255), 0, 1);
    Vertices[1] = irr::video::S3DVertex(10, 0, -10, 1, 0, 0, irr::video::SColor(255, 255, 0, 255), 1, 1);
    Vertices[2] = irr::video::S3DVertex(0, 20, 0, 0, 1, 1, irr::video::SColor(255, 255, 255, 0), 1, 0);
    Vertices[3] = irr::video::S3DVertex(-10, 0, -10, 0, 0, 1, irr::video::SColor(255, 0, 255, 0), 0, 0);
    Vertices[4] = irr::video::S3DVertex(-5, 10, -20, 1, 0, 1, irr::video::SColor(255, 255, 0, 0), 1, 1);
    Box.reset(Vertices[0].Pos);
    for (irr::s32 i=1; i<5; ++i)
       Box.addInternalPoint(Vertices[i].Pos);
}

void    driverChoiceConsole(irr::video::E_DRIVER_TYPE &driverType)
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

void    CSampleSceneNode::OnRegisterSceneNode()
{
    if (IsVisible)
        SceneManager->registerNodeForRendering(this);

    ISceneNode::OnRegisterSceneNode();
}

void    CSampleSceneNode::render()
{
    irr::u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1, 3,0,1  };
    irr::video::IVideoDriver* driver = SceneManager->getVideoDriver();

    driver->setMaterial(Material);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 5, &indices[0], 5, irr::video::EVT_STANDARD, irr::scene::EPT_QUADS, irr::video::EIT_16BIT);
}

int main()
{
    irr::video::E_DRIVER_TYPE driverType;
    driverChoiceConsole(driverType);
    if (driverType==irr::video::EDT_COUNT)
        return 1;

    // create device

    irr::IrrlichtDevice *device = irr::createDevice(driverType,
                                          irr::core::dimension2d<irr::u32>(640, 480), 16, false);

    if (device == 0)
        return 1; // could not create selected driver.

    // create engine and camera

    device->setWindowCaption(L"Custom Scene Node - Irrlicht Engine Demo");

    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();

    smgr->addCameraSceneNode(0, irr::core::vector3df(0,-40,0), irr::core::vector3df(0,0,0));
    CSampleSceneNode *myNode = new CSampleSceneNode(smgr->getRootSceneNode(), smgr, 666);
    irr::scene::ISceneNodeAnimator* anim =
            smgr->createRotationAnimator(irr::core::vector3df(0.8f, 0, 0.8f));

    if(anim)
    {
        myNode->addAnimator(anim);
        anim->drop();
        anim = 0;
    }
    myNode->drop();
    myNode = 0; // As I shouldn't refer to it again, ensure that I can't
    irr::u32 frames=0;
    while(device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(0,100,100,100));

        smgr->drawAll();

        driver->endScene();
        if (++frames==100)
        {
            irr::core::stringw str = L"Irrlicht Engine [";
            str += driver->getName();
            str += L"] FPS: ";
            str += (irr::s32)driver->getFPS();

            device->setWindowCaption(str.c_str());
            frames=0;
        }
    }

    device->drop();

    return 0;
}



