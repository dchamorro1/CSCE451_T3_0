#include <stdio.h>

class Trie
{
public:
    TrieNode root;

    void __thiscall Trie::Node::Node(Node *this)
    {
        long i;
        Node **alphabet;
        long in_FS_OFFSET;
        allocator local_21;
        long canary;

        canary = *(long *)(in_FS_OFFSET + 0x28);
        i = 26;
        alphabet = this->alphabet;
        for (; i != 0; i = i + -1)
        {
            *alphabet = (Node *)0x0;
            alphabet = alphabet + 1;
        }
        this->some_flag = true;
        this->some_flag2 = false;
        std::allocator<char>::allocator();
        /* try { // try from 00110927 to 0011092b has its CatchHandler @ 0011094a */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)&this->maybe_curr_letter, "", &local_21);
        std::allocator<char>::~allocator((allocator<char> *)&local_21);
        if (canary != *(long *)(in_FS_OFFSET + 0x28))
        {
            /* WARNING: Subroutine does not return */
            __stack_chk_fail();
        }
        return;
    }

    /* Trie::find_wild(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
     */

    undefined (*)[16] Trie::find_wild(basic_string wild)
    {
        basic_string *in_RDX;
        Trie *trie;
        undefined4 in_register_0000003c;
        undefined(*potential_words)[16];

        potential_words = (undefined(*)[16])CONCAT44(in_register_0000003c, wild);
        *potential_words = (undefined[16])0x0;
        *(undefined8 *)potential_words[1] = 0;
        /* try { // try from 00110e4e to 00110e52 has its CatchHandler @ 00110e55 */
        _wild(trie, (Node **)trie, in_RDX, 0, (vector *)potential_words);
        return potential_words;
    }

    /* WARNING: Could not reconcile some variable overlaps */
    /* Trie::_wild(Trie::Node*&, std::__cxx11::basic_string<char, std::char_traits<char>,
       std::allocator<char> > const&, unsigned long, std::vector<std::__cxx11::basic_string<char,
       std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char,
       std::char_traits<char>, std::allocator<char> > > >&) */

    void __thiscall Trie::_wild(Trie *this, Node **nodes, basic_string *query_word, ulong index, vector *potential_words)
    {
        bool cVar3;
        bool cVar4;
        int char_index;
        char *letter;
        long in_FS_OFFSET;
        char character;
        int i_2;
        int i;
        Node *letter_node;
        long maybe_canary;
        bool add_word;
        Node *node_list;

        maybe_canary = *(long *)(in_FS_OFFSET + 0x28);
        if ((*nodes)->some_flag2 != false)
        {
            cVar3 = validate(this, *nodes);
            if (cVar3)
            {
                add_word = true;
                goto LAB_001132bc;
            }
        }
        add_word = false;
    LAB_001132bc:
        if (add_word)
        {
            std::
                vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocat or <std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::push_back((vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                                                                                                                                                                                                                         *)potential_words,
                                                                                                                                                                                                                    (basic_string *)&(*nodes)->maybe_curr_letter);
        }
        else
        {
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *)
                           query_word,
                       index);
            if (*letter == '!')
            {
                letter_node._0_4_ = 2;
            }
            else
            {
                letter_node._0_4_ = 1;
            }
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *)
                           query_word,
                       index);
            if (*letter == '!')
            {
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                                                 *)query_word,
                                                                                                                            index + 1);
                std::unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::insert((unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>> *)this->field2_0x40, letter);
                node_list = *nodes;
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                                                 *)query_word,
                                                                                                                            index + 1);
                char_index = Trie::index(this, letter);
                if (node_list->alphabet[char_index] != (Node *)0x0)
                {
                    node_list = *nodes;
                    letter = (char *)std::__cxx11::
                        basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                          *)query_word,
                                                                                                     index + 1);
                    char_index = Trie::index(this, letter);
                    node_list->alphabet[char_index]->some_flag = false;
                    node_list = *nodes;
                    letter = (char *)std::__cxx11::
                        basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                          *)query_word,
                                                                                                     index + 1);
                    char_index = Trie::index(this, letter);
                    std::
                        unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::allocator<T rie::Node *>>::insert((unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::a llocator<Trie::Node *>>
                                                                                                                                                      *)&this->field3_0x78,
                                                                                                                                                 node_list->alphabet + char_index);
                }
            }
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *)
                           query_word,
                       index);
            char_index = isalpha((int)*letter);
            if (char_index == 0)
            {
                for (i = 0; i < 26; i = i + 1)
                {
                    unique0x0000c000 = (*nodes)->alphabet[i];
                    if ((unique0x0000c000 == (Node *)0x0) || (unique0x0000c000->some_flag == false))
                    {
                    LAB_001135e6:
                        add_word = false;
                    }
                    else
                    {
                        character = (char)i + 'a';
                        cVar4 = (bool)std::
                            unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::contains((unordered_set<char, std::hash<char>, std::equal_to<char>, std::allo cator<char>>
                                                                                                                           *)this->field1_0x8,
                                                                                                                      &character);
                        if (cVar4 == true)
                            goto LAB_001135e6;
                        add_word = true;
                    }
                    if (add_word)
                    {
                        _wild(this, (Node **)((long)&letter_node + 4), query_word, (long)(int)letter_node + index,
                              potential_words);
                    }
                }
            }
            else
            {
                node_list = *nodes;
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                                                 *)query_word,
                                                                                                                            index);
                char_index = Trie::index(this, letter);
                unique0x0000c000 = node_list->alphabet[char_index];
                for (i_2 = 0; i_2 < 26; i_2 = i_2 + 1)
                {
                    if ((*nodes)->alphabet[i_2] == (Node *)0x0)
                    {
                    LAB_001134db:
                        add_word = false;
                    }
                    else
                    {
                        letter = (char *)std::__cxx11::
                            basic_string<char, std::char_traits<char>, std::allocator<char>>::
                            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                            *)query_word,
                                       index);
                        char_index = Trie::index(this, letter);
                        if (i_2 == char_index)
                            goto LAB_001134db;
                        add_word = true;
                    }
                    if (add_word)
                    {
                        (*nodes)->alphabet[i_2]->some_flag = false;
                        std::
                            unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::allocator<Trie::Node *>>::insert((unordered_set < Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std
                                                                                                                                                     :
                                                                                                                                                     : allocator < Trie::Node * >>
                                                                                                                                                                                     *)&this->field3_0x78,
                                                                                                                                                    (*nodes)->alphabet + i_2);
                    }
                }
                if ((stack0xffffffffffffffd8 != (Node *)0x0) && (stack0xffffffffffffffd8->some_flag != false))
                {
                    _wild(this, (Node **)((long)&letter_node + 4), query_word, (long)(int)letter_node + index,
                          potential_words);
                }
            }
        }
        if (maybe_canary != *(long *)(in_FS_OFFSET + 0x28))
        {
            /* WARNING: Subroutine does not return */
            __stack_chk_fail();
        }
        return;
    }

    int __thiscall Trie::index(Trie *this, char *letter)
    {
        return *letter + -97;
    }

    /* Trie::validate(Trie::Node const*) */

    bool __thiscall Trie::validate(Trie *this, Node *param_1)
    {
        bool reached_end;
        bool bVar1;
        char *character;
        long lVar2;
        long in_FS_OFFSET;
        undefined8 begin;
        undefined8 end;
        undefined1 *local_18;
        long canary;

        canary = *(long *)(in_FS_OFFSET + 0x28);
        local_18 = this->field2_0x40;
        begin = std::unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::begin((unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>> *)local_18);
        end = std::unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::end();
        do
        {
            reached_end = (bool)std::__detail::operator==((_Node_iterator_base *)&begin, (_Node_iterator_base *)&end);
            if (reached_end == true)
            {
                bVar1 = true;
            LAB_00113240:
                if (canary != *(long *)(in_FS_OFFSET + 0x28))
                {
                    /* WARNING: Subroutine does not return */
                    __stack_chk_fail();
                }
                return bVar1;
            }

            character = (char *)std::__detail::_Node_iterator<char, true, false>::operator*((_Node_iterator<char, true, false> *)&begin);
            lVar2 = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::find((basic_string<char, std::char_traits<char>, std::allocator<char>> *)&param_1->maybe_curr_letter, *character, 0);

            if (lVar2 == -1)
            {
                bVar1 = false;
                goto LAB_00113240;
            }
            std::__detail::_Node_iterator<char, true, false>::operator++((_Node_iterator<char, true, false> *)&begin);
        } while (true);
    }

    /* WARNING: Could not reconcile some variable overlaps */
    /* Trie::_wild(Trie::Node*&, std::__cxx11::basic_string<char, std::char_traits<char>,
       std::allocator<char> > const&, unsigned long, std::vector<std::__cxx11::basic_string<char,
       std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char,
       std::char_traits<char>, std::allocator<char> > > >&) */

    void __thiscall Trie::_wild(Trie *this, Node **nodes, basic_string *query_word, ulong index, vector *potential_words)
    {
        bool cVar3;
        bool cVar4;
        int char_index;
        char *letter;
        long in_FS_OFFSET;
        char character;
        int i_2;
        int i;
        Node *letter_node;
        long maybe_canary;
        bool add_word;
        Node *node_list;

        maybe_canary = *(long *)(in_FS_OFFSET + 0x28);
        if ((*nodes)->some_flag2 != false)
        {
            cVar3 = validate(this, *nodes);
            if (cVar3)
            {
                add_word = true;
                goto LAB_001132bc;
            }
        }
        add_word = false;
    LAB_001132bc:
        if (add_word)
        {
            std::
                vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocat or <std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::push_back((vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                                                                                                                                                                                                                         *)potential_words,
                                                                                                                                                                                                                    (basic_string *)&(*nodes)->maybe_curr_letter);
        }else{
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *)
                           query_word,
                       index);
            if (*letter == '!')
            {
                letter_node._0_4_ = 2;
            }
            else
            {
                letter_node._0_4_ = 1;
            }
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *) query_word, index);
            
            if (*letter == '!')
            {
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>*)query_word,index + 1);
                std::unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::insert((unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>> *)this->field2_0x40, letter);
                node_list = *nodes;
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                                                 *)query_word,
                                                                                                                            index + 1);
                char_index = Trie::index(this, letter);
                if (node_list->alphabet[char_index] != (Node *)0x0)
                {
                    node_list = *nodes;
                    letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>*)query_word,index + 1);
                    char_index = Trie::index(this, letter);
                    node_list->alphabet[char_index]->some_flag = false;
                    node_list = *nodes;
                    letter = (char *)std::__cxx11::
                        basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                          *)query_word,
                                                                                                     index + 1);
                    char_index = Trie::index(this, letter);
                    
                    std::unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::allocator<T rie::Node *>>::insert((unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::a llocator<Trie::Node *>>
                                                                                                                                                      *)&this->field3_0x78,
                                                                                                                                                 node_list->alphabet + char_index);
                }
            }
            letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>> *)
                           query_word,
                       index);
            char_index = isalpha((int)*letter);
            if (char_index == 0)
            {
                for (i = 0; i < 26; i = i + 1)
                {
                    unique0x0000c000 = (*nodes)->alphabet[i];
                    if ((unique0x0000c000 == (Node *)0x0) || (unique0x0000c000->some_flag == false))
                    {
                    LAB_001135e6:
                        add_word = false;
                    }
                    else
                    {
                        character = (char)i + 'a';
                        cVar4 = (bool)std::
                            unordered_set<char, std::hash<char>, std::equal_to<char>, std::allocator<char>>::contains((unordered_set<char, std::hash<char>, std::equal_to<char>, std::allo cator<char>>
                                                                                                                           *)this->field1_0x8,
                                                                                                                      &character);
                        if (cVar4 == true)
                            goto LAB_001135e6;
                        add_word = true;
                    }
                    if (add_word)
                    {
                        _wild(this, (Node **)((long)&letter_node + 4), query_word, (long)(int)letter_node + index,
                              potential_words);
                    }
                }
            }
            else
            {
                node_list = *nodes;
                letter = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                                                                                                                 *)query_word,
                                                                                                                            index);
                char_index = Trie::index(this, letter);
                unique0x0000c000 = node_list->alphabet[char_index];
                for (i_2 = 0; i_2 < 26; i_2 = i_2 + 1)
                {
                    if ((*nodes)->alphabet[i_2] == (Node *)0x0)
                    {
                    LAB_001134db:
                        add_word = false;
                    }
                    else
                    {
                        letter = (char *)std::__cxx11::
                            basic_string<char, std::char_traits<char>, std::allocator<char>>::
                            operator[]((basic_string<char, std::char_traits<char>, std::allocator<char>>
                                            *)query_word,
                                       index);
                        char_index = Trie::index(this, letter);
                        if (i_2 == char_index)
                            goto LAB_001134db;
                        add_word = true;
                    }
                    if (add_word)
                    {
                        (*nodes)->alphabet[i_2]->some_flag = false;
                        std::
                            unordered_set<Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std::allocator<Trie::Node *>>::insert((unordered_set < Trie::Node *, std::hash<Trie::Node *>, std::equal_to<Trie::Node *>, std
                                                                                                                                                     :
                                                                                                                                                     : allocator < Trie::Node * >>
                                                                                                                                                                                     *)&this->field3_0x78,
                                                                                                                                                    (*nodes)->alphabet + i_2);
                    }
                }
                if ((stack0xffffffffffffffd8 != (Node *)0x0) && (stack0xffffffffffffffd8->some_flag != false))
                {
                    _wild(this, (Node **)((long)&letter_node + 4), query_word, (long)(int)letter_node + index,
                          potential_words);
                }
            }
        }

        if (maybe_canary != *(long *)(in_FS_OFFSET + 0x28))
        {
            /* WARNING: Subroutine does not return */
            __stack_chk_fail();
        }

        return;
    }

}

