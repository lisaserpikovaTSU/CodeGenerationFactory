#ifndef JAVACODEFACTORY_H
#define JAVACODEFACTORY_H

#include "icodefactory.h"
#include "java/javaclassunit.h"
#include "java/javamethodunit.h"
#include "java/javaprintoperatorunit.h"

class JavaCodeFactory: public ICodeFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name,
                                               JavaClassUnit::ClassModifier modifier
                                               = JavaClassUnit::ClassModifier::NONE ) override {
        return std::make_shared<JavaClassUnit>(name, modifier);
    }
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                 const std::string& returnType, Flags flags = 0) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};

#endif // JAVACODEFACTORY_H
