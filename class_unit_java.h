#ifndef CLASS_UNIT_JAVA_H
#define CLASS_UNIT_JAVA_H

#include "class_unit.h"

class ClassUnitJava: public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа для языка (определены после класса)

public:
  explicit ClassUnitJava(const std::string &name): ClassUnit(name, ACCESS_MODIFIERS.size()) {}

  void add(const std::shared_ptr <Unit> &unit, Flags flags)     // Функция добавления Unit в список полей
  {
    int accessModifier = PRIVATE;                                // По умолчанию PRIVATE
    if (flags < ACCESS_MODIFIERS.size()) {                      // Если flags < длины вектора ACCESS_MODIFIERS
      accessModifier = flags;                                   // То ставим такой модификатор, как во flags
    }
    m_fields[accessModifier].push_back(unit);                   // Указатель на Unit передается в вектор полей класса с данным модификатором
  }

  std::string compile(unsigned int level = 0) const {

      std::string result = generateShift(level) + "class " + m_name + " {\n";       // Комментарии аналогичны языку С#
      for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
      {
        if (m_fields[i].empty())
        {
          continue;
        }

        for (const auto & methods: m_fields[i])
        {
          result += generateShift(level+1) + ACCESS_MODIFIERS[i] + " " + methods -> compile(level+1);
        }
        result += "\n";
      }
      result += generateShift(level) + "};\n";
      return result;
    }
};

//Модификаторы доступа для данного языка (в данном векторе они должны быть выстроены по порядку в соответствии с порядком заданным в родительском классе Unit)
const std::vector <std::string> ClassUnitJava::ACCESS_MODIFIERS =
{
  "public",
  "protected",
  "private"
};

#endif // CLASS_UNIT_JAVA_H
