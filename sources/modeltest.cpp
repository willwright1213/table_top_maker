/*
 * Model Test file for testing insertion, selection and removal of items in the database
*/

#include "headers/world.h"
#include "headers/era.h"
#include "headers/character.h"
#include <QtTest/QtTest>

class ModelTest: public QObject {

    Q_OBJECT

    World *w;

private slots:

    void initTestCase()
    {
        w = new World(false, "test");
        Era::initiate_validators();
        Character::initiate_validators();
        Character::generate_template(*w);
        //Character::generate_css(*w);
    }

    void valid_insertion()
    {
        QString verification = "";
        QString first = "Dark Age";
        QString second = "Bronze Age";

        try {
           Era::create(*w, first, 0);
           Era::create(*w, second, 1);
           qDebug() << "Era insertion successful";
        }  catch (std::invalid_argument &e) {
            verification = e.what();
        }

        QString character_name = "Willis";
        QString character_race = "Human";
        QString character_class = "Paladin";
        QString birth_year = "10 000 bc";
        QString birth_place = "Winterfell";

        try {
           Character::create(*w, character_name, character_race, character_class, birth_year, birth_place, "", "", "<p>oh hell naw</p>");
           qDebug() << "Character insertion successful";
        }  catch (std::invalid_argument &e) {
            qDebug() << e.what();
            verification = e.what();
        }

        QVERIFY(verification == "");
    }

    void unique_era_insertion()
    {
        QString verification = "";
        QString first = "Dark Age";
        QString second = "Bronze Age";

        try {
            Era::create(*w, first, 0);
            Era::create(*w, second, 0);
        }  catch (std::invalid_argument &e) {
            verification = "double ordering";
        }

        QVERIFY(verification == "double ordering");
    }

    void insert_delete_insert()
    {
        QString verification = "";
        QString first = "Dark Age";

        try {
           Era::create(*w, first, 0);
           Era::remove(*w, Era::find_by_name(*w, first));

        }  catch (std::invalid_argument &e) {
           verification = "remove did not work";
        }
        QVERIFY(verification == "");

    }

    void cleanup() {
        database::openConnection(w->path());
        sqlite3_exec(database::db, "DELETE FROM era;", NULL, NULL, nullptr);
        sqlite3_exec(database::db, "DELETE FROM characters;", NULL, NULL, nullptr);
        sqlite3_exec(database::db, "DELETE FROM campaigns;", NULL, NULL, nullptr);
        database::closeConnection();
    }

    void cleanupTestCase(){
        //w->destroy();
    }
};

#include "modeltest.moc"

