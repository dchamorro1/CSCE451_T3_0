
/* check2(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >) */

bool check2(basic_string param_1)

{
    long lVar1;
    char *path;
    size_t read_size;
    bool ret_output;
    long in_FS_OFFSET;
    allocator alloc;
    int num_attempts_max;
    int index2;
    int num_attempts_curr;
    int index3;
    int index;
    int local_e0;
    int file_pointer;
    DIR *dir_fp;
    dirent *directory;
    basic_string local_c8[8];
    basic_string d_name[8];
    basic_string local_88[8];
    FILE *files[5];
    char file_attempts[2];

    lVar1 = *(long *)(in_FS_OFFSET + 0x28);
    dir_fp = opendir("/home");
    if (dir_fp == (DIR *)0x0)
    {
        ret_output = false;
    }
    else
    {
        std::allocator<char>::allocator();
        /* try { // try from 00103e63 to 00103e67 has its CatchHandler @ 00104851 */
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
            basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_c8, "", &alloc);
        std::allocator<char>::~allocator((allocator<char> *)&alloc);
        /* try { // try from 0010403e to 001040af has its CatchHandler @ 00104a8b */
        while (directory = readdir(dir_fp), directory != (dirent *)0x0)
        {
            std::allocator<char>::allocator();
            /* try { // try from 00103eaa to 00103eae has its CatchHandler @ 00104872 */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)d_name,
                                                   directory->d_name, &alloc);
            std::allocator<char>::~allocator((allocator<char> *)&alloc);
            ret_output = std::operator==(d_name, ".");
            if ((ret_output) || (ret_output = std::operator==(d_name, ".."), ret_output))
            {
                ret_output = true;
            }
            else
            {
                ret_output = false;
            }
            if (!ret_output)
            {
                /* try { // try from 00103f2a to 00103f2e has its CatchHandler @ 001048b7 */
                std::operator+((char *)files, (basic_string *)"/home/");
                /* try { // try from 00103f44 to 00103f48 has its CatchHandler @ 0010488d */
                std::operator+(local_88, (char *)files);
                std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)d_name, local_88);
                std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
                std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)files);
                /* try { // try from 00103f8f to 00103f93 has its CatchHandler @ 001048b7 */
                std::operator+((basic_string *)files, (char *)d_name);
                path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::c_str();
                /* try { // try from 00103fa8 to 00103ffc has its CatchHandler @ 001048a2 */
                file_pointer = creat(path, 1);
                if (-1 < file_pointer)
                {
                    close(file_pointer);
                    path = (char *)std::__cxx11::
                        basic_string<char, std::char_traits<char>, std::allocator<char>>::c_str();
                    remove(path);
                    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::operator=((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_c8,
                                                                                                              d_name);
                }
                std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)files);
            }
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)d_name);
        }
        closedir(dir_fp);
        ret_output = std::operator==(local_c8, "");
        if (ret_output)
        {
            ret_output = false;
        }
        else
        {
            /* start reading files */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001040cc to 001040d0 has its CatchHandler @ 001048d2 */
            files[0] = fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 001040f9 to 001040fd has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 0010411a to 0010411e has its CatchHandler @ 001048ea */
            files[1] = fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104147 to 0010414b has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104168 to 0010416c has its CatchHandler @ 00104902 */
            files[2] = fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104195 to 00104199 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001041b6 to 001041ba has its CatchHandler @ 0010491a */
            files[3] = fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 001041e3 to 001041e7 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104204 to 00104208 has its CatchHandler @ 00104932 */
            files[4] = fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104231 to 00104235 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104252 to 00104256 has its CatchHandler @ 0010494a */
            fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            std::allocator<char>::allocator();
            /* try { // try from 0010428e to 00104292 has its CatchHandler @ 00104977 */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88,
                                                   "attempts", &alloc);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001042af to 001042b3 has its CatchHandler @ 00104962 */
            fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            std::allocator<char>::~allocator((allocator<char> *)&alloc);
            std::allocator<char>::allocator();
            /* try { // try from 001042fa to 001042fe has its CatchHandler @ 001049a7 */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88,
                                                   "/tmp/attempts", &alloc);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 0010431b to 0010431f has its CatchHandler @ 00104992 */
            fopen(path, "a+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            std::allocator<char>::~allocator((allocator<char> *)&alloc);
            num_attempts_max = -1;
            for (index2 = 0; index2 < 8; index2 = index2 + 1)
            {
                if (files[index2] != (FILE *)0x0)
                {
                    fseek(files[index2], 0, 0);
                    /* try { // try from 001043ae to 001044fd has its CatchHandler @ 00104a8b */
                    read_size = fread(file_attempts, 1, 2, files[index2]);
                    local_e0 = (int)read_size;
                    if (local_e0 == 2)
                    {
                        if ((file_attempts[0] == '-') && (file_attempts[1] == '1'))
                        {
                            num_attempts_curr = -1;
                        }
                        else
                        {
                            num_attempts_curr = 0;
                        }
                    }
                    else if (local_e0 < 3)
                    {
                        if (local_e0 == 0)
                        {
                            num_attempts_curr = 0;
                        }
                        else if (local_e0 == 1)
                        {
                            if ((int)file_attempts[0] - L'0' U < 10)
                            {
                                num_attempts_curr = file_attempts[0] + -48;
                            }
                            else
                            {
                                num_attempts_curr = 0;
                            }
                        }
                    }
                    if (num_attempts_max < num_attempts_curr)
                    {
                        num_attempts_max = num_attempts_curr;
                    }
                }
            }
            for (index3 = 0; index3 < 8; index3 = index3 + 1)
            {
                if (files[index3] != (FILE *)0x0)
                {
                    fclose(files[index3]);
                }
            }
            /* check if max attempts in the files < 4 or not */
            if (num_attempts_max < 4)
            {
                num_attempts_max = num_attempts_max + 1;
            }
            else
            {
                std::operator<<((basic_ostream *)std::cout, "Out of attempts.\n");
            }
            /* start writing file */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 0010451a to 0010451e has its CatchHandler @ 001049c2 */
            files[0] = fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104547 to 0010454b has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104568 to 0010456c has its CatchHandler @ 001049da */
            files[1] = fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104595 to 00104599 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001045b6 to 001045ba has its CatchHandler @ 001049f2 */
            files[2] = fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 001045e3 to 001045e7 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104604 to 00104608 has its CatchHandler @ 00104a0a */
            files[3] = fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 00104631 to 00104635 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 00104652 to 00104656 has its CatchHandler @ 00104a1f */
            files[4] = fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* try { // try from 0010467f to 00104683 has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001046a0 to 001046a4 has its CatchHandler @ 00104a34 */
            fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            std::allocator<char>::allocator();
            /* try { // try from 001046dc to 001046e0 has its CatchHandler @ 00104a5e */
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                basic_string<std::allocator<char>>((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88,
                                                   "attempts", &alloc);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 001046fd to 00104701 has its CatchHandler @ 00104a49 */
            fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            std::allocator<char>::~allocator((allocator<char> *)&alloc);
            /* try { // try from 00104739 to 0010473d has its CatchHandler @ 00104a8b */
            std::operator+(local_88, (char *)local_c8);
            path = (char *)std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::
                c_str();
            /* try { // try from 0010475a to 0010475e has its CatchHandler @ 00104a76 */
            fopen(path, "w+");
            std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_88);
            /* Write max attempts to all the files */
            for (index = 0; index < 8; index = index + 1)
            {
                if (files[index] != (FILE *)0x0)
                {
                    fseek(files[index], 0, 0);
                    alloc = (allocator)((char)num_attempts_max + '0');
                    /* try { // try from 001047e2 to 001047fb has its CatchHandler @ 00104a8b */
                    fwrite(&alloc, 1, 1, files[index]);
                    fclose(files[index]);
                }
            }
            /* returns true only if max attempts is 0 */
            if (num_attempts_max == 0)
            {
                ret_output = true;
            }
            else
            {
                ret_output = false;
            }
        }
        std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string((basic_string<char, std::char_traits<char>, std::allocator<char>> *)local_c8);
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28))
    {
        return ret_output;
    }
    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
}
