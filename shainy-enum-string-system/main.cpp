#pragma once
#include <iostream>
#include <string>
/*
 * enum class like 💩
 * no one knows what this does but we write it anyway
 */
enum class Options
{
  SHIT_GIT,   // bruh
  SHIT_Update // update? idk man
};

/*
 * template trait MAGIC 🔥
 * if u don't specialize this shit -> boom at compile time 💣
 * no mercy, only static_assert
 */
template <typename T> struct enumToString
{
  static std::string to(T)
  {
    static_assert(sizeof(T) == 0, "bro u forgot to specialize this trait 💀");
    return {}; // we return this just for compiler to shut up 😤
  }
};

/*
 * now we specialize this trait for our God enum: Options 🙏
 * here is where shit gets real (like fr fr)
 */
template <> struct enumToString<Options>
{
  static std::string to(Options opt)
  {
    switch (opt)
    {
    case Options::SHIT_GIT:
      return "Gitt"; // git but with flavor 😩
    case Options::SHIT_Update:
      return "Update"; // basic
    default:
      return "Unknow"; // not even wrong 🤷‍♂️
    }
  }
};

/*
 * this function is basically a wrapper around the trait
 * it just screams: I HAVE NO CLUE WHAT TYPE THIS IS BUT I TRUST YOU 😤
 */
template <typename T> std::string typenameToString(T value)
{
  return enumToString<T>::to(value);
}

int main()
{
  Options opt = Options::SHIT_GIT;

  std::string str = typenameToString(opt);

  std::cout << str << "\n";
  return 0;
}
