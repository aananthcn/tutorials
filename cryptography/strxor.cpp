// message OTP - 6c73d5240a948c86981bc294814d
#include "strxor.h"

strxor::strxor(/* args */) {
    std::cout << "constructor\n";
}

strxor::~strxor() {
    std::cout << "destructor\n";
}

unsigned char strxor::ascii2int(int in) {
    unsigned char out;

    if (in >= 97) {
        out = in - 97 + 10;
    }
    else if ( in >= 65) {
        out = in - 65 + 10;
    }
    else if (in >= 48) {
        out = in - 48;
    }

    return out;
}

unsigned char strxor::getbytefrom_hexstr(std::string str, int pos) {
    int msn, lsn;
    int len = str.size();
    //std::cout << "str = " << &str[pos] << "\n";

    if ((pos + 2) <= len) {
        msn = ascii2int(str[pos]);
        lsn = ascii2int(str[pos+1]);
    }
    else {
        std::cout << "Error: reached invalid case!: " << __FILE__ << ":" << __func__ << "()\n";
        std::cout << "\t pos = " << pos << " len = " << len << "\n";
        return 0; //end of string
    }

    //std::cout << "msn = " << msn << ", lsn = " << lsn << "\n";
    return (unsigned char)((msn << 4) & 0xF0 | (lsn & 0xF)); 
}

std::string strxor::hexstr2str(std::string in) {
    std::string str;
    int len = in.size();
    str.resize(len);

    for (int i = 0; i < len; i += 2) {
        str[i/2] = getbytefrom_hexstr(in, i);
    }

    return str;
}

std::string strxor::str2hexstr(std::string in) {
    std::string out;
    int len = in.size();
    out.resize(len*2);

    for (int i = 0; i < len; i++) {
        sprintf(&out[i*2], "%02x", (unsigned char) in[i]);
    }

    return out;
}

std::string strxor::xor_str(std::string a, std::string b) {
    // this function assumes both a & b are normal strings
    std::string res;
    int len, out;

    a.size() > b.size() ? len = b.size() : len = a.size();
    res.resize(len);
    if (len == 0) {
        std::cout << "Error: len = 0\n";
        std::cout << "\ta = " << a << "\n";
        std::cout << "\tb = " << b << "\n";
        exit(-1);
    }

    //std::cout << "len = " << std::dec << len << "\n";
    for (int i = 0; i < len; i++) {
        res[i] = (unsigned char)(a[i] ^ b[i]);
    }

    return res;
}


int main()
{
    strxor x;

    std::string otp1 = "6c73d5240a948c86981bc294814d";
    std::string msg1 = "attack at dawn";
    std::string otp1_str = x.hexstr2str(otp1);
    std::string key = x.xor_str(msg1, otp1_str);
    std::cout << "msg1: " << msg1 << "\n";
    std::cout << "otp1: " << otp1 << "\n";
    std::cout << "key: " << x.str2hexstr(key) << "\n";

    std::string msg2 = "attack at dusk";
    std::string otp2 = x.xor_str(msg2, key);
    std::cout << "msg2: " << msg2 << "\n";
    std::cout << "otp2: " << x.str2hexstr(otp2) << "\n";

    return 0;
}
