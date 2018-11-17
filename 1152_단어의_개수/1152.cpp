#include <iostream>
using namespace std;


int main() {
	char a=0,flag=0;
	int c = 0;
	while (a = getchar()) {
		if (a == ' ')
			continue;
		else if (a == '\n' || a == EOF || a == '\0') {
			flag = 1;
			c = -1;
			break;
		}
		else
			break;
	}
	if(flag == 0)
		while (a=getchar()) {
			if (a == '\n' || a == EOF || a == '\0')
				break;
			if (a == ' ')
				if ((a = getchar()) == ' ' || a == '\0' || a == '\n' || a == EOF)
					break;
				else
					c++;
		}

	std::cout << c+1;
	return 0;
}