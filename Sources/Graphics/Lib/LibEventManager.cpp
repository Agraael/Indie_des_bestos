//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#include <iostream>
#include "LibEventManager.hpp"

graphic::LibEventManager::LibEventManager(t_contextRecEvnt const& context) : _context(context)
{

}

bool graphic::LibEventManager::OnEvent(const irr::SEvent& event)
{
    if (event.EventType == irr::EET_GUI_EVENT)
    {
        irr::s32 id = event.GUIEvent.Caller->getID();
        irr::gui::IGUIEnvironment* env = _context.device->getGUIEnvironment();

        switch(event.GUIEvent.EventType)
        {
            case irr::gui::EGET_SCROLL_BAR_CHANGED:
                if (id == graphic::GUI_ID_TRANSPARENCY_SCROLL_BAR)
                {
                    irr::s32 pos = ((irr::gui::IGUIScrollBar*)event.GUIEvent.Caller)->getPos();

                    for (irr::u32 i=0; i< irr::gui::EGDC_COUNT ; ++i)
                    {
                        irr::video::SColor col = env->getSkin()->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
                        col.setAlpha(pos);
                        env->getSkin()->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
                    }

                }
                break;
            case irr::gui::EGET_BUTTON_CLICKED:
                switch(id)
                {
                    case graphic::GUI_ID_QUIT_BUTTON:
                        _context.device->closeDevice();
                        return true;

                    case graphic::GUI_ID_NEW_WINDOW_BUTTON:
                    {
                        _context.counter += 30;
                        if (_context.counter > 200)
                            _context.counter = 0;

                        irr::gui::IGUIWindow* window = env->addWindow(
                                irr::core::rect<irr::s32>(100 + _context.counter, 100 + _context.counter, 300 + _context.counter, 200 + _context.counter),
                                false, L"Test window");

                        env->addStaticText(L"Please close me", irr::core::rect<irr::s32>(35,35,140,50), true, false, window);
                    }
                        return true;

                    case graphic::GUI_ID_FILE_OPEN_BUTTON:
                        // Il y a quelques options pour l'ouverture de fichier.
                        // Nous mettons le titre, indiquons qu'elle sera une fenêtre modale et nous assurons
                        // que le dossier de travail est restauré après que la fenêtre se soit fermée.
                        env->addFileOpenDialog(L"Please choose a file.", true, 0, -1, true);
                        return true;

                    default:
                        return false;
                }
                break;
            case irr::gui::EGET_FILE_SELECTED:
            {
                // Montre le nom du fichier sélectionné dans la fenêtre d'ouverture de fichier.
                irr::gui::IGUIFileOpenDialog* dialog =
                        (irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
		(void)(dialog);
	    }
	    break;

	default:
                break;
        }
    }

    return false;
}

bool graphic::LibEventManager::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

bool graphic::LibEventManager::eventGetter()
{
    for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
    return true;
}

/*int main()
{
    // crée un moteur et quitte si la création a échouée

    irr::IrrlichtDevice * device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480));

    if (device == 0)
        return 1; // on ne peut pas créer le pilote sélectionné
    device->setWindowCaption(L"Irrlicht Engine - User Interface Demo");
    device->setResizable(true);

    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
    irr::gui::IGUISkin* skin = env->getSkin();
    irr::gui::IGUIFont* font = env->getFont("../../media/PaddingtonItalic.ttf");
    if (font)
        skin->setFont(font);

    skin->setFont(env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    irr::gui::IGUIImage *background = env->addImage(driver->getTexture("../../media/pixel_skyline.png"), irr::core::position2d<int>(0,0));
    background->setScaleImage(true);
    background->setMinSize(irr::core::dimension2du(640,480));
    background->setMaxSize(irr::core::dimension2du(640,480));
    env->addButton(irr::core::rect<irr::s32>(200,240,400,280), 0, graphic::GUI_ID_QUIT_BUTTON, L"Quit", L"Exits Program");
    env->addButton(irr::core::rect<irr::s32>(200,300,400,340), 0, graphic::GUI_ID_NEW_WINDOW_BUTTON,
                   L"New Window", L"Launches a new Window");
    env->addButton(irr::core::rect<irr::s32>(10,320,110,320 + 32), 0, graphic::GUI_ID_FILE_OPEN_BUTTON,
                   L"File Open", L"Opens a file");
    env->addStaticText(L"Transparent Control:", irr::core::rect<irr::s32>(150,20,350,40), true);
    irr::gui::IGUIScrollBar* scrollbar = env->addScrollBar(true,
                                                 irr::core::rect<irr::s32>(150, 45, 350, 60), 0, graphic::GUI_ID_TRANSPARENCY_SCROLL_BAR);
    scrollbar->setMax(255);

    // met la position de la barre de défilement à la valeur alpha d'un élément choisi arbitrairement
    scrollbar->setPos(env->getSkin()->getColor(irr::gui::EGDC_WINDOW).getAlpha());

    env->addEditBox(L"Editable Text", irr::core::rect<irr::s32>(200, 200, 400, 230));

    // Stocke les données appropriées dans la structure de _contexte.
    graphic::t_contextRecEvnt context;
    context.device = device;
    context.counter = 0;

    // Enfin, crée le receveur d'événement, on lui donne la structure de _contexte.
    graphic::LibEventManager receiver(context);

    // Et nous disons au moteur d'utiliser notre receveur d'événement personnel. 640, 480
    irr::gui::IGUIImage *image = env->addImage(driver->getTexture("../../media/Neo_Bomberman_Logo.png"), irr::core::position2d<int>(150,5));
    image->setScaleImage(true);
    image->setMinSize(irr::core::dimension2du(200,200));
    image->setMaxSize(irr::core::dimension2du(600,600));
    while(device->run() && driver)
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, irr::video::SColor(0,200,200,200));

            env->drawAll();

            driver->endScene();
        }

    device->drop();

    return 0;
}*/
