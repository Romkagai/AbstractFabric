#ifndef PRINT_OPERATOR_UNIT_JAVA_H
#define PRINT_OPERATOR_UNIT_JAVA_H

#include "print_operator_unit.h"

class PrintOperatorUnitJava : public PrintOperatorUnit {
public:
    explicit PrintOperatorUnitJava(const std::string& text) : PrintOperatorUnit(text) { }
    // В JAVA используем System.out.println
    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
};

#endif // PRINT_OPERATOR_UNIT_JAVA_H
