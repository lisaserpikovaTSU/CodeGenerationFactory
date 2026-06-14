#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <memory>
#include "icodefactory.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class CodeGenerator
{
public:
    explicit CodeGenerator(std::shared_ptr<ICodeFactory> factory): m_factory(std::move(factory)) {}

    void addClass(const std::string& name, Unit::Flags modifier = 0) {
        m_class = m_factory->createClassUnit(name, modifier);
    }

    void addMethod(const std::string& name, const std::string& returnType, Unit::Flags flags = 0, int accessModifier = 0) {
        current_method = m_factory->createMethodUnit(name, returnType, flags);
        m_class->add(current_method, accessModifier);
    }

    void addPrint(const std::string& text) {
        std::shared_ptr<PrintOperatorUnit> print = m_factory->createPrintOperatorUnit(text);
        current_method->add(print, 0);
    }

    std::string generateCode() const {
        return m_class->compile();
    }
private:
    std::shared_ptr<ICodeFactory> m_factory;
    std::shared_ptr<ClassUnit> m_class;
    std::shared_ptr<MethodUnit> current_method;
};

#endif // CODEGENERATOR_H
