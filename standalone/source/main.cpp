#include <concurrency/Scheduler.h>
#include <concurrency/concurrency.h>
#include <concurrency/version.h>

//#include <cxxopts.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

// auto main(int argc, char** argv) -> int {
auto main() -> int {
  //  const std::unordered_map<std::string, concurrency::LanguageCode> languages{
  //      {"en", concurrency::LanguageCode::EN},
  //      {"de", concurrency::LanguageCode::DE},
  //      {"es", concurrency::LanguageCode::ES},
  //      {"fr", concurrency::LanguageCode::FR},
  //  };

  //  cxxopts::Options options(*argv, "A program to welcome the world!");

  //  std::string language;
  //  std::string name;

  // clang-format off
//  options.add_options()
//    ("h,help", "Show help")
//    ("v,version", "Print the current version number")
//    ("n,name", "Name to greet", cxxopts::value(name)->default_value("World"))
//    ("l,lang", "Language code to use", cxxopts::value(language)->default_value("en"))
//  ;
  // clang-format on

  //  auto result = options.parse(argc, argv);

  //  if (result["help"].as<bool>()) {
  //    std::cout << options.help() << std::endl;
  //    return 0;
  //  }

  //  if (result["version"].as<bool>()) {
  //    std::cout << "Concurrency, version " << CONCURRENCY_VERSION << std::endl;
  //    return 0;
  //  }

  //  auto langIt = languages.find(language);
  //  if (langIt == languages.end()) {
  //    std::cerr << "unknown language code: " << language << std::endl;
  //    return 1;
  //  }

  //  concurrency::Concurrency concurrency(name);
  //  std::cout << concurrency.greet(langIt->second) << std::endl;

  std::cout << "Threads: " << concurrency::Scheduler::ConcurrencyLevel() << std::endl;

  return 0;
}
