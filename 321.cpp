#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <accountssettingspaneinterop.h>
#include <string_view>
 
//komentarz Aleksander Wolak
int main()

{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    auto print = [&s](std::string_view const rem)
    {
        for (auto a : s)
            std::cout << a << ' ';
        std::cout << ": " << rem << '\n';
    };

    std::array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

 
    std::sort(s.begin(), s.end());
    print("rahhhhhh!!!!");
    print("sorted with the defaultt operator<");
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard  compare function object");
 
    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    }
    customLess;
 
    std::sort(s.begin(), s.end(), customLess);
 
    std::sort(s.begin(), s.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  });
    print("sorted with a lambda expression");
    int x = 5 + 4;
}
