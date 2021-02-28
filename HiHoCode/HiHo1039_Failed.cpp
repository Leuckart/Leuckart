/**************************************************
	> File Name:   Test.cpp
	> Author:      Leuckart
	> Time:        2017-09-23  03:26
**************************************************/

#include <iostream>
#include <string>

using namespace std;

int Search_Next(std::string in_str, int beg)
{
	int str_len = in_str.length();
	/* It Seems That I Dont Need 'position' */
	int position = beg;
	while ((position < str_len) && (in_str[position] == '#'))
	{
		position++;
	}
	/* Max Of 'position' : str_len */
	return position;
}

int Get_Score(std::string in_str)
{
	//std::cout << in_str << std::endl;
	int str_len = in_str.length();

	if (str_len == 1)
	{
		return 0;
	}

	int delete_flag_all = 1;
	int delete_flag_iter = 1;

	while (delete_flag_all)
	{
		delete_flag_all = 0;
		delete_flag_iter = 0;
		int left = 0;

		while (left < str_len - 1)
		{
			left = Search_Next(in_str, left);
			if (left >= str_len - 1)
			{
				break;
			}

			int right = Search_Next(in_str, left + 1);
			if (right == str_len)
			{
				break;
			}

			while (right < str_len && in_str[left] == in_str[right])
			{
				delete_flag_all = 1;
				delete_flag_iter = 1;
				in_str[right] = '#';
				right++;
			}
			if (right == str_len)
			{
				//break;
			}

			if (delete_flag_iter)
			{
				in_str[left] = '#';
				delete_flag_iter = 0;
				left = right;
			}
			else
			{
				left = right;
			}
			//delete_flag_iter = 0;
		}
	}

	//std::cout << in_str << std::endl;

	int delete_number = 0;
	for (int i = 0; i < str_len; i++)
	{
		if (in_str[i] == '#')
		{
			delete_number++;
		}
	}
	return delete_number;
}

int main(int argc, char *argv[])
{
	int String_Number;
	std::cin >> String_Number;

	std::string input_string;
	std::string new_string;

	while (String_Number > 0)
	{
		String_Number--;
		std::cin >> input_string;
		int string_length = input_string.length();

		int ans = 0;
		int ans_iter;

		for (int string_position = 0; string_position < string_length + 1; string_position++)
		{
			new_string = input_string.substr(0, string_position) + "A" + input_string.substr(string_position, string_length - string_position);
			ans_iter = Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}

			new_string = input_string.substr(0, string_position) + "B" + input_string.substr(string_position, string_length - string_position);
			ans_iter = Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}

			new_string = input_string.substr(0, string_position) + "C" + input_string.substr(string_position, string_length - string_position);
			ans_iter = Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}
		}
		std::cout << ans << std::endl;
	}
}
