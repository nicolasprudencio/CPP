#include <string>

char	char_converter(const std::string &str) {
	return static_cast<int>(str[0]);
}
