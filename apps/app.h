#ifndef CHAMEMELON_APP
#define CHAMEMELON_APP
#include <string>
class App{
public:
    App(std::string name);
    std::string name;
    void build(std::string include_dir);
};



#endif
