#ifndef CLASS_UNIT_C_SHARP_H
#define CLASS_UNIT_C_SHARP_H

#include "class_unit.h"

class ClassUnitCSharp: public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа для языка (определены после класса)

public:
  explicit ClassUnitCSharp(const std::string &name): ClassUnit(name, ACCESS_MODIFIERS.size()) {}

  void add(const std::shared_ptr <Unit> &unit, Flags flags)     // Функция добавления Unit в список полей
  {
    int accessModifier = PRIVATE;                               // По умолчанию PRIVATE
    if (flags < ACCESS_MODIFIERS.size()) {                      // Если flags < длины вектора ACCESS_MODIFIERS
      accessModifier = flags;                                   // То ставим такой модификатор, как во flags
    }
    m_fields[accessModifier].push_back(unit);                   // Указатель на Unit передается в вектор полей класса с данным модификатором
  }

  std::string compile(unsigned int level = 0) const
  {
    std::string result = generateShift(level) + "class " + m_name + " {\n"; // Создаем строку типа class ClassName и отступ

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)    // Идем по доступным модификаторам доступа
    {
      if (m_fields[i].empty())                              // Если для данного модификатора нет указателей на Unit'ы переходим на след. модификатор
      {
        continue;
      }

      for (const auto & methods: m_fields[i])               // Иначе компилируем все методы с данным модификатором
      {                                                     // При этом учитывая что в C# модификатор ставится непосредственно перед методом
        result += generateShift(level+1) + ACCESS_MODIFIERS[i] + " " + methods -> compile(level+1);
      }
      result += "\n";                                       // Следующая строка
    }
    result += generateShift(level) + "};\n";                // Закрываем класс, возвращаем код
    return result;
  }
};

//Модификаторы доступа для данного языка (в данном векторе они должны быть выстроены по порядку в соответствии с порядком заданным в родительском классе Unit)
const std::vector<std::string> ClassUnitCSharp::ACCESS_MODIFIERS =
{
  "public",
  "protected",
  "private",
  "internal",
  "protected internal",
  "private protected"
};

#endif // CLASS_UNIT_C_SHARP_H
