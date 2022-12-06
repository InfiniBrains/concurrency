#include <doctest/doctest.h>
#include <concurrency/concurrency.h>
#include <concurrency/version.h>

#include <string>

TEST_CASE("Concurrency") {
  using namespace concurrency;

  Concurrency concurrency("Tests");

  CHECK(concurrency.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(concurrency.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(concurrency.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(concurrency.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("Concurrency version") {
  static_assert(std::string_view(CONCURRENCY_VERSION) == std::string_view("1.0"));
  CHECK(std::string(CONCURRENCY_VERSION) == std::string("1.0"));
}
