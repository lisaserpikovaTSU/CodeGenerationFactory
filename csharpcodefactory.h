#ifndef CSHARPCODEFACTORY_H
#define CSHARPCODEFACTORY_H

#include "icodefactory.h"
#include "csharp/csharpclassunit.h"
#include "csharp/csharpmethodunit.h"
#include "csharp/csharpprintoperatorunit.h"

class CSharpCodeFactory: public ICodeFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, Unit::Flags modifier ) override {
        return std::make_shared<CSharpClassUnit>(name, static_cast<CSharpClassUnit::ClassModifier>(modifier));
    }
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                 const std::string& returnType, Unit::Flags flags = 0) override {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<CSharpPrintOperatorUnit>(text);
    }
};

#endif // CSHARPCODEFACTORY_H
