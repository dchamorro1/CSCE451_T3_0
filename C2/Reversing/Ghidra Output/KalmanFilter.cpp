
/* KalmanFilter(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) */

int KalmanFilter(basic_string param_1)

{
    bool has_ended;
    char *curr_string;
    int __x;
    undefined4 in_register_0000003c;
    long in_FS_OFFSET;
    double extraout_XMM0_Qa;
    double extraout_XMM0_Qa_00;
    double dVar1;
    undefined8 begin;
    undefined8 end;
    double local_30;
    undefined8 local_28;
    long canary;
    undefined8 *begin_ref;

    local_28 = CONCAT44(in_register_0000003c, param_1);
    canary = *(long *)(in_FS_OFFSET + 0x28);
    local_30 = 883.0;
    begin = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::begin();
    end = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::end();
    while (true)
    {
        begin_ref = &begin;
        has_ended = __gnu_cxx::operator!=((__normal_iterator *)begin_ref, (__normal_iterator *)&end);
        __x = (int)begin_ref;
        if (!has_ended)
            break;
        curr_string = (char *)__gnu_cxx::
            __normal_iterator<char *, std::__cxx11::basic_string<char, std::char_traits<c har>, std::allocator<char>>>::operator*((__normal_iterator<char *, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>
                                                                                                                                       *)&begin);
        local_30 = local_30 - (double)(int)*curr_string;
        __gnu_cxx::
            __normal_iterator<char *, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<ch ar>>>::operator++((__normal_iterator<char *, std::__cxx11::basic_string<char, std::char_traits<char>, std ::allocator<char>>>
                                                                                                                                        *)&begin);
    }
    std::abs(__x);
    std::abs(__x);
    dVar1 = ceil(extraout_XMM0_Qa / (extraout_XMM0_Qa_00 + 1.0));
    if (canary != *(long *)(in_FS_OFFSET + 0x28))
    {
        /* WARNING: Subroutine does not return */
        __stack_chk_fail();
    }
    return 1 - (int)dVar1;
}
