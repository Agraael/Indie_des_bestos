//
// Created by Ludovica Pagliarani on 08/05/2018.
//

#ifndef CUSTOMSCENE_HPP
#define CUSTOMSCENE_HPP

#include <irrlicht/irrlicht.h>
#include <iostream>

class CSampleSceneNode : public irr::scene::ISceneNode {
    irr::core::aabbox3d<irr::f32> Box;
    irr::video::S3DVertex Vertices[5];
    irr::video::SMaterial Material;
public:
    CSampleSceneNode(irr::scene::ISceneNode* parent, irr::scene::ISceneManager* mgr, irr::s32 id);
    virtual void OnRegisterSceneNode();
    virtual void render();
    virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const { return Box; }
    virtual irr::u32 getMaterialCount() const { return 1; }
    virtual irr::video::SMaterial& getMaterial(irr::u32 i) { return Material; }
};

void driverChoiceConsole(irr::video::E_DRIVER_TYPE &);

#endif //CUSTOMSCENE_HPP
