//
// Created by eitan on 1/13/2024.
//

#ifndef GREMLIN_H
#define GREMLIN_H


class Gremlin : public BattleCard {

public:
    Gremlin();
};

Gremlin::Gremlin() : BattleCard(5, 2, 10) {}

#endif //GREMLIN_H
