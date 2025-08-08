#include"timer.h"

timer::timer()
{
	counting_time = false;
	std::string time;

	// 获取当前系统时间
	auto now = std::chrono::system_clock::now();

	// 转换为 time_t（方便格式化）
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间
	std::tm* local_tm = std::localtime(&now_time_t);

	std::ostringstream oss;
	oss << std::put_time(local_tm, "%Y %m %d %H");
	time = oss.str();

	std::stringstream ss(time);
	ss >> year >> month >> day >> hour;
}

timer::timer(std::string& t,bool& f)
{
	for (int i = 0; i < t.size(); i++)
	{
		if (!(t[i] <= '9' && t[i] >= '0'))
		{
			f = false;
			return;
		}
	}

	counting_time = false;
	if (t.find(' ') != std::string::npos)
	{
		std::stringstream ss(t);
		ss >> year >> month >> day >> hour;
	}
	else
	{
		year = stoi(t.substr(0, 4));
		month = stoi(t.substr(4, 2));
		day = stoi(t.substr(6, 2));
		hour = stoi(t.substr(8, 2));
	}
	f = true;
}

bool timer::operator<(timer& a)
{
	if (year != a.year)
		return year < a.year;
	if (month != a.month)
		return month < a.month;
	if (day != a.day)
		return day < a.day;
	return hour < a.hour;
}

timer timer::operator-(timer& a)
{
	timer result;

	result.set_time(year - a.year, month - a.month,
		day - a.day, hour - a.hour);

	return result;
}

std::string timer::get_system_time()
{
	std::string time;

	// 获取当前系统时间
	auto now = std::chrono::system_clock::now();

	// 转换为 time_t（方便格式化）
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间
	std::tm* local_tm = std::localtime(&now_time_t);

	std::ostringstream oss;
	oss << std::put_time(local_tm, "%Y %m %d %H");
	time = oss.str();

	std::stringstream ss(time);
	ss >> year >> month >> day >> hour;

	return time;
}

std::string timer::get_time()
{
	/*std::ostringstream oss;
	oss << std::setw(4) << std::setfill('0') << year <<'/b'
		<< std::setw(2) << std::setfill('0') << month << '/b'
		<< std::setw(2) << std::setfill('0') << day << '/b'
		<< std::setw(2) << std::setfill('0') << hour;
	return oss.str();*/

	std::string s;
	if (year / 1000 >= 10 || year / 1000 == 0)
		return "0000000000"; // 年份不合法
	else
		s += std::to_string(year);
	if (month < 10) s += '0';
	s += std::to_string(month);
	if (day < 10) s += '0';
	s += std::to_string(day);
	if (hour < 10) s += '0';
	s += std::to_string(hour);

	std::cout << "当前时间：" << s << std::endl;

	return s;
}

void timer::program_run_time_count()
{
	counting_time = true;
	start = std::chrono::high_resolution_clock::now();  // 开始计时
}

void timer::set_time(std::string& t)
{
	std::stringstream ss(t);
	ss >> year >> month >> day >> hour;
}

void timer::set_time(int y, int m, int d, int h)
{
	year = y;
	month = m;
	day = d;
	hour = h;
}

bool timer::is_legal()
{
	return year * 365 * 24 + month * 30 * 24 + day * 24 + hour >= 0;

	//return year >= 0 && month >= 0 && day >= 0 && hour >= 0;
}

timer::~timer()
{
	if (counting_time) 
	{
		auto end = std::chrono::high_resolution_clock::now();    // 结束计时

		// 计算耗时，单位毫秒（ms）
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "\n耗时：" << duration.count() << " 毫秒" << std::endl;
	}
}

int timer::days_in_month(int year, int month)
{
	static const int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2)
	{
		// 闰年判断
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
	}
	return days[month - 1];
}

timer timer::operator+(int a)
{
	timer result = *this;

	result.hour += a;

	while (result.hour >= 24)
	{
		result.hour -= 24;
		result.day += 1;

		int days_this_month = days_in_month(result.year, result.month);
		if (result.day > days_this_month)
		{
			result.day = 1;
			result.month += 1;
			if (result.month > 12)
			{
				result.month = 1;
				result.year += 1;
			}
		}
	}
	return result;

}