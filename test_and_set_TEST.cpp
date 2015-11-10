
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_number(int x)
{
	while(lock_stream.test_and_set())
	{

	}
	stream << "thread#"<< x <<'\n';
	lock_straem.clear();
}
int main()
{
	std::vector <std::thread> threads;
	for(int i = 1;i<=10;++i)
	{
		threads.push_back(std::thread(append_number,i));
	}
	for(auto & th:threads)
	{
		th.join();
	}
	std::cout << stream.str() << std::endl;
	return 0;
}