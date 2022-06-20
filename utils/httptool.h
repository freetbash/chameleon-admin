#ifndef FB_HTTP_TOOL
#define FB_HTTP_TOOL
#include <string>
#include <vector>
std::string getipbydomain(std::string domain);
std::vector<std::string> split(std::string s, std::string d);
void progress_bar(long int x,long int total);
#endif