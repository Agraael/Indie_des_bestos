//
// Created by Ludovica Pagliarani on 10/06/2018.
//

#include "irrKlangLib.hpp"

graphic::irrKlangLib::irrKlangLib()
{
    _engine = irrklang::createIrrKlangDevice();
    if (!_engine)
        std::cout << "error with createIrrKlangDevice" << std::endl;
    _volume = 1.0f;
}

void graphic::irrKlangLib::playSound(const std::string &sound)
{
    _engine->setSoundVolume(_volume);
    _engine->play2D(sound.c_str());
}
