#ifndef CPPCODEFACTORY_H
#define CPPCODEFACTORY_H

#include "icodefactory.h"
#include "cpp/cppclassunit.h"

class CppCodeFactory: public ICodeFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                 const std::string& returnType, Unit::Flags flags) override {
        return new CppMethodUnit(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return new CppPrintOperatorUnit(text);
    }
};

#endif // CPPCODEFACTORY_H
