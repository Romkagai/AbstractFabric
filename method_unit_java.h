#ifndef METHOD_UNIT_JAVA_H
#define METHOD_UNIT_JAVA_H

#include "method_unit.h"

class MethodUnitJava: public MethodUnit {
public:
    // конструктор
    MethodUnitJava(const std::string & name, const std::string & returnType, Flags flags) : MethodUnit(name, returnType, flags){}

    std::string compile( unsigned int level = 0 ) const     // Фукнкция компиляции
    {
        std::string result = "";        // Берем пустую строку в связи с тем, что в Java
                                        // Модификаторы доступа определяются непосредственно перед определением функции

        if(m_flags & ABSTRACT)          // Модификатор Abstact объявляет виртуальную функцию в Java
        {
            result += "abstract ";      // Проверяем его первым, т.к. abstract не может быть static или final
        }
        else
        {                                // Если же его нет, то
            if(m_flags & STATIC)         // Если в переданных флагах есть STATIC
            {
                result += "static ";     // Компилируем static
            }
            if(m_flags & FINAL)          // Модификатор FINAL в Java используется для завершения реализации метода (больше не изменяется)
            {                            // Если в переданных флагах есть FINAL
                result += "final ";      // Компилируем final
            }
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

#endif // METHOD_UNIT_JAVA_H
