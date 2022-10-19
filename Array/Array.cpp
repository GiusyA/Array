#include "Array.h"
#include <iostream>
#include <string>

#pragma region declaration methods
template <typename T>
void Display(const Array<T>& _other);
#pragma endregion

#pragma region main
int main()
{
#pragma region tab1
    Array<int> _tab1 = Array<int>(4, 5);
    Display(_tab1);
#pragma endregion

#pragma region tab2
    Array<int> _tab2 = Array<int>{ 1, 2, 3, 4, 5 };
    Display(_tab2);

    std::cout << _tab2.Back() << std::endl;
    std::cout << _tab2.Front() << std::endl;
    
    _tab2.Resize(7);
    Display(_tab2);

    _tab2.Resize(3);
    Display(_tab2);
#pragma endregion

#pragma region tab3
    Array<std::string> _tab3 = Array<std::string>{ "Toto", "Titi", "Tutu" };
    _tab3.Resize(5);
    Display(_tab3);

    _tab3.Clear();
    _tab3.Back() = "Toto";
    _tab3.Front() = "Titi";
    Display(_tab3);
#pragma endregion

#pragma region test
    if (_tab1 != _tab2) std::cout << "tab1 != tab2" << std::endl;
    if (_tab1 == _tab1) std::cout << ":)" << std::endl;
#pragma endregion

#pragma region delete
    _tab1.~Array();
    _tab2.~Array();
    _tab3.~Array();
#pragma endregion
}
#pragma endregion

#pragma region methods
template <typename T>
void Display(const Array<T>& _other)
{
    for (size_t i = 0; i < _other.Count(); i++)
    {
        if (_other[i] == T())
        {
            std::cout << "-" << " ";
            continue;
        }
        std::cout << _other[i] << " ";
    }
    std::cout << std::endl;
}
#pragma endregion
