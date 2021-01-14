/*
 * Model Test file for testing insertion, selection and removal of items in the database
*/

#include "headers/world.h"
#include "headers/character.h"
#include <QtTest/QtTest>

class TestCase: public QObject {

    Q_OBJECT

    World *w;

private slots:

    void initTestCase()
    {
        w = new World(false, "test");
        Character::initiate_validators();
        //Character::generate_css(*w);
    }

    void files_integrity()
    {
       QVERIFY(QFile(w->path()->canonicalPath().append("/characters/template/template.html")).exists());
       QVERIFY(QFile(w->path()->canonicalPath().append("/characters/css/stylesheet.css")).exists());
       QVERIFY(QDir(w->path()->canonicalPath().append("/characters/images")).exists());
       QVERIFY(QFile(w->path()->canonicalPath().append("/campaigns/template/template.html")).exists());
       QVERIFY(QFile(w->path()->canonicalPath().append("/campaigns/css/stylesheet.css")).exists());
       QVERIFY(QDir(w->path()->canonicalPath().append("/campaigns/images")).exists());
    }

    void valid_insertion()
    {
        QString verification = "";

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


    void cleanup() {
        database::openConnection(w->path());
        sqlite3_exec(database::db, "DELETE FROM characters;", NULL, NULL, nullptr);
        sqlite3_exec(database::db, "DELETE FROM campaigns;", NULL, NULL, nullptr);
        sqlite3_exec(database::db, "DELETE FROM events;", NULL, NULL, nullptr);
        database::closeConnection();
    }

    void cleanupTestCase(){
        //w->destroy();
    }
};

#include "testcase.moc"

