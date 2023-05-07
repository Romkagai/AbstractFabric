#ifndef CLASS_METHOD_H
#define CLASS_METHOD_H

#include "unit.h"

class MethodUnit: public Unit {

public:
    enum Modifier           //Модификаторы доступа для методов
    {
        STATIC = 1,         //C# C++ JAVA
        CONST = 1 << 1,     //С++
        VIRTUAL = 1 << 2,   //C# C++
        FINAL = 1 << 3,     //JAVA
        ABSTRACT = 1 << 4   //JAVA
    };

public:
    MethodUnit(const std::string & name, const std::string & returnType, Flags flags):
            m_name(name),
            m_returnType(returnType),
            m_flags(flags) {}

    void add(const std::shared_ptr <Unit> & unit, Flags /* flags */ = 0)
    {
        m_body.push_back(unit);
    }

protected:
    std::string m_name;         // Название метода
    std::string m_returnType;   // Тип возвращаемого методом значения
    Flags m_flags;              // Модификаторы метода
    std::vector <std::shared_ptr<Unit>> m_body;    //Тело метода - вектор указателей на Unit
};

#endif // CLASS_METHOD_H
