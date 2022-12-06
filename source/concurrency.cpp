#include <fmt/format.h>
#include <concurrency/concurrency.h>

using namespace concurrency;

Concurrency::Concurrency(std::string _name) : name(std::move(_name)) {}

std::string Concurrency::greet(LanguageCode lang) const {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return fmt::format("Hello, {}!", name);
    case LanguageCode::DE:
      return fmt::format("Hallo {}!", name);
    case LanguageCode::ES:
      return fmt::format("¡Hola {}!", name);
    case LanguageCode::FR:
      return fmt::format("Bonjour {}!", name);
  }
}
