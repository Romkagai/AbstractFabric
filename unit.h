#ifndef UNIT_H
#define UNIT_H

#include <memory>       // Для пользования умным указателем
#include <stdexcept>    // Для вывода exception
#include <vector>       // Для создания объектов std::vector

class Unit {

public:
    using Flags = unsigned int;                                 // Теперь слово Flags будет означать unsigned int
    virtual void add(const std::shared_ptr<Unit>& , Flags)      // Добавление языковой конструкции
    {                                                           // Параметры: указатель на Unit, набор флагов Flags
        throw std::runtime_error( "Not supported" );            // По умолчанию кидает исключение
    }
    virtual std::string compile(unsigned int level = 0) const = 0;  // Функция генерации кода - возвращает строку с готовым кодом
    virtual ~Unit() = default;                                  // Деструктор (=default значит, что компилятор сам определяет деструктор)

protected:
    std::string generateShift( unsigned int level ) const   // Возвращает строку из нужного числа пробелов (результат зависит от уровня вложенности)
    {
        static const auto DEFAULT_SHIFT = " ";          // Величина отступа по умолчанию - 1 пробел
        std::string result;                             // Создаем строку
        for( unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;                    // Добавляем отступы в зависимости от level
        }
        return result;                                  // Возврат строки отступов
    }
};

#endif // UNIT_H
