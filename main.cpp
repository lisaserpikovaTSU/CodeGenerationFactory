#include <QCoreApplication>
#include <memory>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include "codegenerator.h"
#include "cppcodefactory.h"
#include "csharpcodefactory.h"
#include "javacodefactory.h"

QTextStream cin(stdin);
QTextStream cout(stdout);

int main() {

    //Генерируем C++ код
    std::shared_ptr<CppCodeFactory> cppCodeFactory = std::make_shared<CppCodeFactory>();
    CodeGenerator cppGenerator(cppCodeFactory);

    cppGenerator.addClass("MyClass");

    cppGenerator.addMethod("myMethod", "int", CppMethodUnit::STATIC, CppClassUnit::PUBLIC);
    cppGenerator.addPrint("C++");

    cout << cppGenerator.generateCode().c_str() << Qt::endl;

    CodeGenerator cppGenerator1(cppCodeFactory);

    cppGenerator1.addClass("MyClass1");

    cppGenerator1.addMethod("myMethod1", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST, CppClassUnit::PRIVATE);
    cppGenerator1.addPrint("C++");

    cout << cppGenerator1.generateCode().c_str() << Qt::endl;

    //Генерируем C# код
    std::shared_ptr<CSharpCodeFactory> csharpCodeFactory = std::make_shared<CSharpCodeFactory>();
    CodeGenerator csharpGenerator(csharpCodeFactory);

    csharpGenerator.addClass("MyClass");

    csharpGenerator.addMethod("myMethod", "int", CSharpMethodUnit::STATIC, CSharpClassUnit::PUBLIC);
    csharpGenerator.addPrint("C#");

    cout << csharpGenerator.generateCode().c_str() << Qt::endl;

    CodeGenerator csharpGenerator1(csharpCodeFactory);

    csharpGenerator1.addClass("MyClass1", static_cast<unsigned int>(CSharpClassUnit::ClassModifier::INTERNAL));

    csharpGenerator1.addMethod("myMethod1", "void", CSharpMethodUnit::VIRTUAL, CSharpClassUnit::PRIVATE);
    csharpGenerator1.addPrint("C#");

    cout << csharpGenerator1.generateCode().c_str() << Qt::endl;

    //Генерируем Java код
    std::shared_ptr<JavaCodeFactory> javaCodeFactory = std::make_shared<JavaCodeFactory>();
    CodeGenerator javaGenerator(javaCodeFactory);

    javaGenerator.addClass("MyClass");

    javaGenerator.addMethod("myMethod", "int", JavaMethodUnit::STATIC, JavaClassUnit::PUBLIC);
    javaGenerator.addPrint("Java");

    cout << javaGenerator.generateCode().c_str() << Qt::endl;

    CodeGenerator javaGenerator1(javaCodeFactory);

    javaGenerator1.addClass("MyClass1", static_cast<unsigned int>(JavaClassUnit::ClassModifier::PUBLIC)
                                        | static_cast<unsigned int>(JavaClassUnit::ClassModifier::ABSTRACT));

    javaGenerator1.addMethod("myMethod1", "void", JavaMethodUnit::ABSTRACT, JavaClassUnit::PROTECTED);
    javaGenerator1.addPrint("Java");

    cout << javaGenerator1.generateCode().c_str() << Qt::endl;

    return 0;
}
