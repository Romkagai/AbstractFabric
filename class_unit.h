#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "unit.h"

// Класс для реализации создания конкретных классов для разных языков
class ClassUnit: public Unit {

public:
    enum AccessModifier     // Перечисление модификаторов доступа для поставленных в задаче языков
    {
        PUBLIC,             // C# C++ JAVA
        PROTECTED,          // C# C++ JAVA
        PRIVATE,            // C# C++ JAVA
        INTERNAL,           // C#
        PROTECTED_INTERNAL, // C#
        PRIVATE_PROTECTED,  // C#
    };

public:   
  explicit ClassUnit(const std::string &name, size_t field_size) : m_name(name), m_fields(field_size){}

protected:
  std::string m_name;                                       //Название для класса
  using Fields = std::vector <std::shared_ptr<Unit>> ;      //Тип данных Fields (вектор указателей на объекты типа Unit)
  std::vector <Fields> m_fields;                            //Вектор векторов указателей на объекты типа Unit
};

#endif // CLASSUNIT_H
