#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>

struct Signal
{
    char state;
    int time;
    Signal(char _state = 'X', int _time = 0);
    std::istream& input(std::istream& st);
    std::ostream& output(std::ostream& st) const; 
};

class Diagram
{
    public:
    static size_t constexpr __n = 5;

    private:
    Signal sections[__n];
    size_t csize;

    public:
    inline size_t size() const { return csize; }
    Diagram();
    Diagram(char const* ascii_symbs);
    Diagram(char _state);
    std::istream& input(std::istream& st);
    std::ostream& output(std::ostream& st) const;
    Diagram add(Diagram const& second) const;
    Diagram& replace(int timestamp, Diagram const& second);
    Diagram& repeat(size_t n);
    Diagram& rshift(int tshift);
    Diagram& lshift(int tshift);
    Diagram& mergeBlocks();
    int get_total_time() const;
    void insertSignalBlock(Signal&& sig);
    void insertSignalBlock(Signal const& sig);
};