void
FUN_00110020(void)
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
    bool begin_is_end;
    basic_ostream *output;
    basic_string *input;
    long in_FS_OFFSET;
    uint i;
    undefined8 begin;
    undefined8 end;
    vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
        *local_140;
    allocator local_asdf[32];
    Trie trie;
    basic_string key[8];
    basic_string word[10];
    undefined8 canary;

    canary = *(undefined8 *)(in_FS_OFFSET + 0x28);
    output = std::operator<<((basic_ostream *)std::cout, "Welcome to the wordle solver");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout,
                             "This is meant to help you beat the game wordle");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout,
                             "If you give us a \'key\' we can give you all the possible options");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout,
                             "For example if you konw the word is in the format:");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout, "a _ _ e t");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout,
                             "then, enter the key \'a**et\', and all possible options will be returned ");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);
    output = std::operator<<((basic_ostream *)std::cout, "\n\n\n\n");
    std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                 std::endl<char, std::char_traits<char>>);

    Trie::Trie(&trie);
    for (i = 0; i < 2317; i = i + 1)
    {
        std::allocator<char>::allocator();
        /* try { // try from 001104db to 001104df has its CatchHandler @ 0011069b */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word,
                                               (char *)(&Constants::WORDS)[(int)i], local_asdf);
        /* try { // try from 001104f1 to 001104f5 has its CatchHandler @ 0011068a */
        Trie::add_word(&trie, (basic_string)word);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word);
        std::allocator<char>::~allocator((allocator<char> *)local_asdf);
    }
    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)key);
    do
    {
        /* try { // try from 0011054c to 00110579 has its CatchHandler @ 001106e5 */
        std::operator<<((basic_ostream *)std::cout, "key: ");
        std::operator>>((basic_istream *)std::cin, key);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word, key);
        /* try { // try from 00110592 to 00110596 has its CatchHandler @ 001106af */
        Trie::find_wild((basic_string)local_asdf);
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word);
        Trie::reset(&trie);
        local_140 = (vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                         *)local_asdf;
        begin = std::
                    vector < std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>,
        std : : allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>> >
                ::begin(local_140);
        end = std::
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::a llocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::end(local_140);
        while (true)
        {
            begin_is_end = __gnu_cxx::operator==((__normal_iterator *)&begin, (__normal_iterator *)&end);
            if (begin_is_end)
                break;
            input = (basic_string *)
                __gnu_cxx::
                    __normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocato r<char>> *, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allo cator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std ::allocator<char>>>>>::operator*((__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> *, std::vector<std::__cxx11::basic_string<char, std::char_traits<ch ar>, std::allocator<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_tra its<char>, std::allocator<char>>>>>
                                                                                                                                                                                                                                                                                                                                        *)&begin);
            /* try { // try from 0011060a to 0011060e has its CatchHandler @ 001106d1 */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word, input);
            /* try { // try from 00110620 to 00110636 has its CatchHandler @ 001106c0 */
            output = std::operator<<((basic_ostream *)std::cout, word);
            std::basic_ostream<char, std::char_traits<char>>::operator<<((basic_ostream<char, std::char_traits<char>> *)output,
                                                                         std::endl<char, std::char_traits<char>>);
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)word);
            __gnu_cxx::
                __normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> *, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std ::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>>::operator++((__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::al locator<char>> *, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::alloca tor<char>>, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocato r<char>>>>>
                                                                                                                                                                                                                                                                                                                                   *)&begin);
        }
        std::
            vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocat or <std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>::~vector((vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, s td::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>>
                                                                                                                                                                                                                   *)local_asdf);
    } while (true);
}
