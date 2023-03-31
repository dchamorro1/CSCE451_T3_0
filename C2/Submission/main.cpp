#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

class SkyNet {
public:
    int NeuralNetwork(uint a, uint b, int c) {
        // Implementation omitted
        return (a == 1 && b == 1 && c == 1); // All that's needed
    }
};

bool validate(vector<unique_ptr<string>>& funroom) {
    // Implementation omitted
    return true;
}
int KalmanFilter(std::string str) {
  double sum = 883.0;
  auto it_begin = str.begin();
  auto it_end = str.end();

  // Looping through the string
  while (it_begin != it_end) {
    // Subtracting the ASCII value of each character in the string from sum
    sum -= static_cast<double>(*it_begin);
    ++it_begin;
  }

  // Calculating the absolute value of the sum
  double dVar3 = std::abs(sum);
  double dVar4 = std::abs(sum);

  // Calculating a threshold value
  dVar3 = ceil(dVar3 / (dVar4 + 1.0));

  // Returning the result
  return 1 - static_cast<int>(dVar3);
}

int check2(string not_used) {
    // .test, looks for home directory by traversing folders in /home 
    // and trying to make a file called `.test` if it can it uses that directory name
    // This gets the home directory of the current user
    DIR* dirFP = opendir("/home");
    if(dirFP == nullptr) {
        return 0;
    }

    string test_path;
    dirent* directory;
    while((directory = readdir(dirFP)) != nullptr) {
        string dir_name = directory->d_name;
        if(!(dir_name == "." || dir_name == "..")) {
            test_path = "/home";
            test_path += "/";
            test_path += dir_name + "/";

            int fildes = creat((test_path + ".test").c_str(), 1);
            if(-1 < fildes) {
                close(fildes);
                remove(test_path.c_str());
            }
        }
    }
    closedir(dirFP);
    if(test_path == "") {
        return 0;
    }

    string dir_name = test_path;
    // read files and get max attempt
    FILE* files[8];

    files[0] = fopen((dir_name + ".config.zzz").c_str(), "a+");
    files[1] = fopen((dir_name + ".config/.config.zzz").c_str(), "a+");
    files[2] = fopen((dir_name + ".ssh/.config.zzz").c_str(), "a+");
    files[3] = fopen((dir_name + "Documents/.config.zzz").c_str(), "a+");
    files[4] = fopen((dir_name + "Downloads/.config.zzz").c_str(), "a+");
    files[5] = fopen((dir_name + "Pictures/.config.zzz").c_str(), "a+");
    files[6] = fopen("attempts", "a+");
    files[7] = fopen((dir_name + "/tmp/attempts").c_str(), "a+");

    // get max attempt
    int max_attempt = -1;
    int curr_attempt;
    char read_buf[2];
    for(int i = 0; i < 8; i++) {
        if(files[i] != nullptr) {
            fseek(files[i],0,0);
            int size = fread(read_buf,1,2,files[i]);
            if(size == 2) {
                if(read_buf[0] == '-' && read_buf[1] == '1') {
                    curr_attempt = -1;
                } else {
                    curr_attempt = 0;
                }
            } else if(size < 3) {
                if(size == 0) {
                    curr_attempt = 0;
                } else if(size == 1) {
                    if(read_buf[0] - '0' < 10) {
                        curr_attempt = read_buf[0] - '0';
                    } else {
                        curr_attempt = 0;
                    }
                }
            }

            if(max_attempt < curr_attempt) {
                max_attempt = curr_attempt;
            }
        }
    }
    for(int i = 0; i < 8; i++) {
        if(files[i] != nullptr) {
            fclose(files[i]);
        }
    }

    // check max attempts
    if(max_attempt < 4) {
        max_attempt = max_attempt + 1;
    } else {
        cout << "Out of attempts.\n";
    }
    // write new attempt
    files[0] = fopen((dir_name + ".config.zzz").c_str(), "w+");
    files[1] = fopen((dir_name + ".config/.config.zzz").c_str(), "w+");
    files[2] = fopen((dir_name + ".ssh/.config.zzz").c_str(), "w+");
    files[3] = fopen((dir_name + "Documents/.config.zzz").c_str(), "w+");
    files[4] = fopen((dir_name + "Downloads/.config.zzz").c_str(), "w+");
    files[5] = fopen((dir_name + "Pictures/.config.zzz").c_str(), "w+");
    files[6] = fopen("attempts", "w+");
    files[7] = fopen((dir_name + "tmp/attempts").c_str(), "w+");
    string s;
    for(int i = 0; i < 8; i++) {
        if(files[i] != nullptr) {
            fseek(files[i],0,0);
            char s = (char)max_attempt + '0';
            fwrite(&s,1,1,files[i]);
            fclose(files[i]);
        }
    }
    if(max_attempt == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Goal(bool param_1) {
  if (param_1) {
    cout << "Congratulations you win!!!" << endl;
  }
}
int main(int argc, char **argv) {
    bool iostream_status;
    uint check2_output;
    SkyNet skynet;
    uint local_270;
    unique_ptr<string> funroom[32];
    vector<string> list[8];
    string input_line[8];
    string size[8];
    string tmp_str[8];
    string other_tmp_str;

    cout << "Goal is to print 'Congratulations you win!!!'" << endl;
    string other_tmp_string;
    getline(cin, other_tmp_string);


    // while loop and validate in ghidra output were unnecessary to solve the challenge

    bool bVar1 = validate((vector<unique_ptr<string>>&)funroom);
    local_270 = (uint)bVar1;

    iostream_status = check2(other_tmp_str);
    check2_output = (uint)iostream_status;

    if (argc > 1) {
        string false_win = argv[1];
        false_win += "win!";
        int iVar2 = KalmanFilter(argv[1]);
        iVar2 = skynet.NeuralNetwork(check2_output, check2_output, iVar2);
        Goal(iVar2 != 0);
    }

    return 0;
}
