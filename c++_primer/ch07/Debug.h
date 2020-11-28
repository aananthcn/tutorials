#ifndef DEBUG_H
#define DEBUG_H

class Debug {
public:
    constexpr Debug(bool b) : hw(b), io(b), others(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), others(o) {}

    constexpr bool any() { return hw || io || others; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_others(bool b) { others = b; }

private:
    bool hw;
    bool io;
    bool others;
};

#endif