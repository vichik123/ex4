//
// Created by eitan on 1/13/2024.
//

#ifndef GREMLIN_H
#define GREMLIN_H


class Gremlin : public EnemyCard {

public:
    Gremlin();
};

Gremlin::Gremlin() : EnemyCard("Gremlin", 5, 2, 10) {}

#endif //GREMLIN_H
