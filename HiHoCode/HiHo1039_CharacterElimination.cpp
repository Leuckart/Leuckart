/**************************************************
	> File Name:  HiHo1039_CharacterElimination.cpp
	> Author:     Leuckart
	> Time:       2019-03-06 23:45
**************************************************/

#include <iostream>
#include <string>

int Get_Score(std::string in_str)
{
	//cout << in_str << endl;
	int str_len = in_str.length();

	int left, right;
	int change_flag = 1;

	while (change_flag && in_str.length() > 0)
	{
		change_flag = 0;
		left = 0;

		while (left < in_str.length() - 1)
		{
			right = in_str.find_first_not_of(in_str[left], left);
			if (right == -1)
			{
				in_str = in_str.substr(0, left);
				break;
			}
			if (right == left + 1)
			{
				left++;
			}
			else
			{
				in_str = in_str.substr(0, left) + in_str.substr(right);
				change_flag = 1;
			}
		}
	}
	//cout << in_str << endl;
	return in_str.length();
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
			ans_iter = new_string.length() - Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}

			new_string = input_string.substr(0, string_position) + "B" + input_string.substr(string_position, string_length - string_position);
			ans_iter = new_string.length() - Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}

			new_string = input_string.substr(0, string_position) + "C" + input_string.substr(string_position, string_length - string_position);
			ans_iter = new_string.length() - Get_Score(new_string);
			if (ans_iter > ans)
			{
				ans = ans_iter;
			}
		}
		std::cout << ans << std::endl;
	}
}
