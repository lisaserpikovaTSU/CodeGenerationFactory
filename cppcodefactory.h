#ifndef CPPCODEFACTORY_H
#define CPPCODEFACTORY_H

#include "icodefactory.h"
#include "cpp/cppclassunit.h"
#include "cpp/cppmethodunit.h"
#include "cpp/cppprintoperatorunit.h"

class CppCodeFactory: public ICodeFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                 const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

#endif // CPPCODEFACTORY_H
