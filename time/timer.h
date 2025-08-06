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
	* Ĭ�Ϲ��캯��
	*/
	timer();

	/*
	* ���ι��캯��
	* 
	* @param t ʱ���ַ��� "YYYYMMDDHH"
	*/
	timer(std::string& t);

	/*
	* ����С�������
	* 
	* @param a ��һ��ʱ�����
	* 
	* @return true ��ǰ����ʱ��С�ڶ���aʱ��
	*/
	bool operator<(timer& a);

	/*
	* ���ؼ��������
	* 
	* @param a ��һ��ʱ�����
	* 
	* @return ��������ʱ���������Сʱ��
	*/
	timer operator-(timer& a);

	/*
	* ��ȡϵͳ��ǰʱ��
	* 
	* @return ����ʱ���ַ��� "YYYYMMDDHH"
	*/
	std::string get_system_time();

	/*
	* ��ȡʱ���ַ���
	* 
	* @return ����ʱ���ַ��� "YYYYMMDDHH"
	*/
	std::string get_time();

	/*
	* ͳ�Ƴ�������ʱ��
	* �����ӡ�ڿ���̨
	*/
	void program_run_time_count();

	/*
	* ����ʱ��
	* 
	* @param t ʱ���ַ��� "YYYYMMDDHH"
	*/
	void set_time(std::string& t);

	/*
	* ����ʱ��
	* 
	* @param y ��
	* @param m ��
	* @param d ��
	* @param h ʱ
	*/
	void set_time(int y, int m, int d, int h);

	/*
	* �Ϸ��Լ��
	* 
	* @return true �Ϸ� false ���Ϸ�
	*/
	bool is_legal();

	~timer();

private:
	int year, month, day, hour;
	bool counting_time;

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};