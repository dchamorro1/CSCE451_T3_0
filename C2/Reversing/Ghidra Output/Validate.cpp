
uint validate(vector param_1)

{
    ulong uVar1;
    basic_string *pbVar2;
    long lVar3;
    uint unaff_EBX;
    uint uVar4;
    undefined4 in_register_0000003c;
    vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
        *this;
    long in_FS_OFFSET;
    hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>> local_49;
    basic_string local_48[10];
    long local_20;

    this = (vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::a llocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                *)CONCAT44(in_register_0000003c, param_1);
    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string();
    uVar1 = std::
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::a llocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::size(this);
    if (uVar1 < 5)
    {
        uVar4 = 0;
    }
    else
    {
        uVar1 = std::
                    vector < std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>,
        std : : allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>> >
                ::size(this);
        if (uVar1 % 3 == 2)
        {
            pbVar2 = (basic_string *)
                std::
                    vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, s td::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<c har>>>>::operator[](this, 3);
            /* try { // try from 00104b61 to 00104bc7 has its CatchHandler @ 00104c0a */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_48, pbVar2);
        }
        uVar1 = std::
                    vector < std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>,
        std : : allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>> >
                ::size(this);
        if (uVar1 % 3 == 1)
        {
            pbVar2 = (basic_string *)
                std::
                    vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, s td::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<c har>>>>::operator[](this, 2);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_48, pbVar2);
        }
        lVar3 = std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>::operator()(&local_49, local_48);
        uVar4 = unaff_EBX & 0xffffff00 | (uint)(lVar3 == -0x25cfe64b5054e700);
    }
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_48);
    if (local_20 != *(long *)(in_FS_OFFSET + 0x28))
    {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return uVar4;
}
