#ifndef METHOD_UNIT_C_SHARP_H
#define METHOD_UNIT_C_SHARP_H

#include "method_unit.h"

class MethodUnitCSharp: public MethodUnit {
public:
    MethodUnitCSharp(const std::string & name, const std::string & returnType, Flags flags) : MethodUnit(name, returnType, flags){}

    std::string compile( unsigned int level = 0 ) const     // Фукнкция компиляции
    {
        std::string result = "";                            // Берем пустую строку в связи с тем, что в C#
                                                            // Модификаторы доступа определяются непосредственно перед определением функции
        if(m_flags & STATIC)                // Если в переданных флагах есть STATIC
        {
            result += "static ";            // Компилируем static
        }
        else if(m_flags & VIRTUAL)          //  Если нету static, то только в таком случае добавим virtual
        {                                   //  static - конкретная работа с объектом
            result += "virtual ";           //  virtual - работа через ссылку или указатель
        }

        result += m_returnType + " ";       // Пробел

        result += m_name + "()";            // Имя и скобочки

        result += " {\n";                   // Открыли скобку определения метода

        for(const auto& funcs : m_body)
        {
            result += funcs->compile(level + 1);    // Компилируем функции определяемые методом
        }

        result += generateShift(level) + "}\n";     // Закрыли скобку
        return result;                              // Вернули результат
    }
};

#endif // METHOD_UNIT_C_SHARP_H
