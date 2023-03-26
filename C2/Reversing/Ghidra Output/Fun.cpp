
basic_string *fun(basic_string param_1)

{
    Funroom *this;
    basic_string *in_RSI;
    undefined4 in_register_0000003c;
    long in_FS_OFFSET;
    basic_string local_68[8];
    basic_string local_48[10];
    long canary;

    canary = *(long *)(in_FS_OFFSET + 0x28);
    this = (Funroom *)
               std::unique_ptr<Funroom, std::default_delete<Funroom>>::operator->((unique_ptr<Funroom, std::default_delete<Funroom>> *)&funptr);
    Funroom::ballon(this, in_RSI);
    std::unique_ptr<Funroom, std::default_delete<Funroom>>::operator->((unique_ptr<Funroom, std::default_delete<Funroom>> *)&funptr);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(local_68);
    /* try { // try from 00103d68 to 00103d6c has its CatchHandler @ 00103dbc */
    Funroom::cake((basic_string)local_48);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)in_RSI, local_48);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_48);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_68);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((basic_string *)CONCAT44(in_register_0000003c, param_1));
    if (canary != *(long *)(in_FS_OFFSET + 0x28))
    {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return (basic_string *)CONCAT44(in_register_0000003c, param_1);
}