#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

void print_vector(vector<string> vec) {
    for(auto& v : vec) {
        cout << v << endl;
    }
}

vector<string> process_file_line(ifstream& ifs) {
    vector<string> out;
    string str;

    cout << __func__ << endl;
    while(getline(ifs, str)) {
        out.push_back(str);
    }

    return out;
}

vector<string> process_file_word(ifstream& ifs) {
    vector<string> out;
    char str[1024];

    cout << __func__ << endl;
    while(ifs.getline(str, 1024, ' ')) {
        //int len = strlen(str);
        //str[len] = '|';
        //str[len+1] = '\0';
        //cout << str << endl;
        out.push_back(str);
    }

    return out;
}


int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    vector<string> vec;

    if (argc < 2) {
        cout << "Please pass the file-name as argument!\n";
        return -1;
    }

    if (file) {
        // process file
        vec = process_file_line(file);
        print_vector(vec);

        file.clear();
        file.seekg(0);
        vec = process_file_word(file);
        print_vector(vec);
    }
    else {
        cout << "Can't open file \"" << argv[1] << "\"\n" << endl;
    }
    
    return 0;
}