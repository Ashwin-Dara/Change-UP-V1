#include "main.h"

#ifndef INTAKE_H_
#define INTAKE_H_

void intake_move(float intake_speed);

void indexer_move(float index_speed);

void outake_move(float outake_speed);

void autoShootIndex();

void autoShootNoIndex();

namespace intake{
    void opcontrol();
}


#endif