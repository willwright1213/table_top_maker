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
    }

    void valid_insertion()
    {
        QString verification = "";
        QString first = "Dark Age";
        QString second = "Bronze Age";

        try {
           Era::create(*w, first, 0);
           Era::create(*w, second, 1);
        }  catch (std::invalid_argument &e) {
            verification = e.what();
        }

        QString character_name = "Willis";
        QString character_race = "Human";
        QString character_class = "Paladin";

        try {
           Character::create(*w, character_name, character_race, character_class);
        }  catch (std::invalid_argument &e) {
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
        w->destroy();
    }
};

QTEST_MAIN(ModelTest)
#include "modeltest.moc"

