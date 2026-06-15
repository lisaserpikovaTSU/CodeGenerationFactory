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
    cout << "C++ (CppCodeFactory)\n\n" << Qt::endl;

    std::shared_ptr<CppCodeFactory> cppFactory = std::make_shared<CppCodeFactory>();

    //Случай 1**: Генерация класса с одним статическим публичным методом.
    CodeGenerator gen1(cppFactory);
    gen1.addClass("MyClass");
    gen1.addMethod("myMethod", "int", CppMethodUnit::STATIC, CppClassUnit::PUBLIC);
    gen1.addPrint("Hello from C++");
    cout << gen1.generateCode().c_str() << Qt::endl;

    //Случай 2**: Генерация класса с виртуальным константным приватным методом.
    CodeGenerator gen2(cppFactory);
    gen2.addClass("MyClass1");
    gen2.addMethod("myMethod1", "void",
                    CppMethodUnit::VIRTUAL | CppMethodUnit::CONST,
                    CppClassUnit::PRIVATE);
    gen2.addPrint("test");
    cout << gen2.generateCode().c_str() << Qt::endl;

    //Случай 3**: Пустое тело метода.
    CodeGenerator gen3(cppFactory);
    gen3.addClass("EmptyMethodClass");
    gen3.addMethod("emptyMethod", "void", 0, CppClassUnit::PUBLIC);
    cout << gen3.generateCode().c_str() << Qt::endl;



    //Генерируем C# код
    cout << "C# (CSharpCodeFactory)\n\n" << Qt::endl;

    std::shared_ptr<CSharpCodeFactory> csharpFactory = std::make_shared<CSharpCodeFactory>();

    //Случай 4**: Генерация публичного класса со статическим методом.
    CodeGenerator gen4(csharpFactory);
    gen4.addClass("MyClass", static_cast<unsigned int>(CSharpClassUnit::ClassModifier::PUBLIC));
    gen4.addMethod("myMethod", "int", CSharpMethodUnit::STATIC, CSharpClassUnit::PUBLIC);
    gen4.addPrint("Hello from C#");
    cout << gen4.generateCode().c_str() << Qt::endl;

    //Случай 5**: Генерация internal-класса с виртуальным приватным методом.
    CodeGenerator gen5(csharpFactory);
    gen5.addClass("MyClass1", static_cast<unsigned int>(CSharpClassUnit::ClassModifier::INTERNAL));
    gen5.addMethod("myMethod1", "void", CSharpMethodUnit::VIRTUAL, CSharpClassUnit::PRIVATE);
    gen5.addPrint("test");
    cout << gen5.generateCode().c_str() << Qt::endl;

    //Случай 6**: Генерация класса без модификатора доступа.
    CodeGenerator gen6(csharpFactory);
    gen6.addClass("DefaultClass");
    gen6.addMethod("defaultMethod", "string", 0, CSharpClassUnit::PRIVATE);
    gen6.addPrint("default");
    cout << gen6.generateCode().c_str() << Qt::endl;

    //Генерируем Java код
    cout << "Java (JavaCodeFactory)\n\n" << Qt::endl;

    std::shared_ptr<JavaCodeFactory> javaFactory = std::make_shared<JavaCodeFactory>();

    //Случай 7**: Генерация класса со статическим публичным методом.
    CodeGenerator gen7(javaFactory);
    gen7.addClass("MyClass");
    gen7.addMethod("myMethod", "int", JavaMethodUnit::STATIC, JavaClassUnit::PUBLIC);
    gen7.addPrint("Hello from Java");
    cout << gen7.generateCode().c_str() << Qt::endl;

    //Случай 8**: Генерация public abstract класса с абстрактным protected методом.
    CodeGenerator gen8(javaFactory);
    gen8.addClass("MyClass1",
                 static_cast<unsigned int>(JavaClassUnit::ClassModifier::PUBLIC)
                     | static_cast<unsigned int>(JavaClassUnit::ClassModifier::ABSTRACT));
    gen8.addMethod("myMethod1", "void", JavaMethodUnit::ABSTRACT, JavaClassUnit::PROTECTED);
    gen8.addPrint("abstract test");
    cout << gen8.generateCode().c_str() << Qt::endl;

    //Случай 9**: Генерация package-private класса (модификатор NONE).
    CodeGenerator gen9(javaFactory);
    gen9.addClass("PackageClass", static_cast<unsigned int>(JavaClassUnit::ClassModifier::NONE));
    gen9.addMethod("packageMethod", "void", 0, JavaClassUnit::PACKAGE_PRIVATE);
    gen9.addPrint("package test");
    cout << gen9.generateCode().c_str() << Qt::endl;


    //Случай 10**: Создание нескольких методов с разными модификаторами доступа в одном классе.
    //std::shared_ptr<CppCodeFactory> cppFactory = std::make_shared<CppCodeFactory>();

    CodeGenerator gen10(cppFactory);
    gen10.addClass("MultiMethodClass");

    gen10.addMethod("publicMethod", "void", CppMethodUnit::STATIC, CppClassUnit::PUBLIC);
    gen10.addPrint("public");

    gen10.addMethod("protectedMethod", "int", 0, CppClassUnit::PROTECTED);
    gen10.addPrint("protected");

    gen10.addMethod("privateMethod", "double", CppMethodUnit::CONST, CppClassUnit::PRIVATE);
    gen10.addPrint("private");

    cout << gen10.generateCode().c_str() << Qt::endl;

    //Случай 11**: Передача некорректного значения флага доступа (выход за границы массива ACCESS_MODIFIERS).
    CodeGenerator gen11(cppFactory);
    gen11.addClass("InvalidFlagClass");
    gen11.addMethod("someMethod", "void", 0, 999);
    gen11.addPrint("test");
    cout << gen11.generateCode().c_str() << Qt::endl;


    return 0;
}
