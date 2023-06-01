#ifndef CLASS_UNIT_CPP_H
#define CLASS_UNIT_CPP_H

#include "class_unit.h"
#include "method_unit.h"

class ClassUnitCpp: public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа для языка (определены после класса)

public:
  explicit ClassUnitCpp(const std::string &name): ClassUnit(name, ACCESS_MODIFIERS.size()) {}

  void add(const std::shared_ptr <Unit> &unit, Flags flags)     // Функция добавления Unit в список полей
  {
    int accessModifier = PRIVATE;                               // По умолчанию PRIVATE
    if (flags < ACCESS_MODIFIERS.size()) {                      // Если flags < длины вектора ACCESS_MODIFIERS
      accessModifier = flags;                                   // То ставим такой модификатор, как во flags
    }

    // Попытка приведения типа указателя unit к MethodUnit - если указатель не привелся, возвращается nullptr
    // Приведение не удалось => unit это не MethodUnit включение невозможно
    if (std::dynamic_pointer_cast<MethodUnit>(unit) == nullptr){
      throw std::runtime_error( "Only methods can be included in classes" );
    }
    else {m_fields[accessModifier].push_back(unit); }           // Указатель на Unit передается в вектор полей класса с данным модификатором                   // Указатель на Unit передается в вектор полей класса с данным модификатором
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

      result += ACCESS_MODIFIERS[i] + ":\n";                // В С++ для методов модификаторы доступа указываются полями поэтому
                                                            // Сначала выводим модификатор доступа
      for (const auto & methods: m_fields[i])
      {
        result += methods -> compile(level + 1);            // А затем компилируем для него все имеющиеся методы
      }
      result += "\n";                                       // Переход к следующей строке
    }
    result += generateShift(level) + "};\n";                // Отступ и закрытие класса
    return result;                                          // Возвращаем полученный код
  }
};

//Модификаторы доступа для С++ (в данном векторе они должны быть выстроены по порядку в соответствии с порядком заданным в родительском классе Unit)
const std::vector <std::string> ClassUnitCpp::ACCESS_MODIFIERS =
{
  "public",
  "protected",
  "private"
};

#endif // CLASS_UNIT_CPP_H
