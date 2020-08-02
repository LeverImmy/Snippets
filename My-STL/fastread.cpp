namespace io {
    template <typename T> inline void read(T & _x) {
        int f = 0, ch; _x = 0;
        while(!isdigit(ch = getchar())) f |= ch == '-';
        while(isdigit(ch)) _x = _x * 10 + ch - '0', ch = getchar();
        if(f) _x = -_x;
    }
    template <typename T, typename ... Args> inline void read(T &_f, Args& ... args) {
        read(_f), read(args ...);
    }
    inline void _deal(char ch) { putchar(ch); }
    template <typename T> inline void _deal(T _x) {
        if (_x < 0) putchar('-'), _x = -_x;
        if (_x > 9) _deal(_x / 10);
        putchar(_x % 10 + '0');
    }
    inline void write() {}
    template <typename T, typename ... Args> inline void write(T _f, Args ... args) {
        _deal(_f), write(args...);
    }
}

