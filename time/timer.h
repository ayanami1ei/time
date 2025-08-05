#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <ctime>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>

#ifndef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API timer
{
public:
	timer();

	timer(std::string& t);

	bool operator<(timer& a);

	timer operator-(timer& a);

	std::string get_system_time();

	std::string get_time();

	void program_run_time_count();

	void set_time(std::string& t);

	void set_time(int y, int m, int d, int h);

	bool is_legal();

	~timer();

private:
	int year, month, day, hour;
	bool counting_time;

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};