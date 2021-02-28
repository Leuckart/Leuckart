/**************************************************
	> File Name:  Leet_297_SerializeAndDeserializeBinaryTree.cpp
	> Author:     Leuckart
	> Time:       2020-03-19 02:04
**************************************************/

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
	string serialize(TreeNode *root)
	{
		string result;
		serializeCore(root, result);
		return result;
	}

	TreeNode *deserialize(string data)
	{
		int pos = 0;
		return deserializeCore(data, pos);
	}

private:
	void serializeCore(TreeNode *root, string &result)
	{
		if (root == nullptr)
			result += "# ";
		else
		{
			result += to_string(root->val) + " ";
			serializeCore(root->left, result);
			serializeCore(root->right, result);
		}
	}

	TreeNode *deserializeCore(const string &data, int &pos)
	{
		int new_pos = data.find(' ', pos);
		string item = data.substr(pos, new_pos - pos);
		pos = new_pos + 1;

		if (item == "#")
			return nullptr;

		TreeNode *root = new TreeNode(stoi(item));
		root->left = deserializeCore(data, pos);
		root->right = deserializeCore(data, pos);
		return root;
	}
};

int main(int argc, char *argv[])
{
	Codec cod;
	return 0;
}
