
#include <iostream>
#include <string>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>

class strxor
{
private:
    unsigned char ascii2int(int in);
    unsigned char getbytefrom_hexstr(std::string str, int pos);

public:
    strxor();
    ~strxor();
    std::string hexstr2str(std::string in);
    std::string str2hexstr(std::string in);
    std::string xor_str(std::string a, std::string b);
};
