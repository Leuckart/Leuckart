/**************************************************
	> File Name:  HiHo1014_TrieTree.cpp
	> Author:     Leuckart
	> Time:       2017-07-22 16:08
**************************************************/

#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

struct TrieNode
{
	int successor_number;
	TrieNode *successor[ALPHABET_SIZE];

	TrieNode()
	{
		successor_number = 0;
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			successor[i] = NULL;
		}
	}
};

int main(int argc, char *argv[])
{
	int Directory_Size;
	std::cin >> Directory_Size;

	TrieNode *Root = new TrieNode;
	TrieNode *current_node;
	std::string input_word;

	while (Directory_Size > 0)
	{
		Directory_Size--;
		std::cin >> input_word;

		int input_word_length = input_word.length();
		current_node = Root;

		for (int word_position = 0; word_position < input_word_length; word_position++)
		{
			current_node->successor_number++;
			if (current_node->successor[input_word[word_position] - 'a'] == NULL)
			{
				current_node->successor[input_word[word_position] - 'a'] = new TrieNode;
			}
			current_node = current_node->successor[input_word[word_position] - 'a'];
		}
		current_node->successor_number++;
	}

	int Request_Number;
	std::cin >> Request_Number;

	while (Request_Number > 0)
	{
		Request_Number--;
		std::cin >> input_word;

		int input_word_length = input_word.length();
		current_node = Root;

		for (int word_position = 0; (word_position < input_word_length) && (current_node != NULL); word_position++)
		{
			current_node = current_node->successor[input_word[word_position] - 'a'];
		}

		if (current_node == NULL)
		{
			std::cout << "0" << std::endl;
		}
		else
		{
			std::cout << current_node->successor_number << std::endl;
		}
	}
}
