#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <vector>
using namespace std;
const int MAX_ARRAY_SIZE = INT32_MAX >> 5;

class ArrayManager
{
private:
	const int cores = thread::hardware_concurrency();
	shared_ptr<int> data{ new int[MAX_ARRAY_SIZE] };
	int segment_count;
	vector<std::thread> threads;
	
	/*auto maxFinderWorker(const int* data, const int start, const int end) -> int
	{
		auto max = data[start];
		for (auto i = start + 1; i < end; i++)
			max = data[i] > max ? data[i] : max;
		return max;
	}*/
	
	auto worker(const int start, const int end) noexcept -> void 
	{
		std::random_device rn;
		std::mt19937 engine{ rn() };
		std::uniform_int_distribution<int> dice{ INT32_MIN, INT32_MAX };
		
		for (auto  i = start; i < end; i++)
			data.get()[i] = dice(engine);
	}

	auto time_measure_decorator(const function<void(void)> function_to_decorate) const noexcept -> void
	{
		const auto start = std::chrono::system_clock::now();

		function_to_decorate();
		
		const auto ende = std::chrono::system_clock::now();
		const std::chrono::duration<double> dur = ende - start;
		std::cout << "Duration with : " << segment_count << " Segments was " << dur.count() << " Seconds." << std::endl;

	}


	

	auto calculate_and_run_threads() noexcept -> void
	{
		try
		{
			calculate_and_run_threads_impl();
		}
		catch (const std::exception&)
		{
			std::cout << "\n****** Upps *****\n" << std::endl;
		}
	}
	void calculate_and_run_threads_impl()
	{
		run_threads();
		await_termination();
	}

	auto calculate_and_run_single_worker(const int segment)  -> void
	{
		auto segment_size = MAX_ARRAY_SIZE / segment_count;
		threads.emplace_back(std::thread{ [this, segment, segment_size] {worker(segment * segment_size, (segment + 1) * segment_size); } });
	}

	auto run_threads() -> void
	{
			for (auto actual_segment = 0; actual_segment < segment_count; actual_segment++)
			{
				calculate_and_run_single_worker(actual_segment);
			}
		
	}

	void await_termination() 
	{
		for (auto& t : threads)
		{
			if(t.joinable())
				t.join();
		}
	}

public:
	ArrayManager() = default;

	auto get_data() const noexcept -> shared_ptr<int>
	{
		return data;
	}

	virtual auto fill_array_parallel_with_random_numbers() noexcept -> void
	{

		for (segment_count = 1; segment_count <= cores + 1; segment_count++)
		{
			time_measure_decorator([this]() {calculate_and_run_threads(); });
		}
	}
	virtual auto find_max_value_parallel() noexcept -> void
	{

		for (segment_count = 1; segment_count <= cores + 1; segment_count++)
		{
			time_measure_decorator([this]() {calculate_and_run_threads(); });
		}
	}

	
};

