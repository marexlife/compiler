#ifndef MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#define MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#include <exception>
#include <string>

namespace marex::parse::exceptions {
class InvalidTokenException final : public std::exception {
  public:
    explicit InvalidTokenException(std::string &&message);

    const char *what() const noexcept override;

  private:
    std::string message;
};
} // namespace marex::parse::exceptions
#endif // MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H