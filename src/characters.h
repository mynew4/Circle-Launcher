#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QFileInfoList>

enum CharRaceEnum {
    RACE_UNKNOWN,
    RACE_HUMAN,
    RACE_ORK,
    RACE_DWARF,
    RACE_NIGHTELF,
    RACE_UNDEAD,
    RACE_TAUREN,
    RACE_GNOME,
    RACE_TROLL,
    RACE_GOBLIN,
    RACE_BLOODELF,
    RACE_DRAENEI
};

enum CharClassEnum {
    CLASS_UNK_0,
    CLASS_WARRIOR,
    CLASS_PALADIN,
    CLASS_HUNTER,
    CLASS_ROGUE,
    CLASS_PRIEST,
    CLASS_DEATH_KNIGHT,
    CLASS_SHAMAN,
    CLASS_MAGE,
    CLASS_WARLOCK,
    CLASS_UNK_1,
    CLASS_DRUID
};

struct Character {
    QString name;
    QString charClassStr;
    CharClassEnum charClass;
    CharRaceEnum race;
    bool isMale;
    int level;
    QDateTime lastIn;
};

class Characters
{
private:
    QList<Character> characters;
    QString gamePath;
    QString realm;

public:
    Characters(QString _gamePath);

    void setGamePath(QString _gamePath);
    void SearchByRealm(QString _realm);

    Character getCharacterByIndex(int index);
    QList<Character> getCharacters();
    int getCharactersCount();
    int getIndexByName(QString name);

private:
    QStringList getCharDataFiles();
    void processFile(QFile *file);
    QString getAssignment(QString str);
    QString getCharacterName(QString str);
    QString getRealClassName(QString str);
    CharRaceEnum getRealRace(QString str);
    bool    isMaleStrToBool(QString str);
    CharClassEnum getClassFromStr(QString str);

    Character createUnknownChar();
};

#endif // CHARACTERS_H
