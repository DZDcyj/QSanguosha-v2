#ifndef _UTIL_H
#define _UTIL_H

#include <QRandomGenerator>
#include <QRandomGenerator64>

struct lua_State;
class QVariant;

template<typename T>
void qShuffle(QList<T> &list)
{
    auto* qrandgen = QRandomGenerator::global();
    std::shuffle(list.begin(), list.end(), *qrandgen);
}

// lua interpreter related
lua_State *CreateLuaState();
bool DoLuaScript(lua_State *L, const char *script);

QVariant GetValueFromLuaState(lua_State *L, const char *table_name, const char *key);

QStringList IntList2StringList(const QList<int> &intlist);
QList<int> StringList2IntList(const QStringList &stringlist);
QVariantList IntList2VariantList(const QList<int> &intlist);
QList<int> VariantList2IntList(const QVariantList &variantlist);

bool isNormalGameMode(const QString &mode);

static const int S_EQUIP_AREA_LENGTH = 5;

#endif

