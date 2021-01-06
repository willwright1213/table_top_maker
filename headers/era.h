#ifndef ERA_H
#define ERA_H

#include <QString>
/*
 * Era class. An Era is a large period of time in the world creation.
 * Each campaign created belongs to an era that is part of our world.
 * This class handles the creation, modification and destruction of these era,


*/

namespace model {

    class Era {

    public:
       Era(const QString& w);
       ~Era();
       void setLore(const QString& lore);
       void setName(const QString& lore);
       void setStart(const QString& start);
       void setEnd(const QString& end);

       QString lore() const;
       QString name() const;
       QString start() const;
       QString end() const;
    private:
       QString world;
    };
};

#endif // ERA_H
