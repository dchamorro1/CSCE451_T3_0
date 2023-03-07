void _wild(Node **nodes, string *query_word, long index, vector<string> *potential_words){
        bool cVar3;
        bool cVar4;
        int char_index;
        char *letter;
        char character;

        long offset;

        Node *letter_node;
        long maybe_canary;
        bool add_word;
        Node *node_list;

        maybe_canary = offset + 40;

        if(*nodes->some_flag == true){
            cVar3 = validate(*nodes);

            if(cVar3){
                add_word = true;

                if(add_word){
                    potential_words->push_back(*query_word);
                }else{
                    letter = (char *)*nodes->letter;
                    char_index = index(this, letter);

                    if(*letter == '!'){
                        letter_node._0._4_ = 2;
                    }else{
                        letter_node._0._4_ = 1;
                    }

                    letter = (char *)*nodes->letter;

                    if(*letter == '!'){
                        letter = (char *)*nodes->letter;
                        potential_words.insert(this, letter, *nodes);
                        node_list = *nodes;

                        letter = (char *)*nodes->letter;

                        char_index = index(this, letter);

                        if(node_list->alphabet[char_index] != nullptr){
                            node_list = *nodes;
                            letter = (char *)*nodes->letter;
                            char_index = index(this, letter);
                            node_list = node_list->alphabet[char_index];

                            node_list = *nodes;
                            letter = (char *)*nodes->letter;

                            char_index = index(this, letter);

                            potential_words.insert(this, letter, node_list->alphabet[char_index]);
    

                        }
                    }
                    letter = (char *)*nodes->letter;
                    char_index = isalpha((int)*letter)

                    if(char_index == 0){
                        for(int i = 0; i < 26; i++){
                            unique = *nodes->alphabet[i];

                            if((unique == nullptr) || (unique->some_flag == false)){
                                add_word = false;
                            }else{
                                character = (char)i + 'a';
                                cVar4 = unique.contains(character);

                                if(cVar4){
                                    add_word = false;
                                }
                                add_word = true;
                            }
                            if(add_word){
                                _wild(unique, query_word, index + 4, potential_words);
                            }
                        }
                    }
                    else{
                        node_list = *nodes;
                        letter = (char *)*nodes->letter;
                        char_index = index(this, letter);
                        unique = node_list->alphabet[char_index];

                        for (int i = 0; i < 26; i++){
                            if((*nodes)->alphabet[i] == nullptr){
                                add_word = false;
                            }else{
                                letter = (char *)*nodes->letter;
                                char_index = index(this, letter);
                                if (i == char_index){
                                    add_word = true;
                                }
                            }
                            if(add_word){
                                *nodes->alphabet[i].some_flag = true;
                                potential_words.insert(this, letter, *nodes->alphabet[i]);
                            }
                        }
                        if ((stack != nullptr) && (stack->some_flag == true)){
                            _wild(stack, query_word, index + 4, potential_words);
                        }
                    }


                    
                }
                if(maybe_canary != 0x28){
                    return 1;
                }
                return;
            }
            else{
                add_word = false;
            }
        }
    }