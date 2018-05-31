//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#include "customScene.hpp"

int main()
{
    MyEventReceiver receiver;

    IrrlichtDevice* device = createDevice(irr::video::EDT_OPENGL,
                                          core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);

    if (device == 0)
        return 1; // could not create selected driver.

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    scene::ISceneNode * node = smgr->addSphereSceneNode();
    if (node)
    {
        node->setPosition(core::vector3df(0,0,30));
        node->setMaterialTexture(0, driver->getTexture("./media/red_brick.jpg"));
        node->setMaterialFlag(video::EMF_LIGHTING, false);
    }
    /*scene::ISceneNode* n = smgr->addCubeSceneNode();

    if (n)
    {
        n->setMaterialTexture(0, driver->getTexture("./media/red_brick.jpg"));
        n->setMaterialFlag(video::EMF_LIGHTING, false);
        scene::ISceneNodeAnimator* anim =
                smgr->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
        if (anim)
        {
            n->addAnimator(anim);
            anim->drop();
        }
    }*/
    smgr->addCameraSceneNodeFPS();


    while(device->run())
    {


        driver->beginScene(true, true, video::SColor(255,113,113,133));

        smgr->drawAll(); // draw the 3d scene
        device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

        driver->endScene();
    }
    device->drop();

    return 0;
}