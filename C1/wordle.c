#include <stdio.h>

void FUN_00110020(void)
{
    /* WARNING: Treating indirect jump as call */
    (*(code *)(undefined *)0x0)();
    return;
}

/* WARNING: Removing unreachable block (ram,0x00110253) */
/* WARNING: Removing unreachable block (ram,0x0011025f) */
void FUN_00110240(void)
{
    return;
}

/* WARNING: Removing unreachable block (ram,0x00110294) */
/* WARNING: Removing unreachable block (ram,0x001102a0) */
void FUN_00110270(void)
{
    return;
}

void FUN_001102b0(void)
{
    if (DAT_00125378 != '\0')
    {
        return;
    }
    __cxa_finalize(&__dso_handle);
    FUN_00110240();
    DAT_00125378 = 1;
    return;
}

void main(void)
{
    char cVar1;
    undefined8 uVar2;
    long in_FS_OFFSET;
    uint local_154;
    undefined8 local_150;
    undefined8 local_148;
    undefined *local_140;
    undefined local_138[32];
    undefined local_118[176];
    undefined local_68[32];
    undefined local_48[40];
    undefined8 local_20;

    local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "Welcome to the wordle solver");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "This is meant to help you beat the game wordle");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "If you give us a \'key\' we can give you all the possible options");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "For example if you konw the word is in the format:");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "a _ _ e t");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout,
                                                                    "then, enter the key \'a**et\', and all possible options will be returned");
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    uVar2 = _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, &DAT_0011b7a7);
    _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
    _ZN4TrieC2Ev(local_118);
    for (local_154 = 0; local_154 < 0x90d; local_154 = local_154 + 1)
    {
        _ZNSaIcEC1Ev(local_138);
        /* try { // try from 001104db to 001104df has its CatchHandler @ 0011069b */
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_(local_48, *(undefined8 *)(_ZN9Constants5WORDSE + (long)(int)local_154 * 8), local_138);
        /* try { // try from 001104f1 to 001104f5 has its CatchHandler @ 0011068a */
        _ZN4Trie8add_wordENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(local_118, local_48);
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(local_48);
        _ZNSaIcED1Ev(local_138);
    }
    _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev(local_68);
    do
    {
        /* try { // try from 0011054c to 00110579 has its CatchHandler @ 001106e5 */
        _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc(_ZSt4cout, "key: ");
        _ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_ EE(_ZSt3cin, local_68);
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS4_(local_48, local_68);
        /* try { // try from 00110592 to 00110596 has its CatchHandler @ 001106af */
        _ZN4Trie9find_wildENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(local_138, local_118, local_48);
        _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(local_48);
        _ZN4Trie5resetEv(local_118);
        local_140 = local_138;
        local_150 = _ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE5beginEv(local_140);
        local_148 = _ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE3endEv(local_140);
        while (true)
        {
            cVar1 = _ZN9__gnu_cxxeqIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt6vectorIS6_SaIS 6_EEEEbRKNS_17__normal_iteratorIT_T0_EESG_(&local_150, &local_148);
            if (cVar1 == '\x01')
                break;
            uVar2 = _ZNK9__gnu_cxx17__normal_iteratorIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE ESt6vectorIS6_SaIS6_EEEdeEv(&local_150);
            /* try { // try from 0011060a to 0011060e has its CatchHandler @ 001106d1 */
            _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2ERKS4_(local_48, uVar2);
            /* try { // try from 00110620 to 00110636 has its CatchHandler @ 001106c0 */
            uVar2 = _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_strin gIS4_S5_T1_EE(_ZSt4cout, local_48);
            _ZNSolsEPFRSoS_E(uVar2, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_);
            _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(local_48);
            _ZN9__gnu_cxx17__normal_iteratorIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt6vecto rIS6_SaIS6_EEEppEv(&local_150);
        }
        _ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev(local_138);
    } while (true);
}