#include <iostream>
#include <string>
#include<vector>
#include<map>
// 之前的方法 思路不是很清晰
// bool isNumeric(const char *str)
// {
//     if(str==nullptr)
//         return false;
//     bool sign = false, decimal = false, hasE = false;
//     for (int i = 0; i < std::strlen(str); i++)
//     {
//         // correction of e
//         if (str[i] == 'e' || str[i] == 'E')
//         {
//             if (i == strlen(str) - 1)
//                 return false; // e must follow with number
//             if (hasE)
//                 return false; // cannot exist more than one e
//             hasE = true;
//         }
//         else if (str[i] == '+' || str[i] == '-')
//         {

//             if (sign && str[i - 1] != 'e' && str[i - 1] != 'E')
//                 return false;

//             if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
//                 return false;
//             sign = true;
//         }
//         else if (str[i] == '.')
//         {

//             if (hasE || decimal)
//                 return false;
//             decimal = true;
//         }
//         else if (str[i] < '0' || str[i] > '9')
//             return false;
//     }
//     return true;
// }

// 有限状态自动机
bool isNumber(std::string s)
{
    std::vector<std::map<char, int> > states;
    std::map<char, int> temp;
        // 0，头部空格状态
		temp[' '] = 0;  // 输入 空格 还是 空格状态0
		temp['s'] = 1;  // 输入 正负号 进入 符号状态1
		temp['d'] = 2;  // 输入 数字 进入 小数点前数字状态2
		temp['.'] = 4;	// 输入 小数点 进入 前为空小数点后首位数字状态4
		states.push_back(temp);
		temp.clear();
		// 1，e之前的符号
		temp['d'] = 2;  // 输入 数字 进入 小数点前的数字状态2
		temp['.'] = 4;  // 输入小数点 进入 前为空小数点后首位数字状态4
		states.push_back(temp);
		temp.clear();
		// 2，小数点前数字状态
		temp['d'] = 2;  // 输入 数字 还是 小数点前的数字状态2
		temp['.'] = 3;  // 输入 小数点 进入 前非空小数点后的数字状态3
		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
		temp[' '] = 8;	// 输入 空格 进入 尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 3，前非空小数点后的数字状态
		temp['d'] = 3;	// 输入 数字 还是 前非空小数点后的数字状态3
		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
		temp[' '] = 8; 	// 输入 空格 进入尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 4，前为空小数点后首位数字状态4
		temp['d'] = 3; 	// 输入 数字 进入 前非空小数点后的数字状态3
		states.push_back(temp);
		temp.clear();
		// 5，指数符号状态5
		temp['s'] = 6;  // 输入 正负号 进入 指数后的符号状态6
		temp['d'] = 7;	// 输入 数字 进入 指数位置数字状态7
		states.push_back(temp);
		temp.clear();
		// 6，指数后的符号状态
		temp['d'] = 7;  // 输入 数字 进入 指数位置数字状态7
		states.push_back(temp);
		temp.clear();
		// 7，指数位置数字状态
		temp['d'] = 7;  // 输入 数字 还是 指数位置数字状态7
		temp[' '] = 8;  // 输入 空格 进入 尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 8，尾部空格状态
		temp[' '] = 8;  // 输入 空格 还是 尾部空格状态8
		states.push_back(temp);
		temp.clear();

        // 初始状态p=0
        int p=0;
        char t;
        for (int i = 0; i < s.length();i++) {
			char c = s[i];
			// 如果是数字，key='d'
			if (c >= '0'&&c <= '9') {
				t = 'd';
			}
			// 如果是正负号，key='s'
			else if (c == '+' || c == '-') {
				t = 's';
			}
			// 如果是其他字符，key='c'，包含了'.' ' ' 其他非法字符
			else {
				t = c;
			}
			std::map<char, int>::iterator it = states[p].find(t);
			// 如果找不到这个状态转移，则非法数字
			if (it == states[p].end()) {
				return false;
			}
			// 如果找到，获取转移后的状态
			p = (int)it->second;
		}
		// 是否在允许结尾的状态2 3 7 8
		return p == 2 || p == 3 || p == 7 || p == 8;

}

void test(std::string str)
{
    if (isNumber(str))
        std::cout << str << "---passed!!" << std::endl;
    else
        std::cout << str << "---failed!!" << std::endl;
}
int main()
{
    test("5e-1");
    test("1.233445");
    test("+67e-9");
    test(".123");
    test("0");
    test("123.");

    test("e-8");
    test("1e-8-78");
    test("2e-5.6");
    test("5e0e");
  

    return 0;
}

void test(const char* str)
{
    if(isNumeric(str))
        std::cout<<str<<"---passed!!"<<std::endl;
    else
        std::cout<<str<<"---failed!!"<<std::endl;
}
int main()
{
    test("5e-1");
    test("1.233445");
    test("+67e-9");
    test(".123");
    test("0");
    test("123.");


    test("e-8");
    test("1e-8-78");
    test("2e-5.6");
    test("5e0e");
    

    return 0;
}