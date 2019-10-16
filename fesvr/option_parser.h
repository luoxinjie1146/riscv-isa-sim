// See LICENSE for license details.

#ifndef _OPTION_PARSER_H
#define _OPTION_PARSER_H

#include <vector>
#include <functional>

//lxj// 命令行选项语法分析器
class option_parser_t
{
 public:
  option_parser_t() : helpmsg(0) {} //lxj// 初始化构造函数
  void help(void (*helpm)(void)) { helpmsg = helpm; } //lxj// 绑定帮助信息打印函数
  void option(char c, const char* s, int arg, std::function<void(const char*)> action); //lxj// 绑定合法的命令行选项
  const char* const* parse(const char* const* argv0); //lxj// 提取命令行选项及参数，运行命令行选项的行为函数，返回余下的字符串
 private:
  //lxj// 命令行选项及行为
  struct option_t
  {
    char chr; //lxj// 单字符选项
    const char* str; //lxj// 字符串选项
    int arg; //lxj// 命令行选项是否需要参数
    std::function<void(const char*)> func; //lxj// 命令行选项的行为
    option_t(char chr, const char* str, int arg, std::function<void(const char*)> func)
     : chr(chr), str(str), arg(arg), func(func) {}
  };
  std::vector<option_t> opts; // 所有合法的命令行选项
  void (*helpmsg)(void); //lxj// 帮助信息打印函数
  void error(const char* msg, const char* argv0, const char* arg); //lxj// 打印错误信息的帮助函数
};

#endif
