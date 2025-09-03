#include <iostream>
#include <string_view>

void myPrint(std::string_view str){
    std::cout << str << std::endl;
}

void myPrint(const std::string& str){
    std::cout << str << std::endl;
}

int main(void) {
    std::string strString = "123";
    char strChars[4] = "456";
    myPrint(strString);
    myPrint(strChars);

    /*
    这里的问题是：

    string_view 的构造函数是 constexpr basic_string_view(const CharT* str)

    这个构造函数要求指针是 const char*

    而 char strChars[4] 退化后类型是 char*，不是 const char*，需要一个标准转换（加 const）

    在函数重载解析时：

    string_view 版本：char* → const char* → string_view （两个转换步骤）

    const std::string& 版本：char* → std::string （用户自定义转换一次）

    编译器会选择“转换步数更少”的 → 选 std::string 版本，结果这个版本需要构造临时 std::string，而临时对象不能绑定到非常量引用（不过你这里是 const std::string&，所以可以绑定）。
    但有的编译器因为歧义会直接报错（尤其在 C++17 之前的标准实现里）。
    
    */

    return 0;
}