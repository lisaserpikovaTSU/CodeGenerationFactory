#ifndef ICODEFACTORY_H
#define ICODEFACTORY_H

#include <string>
#include <memory>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class ICodeFactory
{
public:
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, Unit::Flags modifier = 0) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name,
                                                         const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
    virtual ~ICodeFactory() = default;
};

#endif // ICODEFACTORY_H
