#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <ctime>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>

#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class  timer
{
public:
	/*
	* 默认构造函数
	*/
	timer();

	/*
	* 含参构造函数
	* 
	* @param t 时间字符串 "YYYYMMDDHH"
	*/
	timer(std::string& t);

	/*
	* 重载小于运算符
	* 
	* @param a 另一个时间对象
	* 
	* @return true 当前对象时间小于对象a时间
	*/
	bool operator<(timer& a);

	/*
	* 重载减法运算符
	* 
	* @param a 另一个时间对象
	* 
	* @return 返回两个时间对象相差的小时数
	*/
	timer operator-(timer& a);

	/*
	* 获取系统当前时间
	* 
	* @return 返回时间字符串 "YYYYMMDDHH"
	*/
	std::string get_system_time();

	/*
	* 获取时间字符串
	* 
	* @return 返回时间字符串 "YYYYMMDDHH"
	*/
	std::string get_time();

	/*
	* 统计程序运行时间
	* 结果打印在控制台
	*/
	void program_run_time_count();

	/*
	* 设置时间
	* 
	* @param t 时间字符串 "YYYYMMDDHH"
	*/
	void set_time(std::string& t);

	/*
	* 设置时间
	* 
	* @param y 年
	* @param m 月
	* @param d 日
	* @param h 时
	*/
	void set_time(int y, int m, int d, int h);

	/*
	* 合法性检测
	* 
	* @return true 合法 false 不合法
	*/
	bool is_legal();

	~timer();

private:
	int year, month, day, hour;
	bool counting_time;

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};