
/* Goal(bool) */

void Goal(bool param_1)

{
    basic_ostream *this;

    if (param_1)
    {
        this = std::operator<<((basic_ostream *)std::cout, (basic_string *)goalString [abi:cxx11]);
        std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)this,
                                                                     std::endl<char, std::char_traits<char>>);
    }
    return;
}
