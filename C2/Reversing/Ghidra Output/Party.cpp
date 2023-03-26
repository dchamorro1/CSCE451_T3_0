
basic_string *party(basic_string param_1)

{
    char cVar1;
    Friend *pFVar2;
    int iVar3;
    long lVar4;
    char *pcVar5;
    int iVar6;
    ulong in_RSI;
    undefined4 in_register_0000003c;
    basic_string *pbVar7;
    long in_FS_OFFSET;
    char local_55;
    float local_54;
    Friend *local_50;
    basic_string local_48[10];
    long local_20;

    pbVar7 = (basic_string *)CONCAT44(in_register_0000003c, param_1);
    local_20 = *(long *)(in_FS_OFFSET + 0x28);
    local_50 = (Friend *)operator.new(4);
    Friend::Friend(local_50);
    local_54 = -1.0513;
    do
    {
        lVar4 = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::size();
        if (lVar4 == 0)
        {
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(pbVar7);
            goto LAB_00103cb2;
        }
        pcVar5 = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
        operator[](in_RSI);
        pFVar2 = local_50;
        local_55 = *pcVar5;
        iVar3 = Friend::approach(local_50, 2);
        Friend::handshake(pFVar2, &local_55, iVar3 != 0);
        cVar1 = local_55;
        pcVar5 = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
        operator[](in_RSI);
        pFVar2 = local_50;
        *pcVar5 = cVar1;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(local_48);
        /* try { // try from 00103c47 to 00103c4b has its CatchHandler @ 00103cc3 */
        iVar3 = Friend::conversation(SUB81(pFVar2, 0), 0);
        iVar6 = (int)local_54;
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_48);
    } while (iVar3 != iVar6);
    if (local_50 != (Friend *)0x0)
    {
        operator.delete(local_50, 4);
    }
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator+=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)FalsAns [abi:cxx11],
                                                                                               "you");
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string(pbVar7);
LAB_00103cb2:
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28))
    {
        return pbVar7;
    }
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
}