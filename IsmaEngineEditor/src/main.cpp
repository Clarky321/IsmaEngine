#include <memory>
#include <IsmaEngineCore\Application.h>

int main(int arc, char* argv[])
{
	auto app = std::make_unique<Application>();
	app->run();
}