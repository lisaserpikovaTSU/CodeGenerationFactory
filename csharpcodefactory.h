#ifndef CSHARPCODEFACTORY_H
#define CSHARPCODEFACTORY_H

#include "icodefactory.h"
#include "csharp/csharpclassunit.h"

class CSharpCodeFactory: public ICodeFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, CSharpClassUnit::ClassModifier modifier ) override {
        return std::make_shared<CSharpClassUnit>(name, modifier);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                 const std::string& returnType, Flags flags = 0) override {
        return new CSharpMethodUnit(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return new CSharpPrintOperatorUnit(text);
    }
};

#endif // CSHARPCODEFACTORY_H
