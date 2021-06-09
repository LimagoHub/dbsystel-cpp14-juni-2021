// Tag3_01CondVar.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <random>


std::mutex my_mutex;
std::condition_variable cond_var;
std::vector<long> vec;

std::random_device rn;
std::mt19937 engine{ rn() };
std::uniform_int_distribution<int> dice{ 0, 1000 };

[[ noreturn ]] auto consumer() noexcept -> void
{

	while (true) {
		std::unique_lock<std::mutex> lock(my_mutex);
		if (vec.empty())
			cond_var.wait(lock, [] {return !vec.empty(); });
		const auto value = vec.back();
		vec.pop_back();
		std::cout << "Consumer <- " << value << std::endl;
	}


}

auto producer() noexcept -> void
{
	for (auto i = 0; i < 20; i++) {

		auto value = dice(engine);
		std::cout << "Producer -> " << value << std::endl;
		{
			std::lock_guard<std::mutex> lock(my_mutex);
			vec.push_back(value);
			cond_var.notify_one();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(value));
	}


}

auto main() -> int
{
	std::thread c(consumer);
	std::thread p(producer);

	c.join();

	return 0;
}

