
undefined4 main(int argc, char **argv)

{
    bool iostream_status;
    byte bVar1;
    int iVar2;
    basic_ostream *output;
    basic_istream *input_stream;
    undefined4 unaff_EBX;
    long in_FS_OFFSET;
    SkyNet skynet;
    int index;
    uint local_270;
    uint check2_output;
    vector list[8];
    unique_ptr funroom[32];
    basic_string input_line[8];
    basic_string size[8];
    basic_string tmp_str[8];
    basic_string other_tmp_str[8];
    basic_string cin[98];

    /* try { // try from 00104fa1 to 00104fa5 has its CatchHandler @ 001051b6 */
    bVar1 = validate((vector)funroom);
    local_270 = (uint)bVar1;
    std::
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::~vector((vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std ::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                                                                                                                                                                                                             *)funroom);
    /* try { // try from 00104fd2 to 00104fd6 has its CatchHandler @ 001051fe */
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(other_tmp_str);
    /* try { // try from 00104fe1 to 00104fe5 has its CatchHandler @ 001051ce */
    iostream_status = check2((basic_string)other_tmp_str);
    check2_output = (uint)iostream_status;
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)other_tmp_str);
    if (1 < argc)
    {
        /* try { // try from 00105032 to 00105068 has its CatchHandler @ 001051fe */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)argument [abi:cxx11], argv[1]);
        /* first argument needs to be "win!" */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator+=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)FalsAns [abi:cxx11],
                                                                                                   "win!");
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(other_tmp_str);
        iVar2 = KalmanFilter((basic_string)other_tmp_str);
        /* try { // try from 00105090 to 001050a3 has its CatchHandler @ 001051e6 */
        iVar2 = SkyNet::NeuralNetwork(&skynet, check2_output, check2_output, iVar2);
        Goal(iVar2 != 0);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)other_tmp_str);
    }
    else
    {
        unaff_EBX = 0;
    }
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)size);
    std::
        vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::~vector((vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std ::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                                                                                                                                                                                                             *)list);
    std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char>>::
        ~basic_stringstream((basic_stringstream<char, std::char_traits<char>, std::allocator<char>> *)cin);
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)input_line);
    if (1 < argc)
    {
        unaff_EBX = 0;
    }
    if (canary != *(long *)(in_FS_OFFSET + 0x28))
    {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return unaff_EBX;
}
