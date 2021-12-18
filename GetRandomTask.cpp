#include "GetRandomTask.h"
std::string GetRandomTask(std::vector<std::string>& a) {
	return a[rand() % 5];
}