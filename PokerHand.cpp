#include <iostream>
#include <string>

const short fiveCards = 5;

using namespace std;

void convert_array(string value_str[], short value[]);
short convert_value(string value);
bool same_suit(string suit[]);
bool straight(short value[]);
bool royal(short value[]);
void occurences(short value[], short num_of_combos[], short& size);
void check_cards(bool& four, bool& three, bool& pair, bool& two_pair, short num_of_combos[], short& size);

int main()
{
		string card[fiveCards];
		short value[fiveCards];
		string value_str[fiveCards];
		string suit[fiveCards];
		for (short i = 0; i < fiveCards; i++)
		{
			cout << "Enter a card #" << i + 1 << " in suit/value format: ";
			getline(cin, card[i]);
			suit[i] = card[i].substr(0, 1);
			value_str[i] = card[i].substr(1, card[i].length() - 1);
		}
		convert_array(value_str, value);

		short num_of_combos[fiveCards], size(0);
		occurences(value, num_of_combos, size);

		bool one_pair(false), two_pair(false), three(false), four(false);

		check_cards(four, three, one_pair, two_pair, num_of_combos, size);
		bool is_straight = straight(value);
		bool is_same_suit = same_suit(suit);
		bool is_royal = royal(value);
		if (is_same_suit && is_straight && is_royal)
		{
			cout << "Royal Flush\n\n";
		}
		else if (is_same_suit && is_straight)
		{
			cout << "Straight Flush\n\n";
		}
		else if (is_straight)
		{
			cout << "Straight\n\n";
		}
		else if (four)
		{
			cout << "Four of a kind\n\n";
		}
		else if (three && one_pair)
		{
			cout << "Full House\n\n";
		}
		else if (is_same_suit)
		{
			cout << "Flush\n\n";
		}
		else if (two_pair)
		{
			cout << "Two pairs\n\n";
		}
		else if (one_pair)
		{
			cout << "Pair\n\n";
		}
		else
		{
			cout << "Nothing\n\n";
		}

	cout << "End of the program.\n\n";
	system("pause");

	return 0;
}

void convert_array(string value_str[], short value[])
{
	for (short i = 0; i < fiveCards; i++)
	{
		value[i] = convert_value(value_str[i]);
	}
	return;
}

short convert_value(string value)
{
	if (value == "2")
	{
		return 2;
	}
	else if (value == "3")
	{
		return 3;
	}
	else if (value == "4")
	{
		return 4;
	}
	else if (value == "5")
	{
		return 5;
	}
	else if (value == "6")
	{
		return 6;
	}
	else if (value == "7")
	{
		return 7;
	}
	else if (value == "8")
	{
		return 8;
	}
	else if (value == "9")
	{
		return 9;
	}
	else if (value == "10")
	{
		return 10;
	}
	else if ((value == "q") || (value == "Q"))
	{
		return 11;
	}
	else if ((value == "j") || (value == "J"))
	{
		return 12;
	}
	else if ((value == "k") || (value == "K"))
	{
		return 13;
	}
	else if ((value == "a") || (value == "A"))
	{
		return 14;
	}
}

bool same_suit(string suit[])
{
	string test = suit[0];
	for (short i = 1; i < fiveCards; i++)
	{
		if (test != suit[i])
		{
			return false;
		}
	}
	return true;
}

bool royal(short value[])
{
	int royal = 0;
	for (int i = 0; i < fiveCards; i++) {
		royal = royal + value[i];
	}
	if (royal == 60) {
		return true;
	}
	else {
		return false;
	}
}

bool straight(short value[])
{
	short min = value[0];
	for (short i = 1; i < fiveCards; i++)
	{
		if (value[i] < min)
		{
			min = value[i];
		}
	}

	short next = min + 1;
	short i = 0;
	while (i < fiveCards)
	{
		if (value[i] == next)
		{
			next++;
			i = 0;
		}
		else
		{
			i++;
		}
	}

	if (next == (min + 5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void occurences(short value[], short num_of_combos[], short& size)
{
	short k = 0;
	short count;
	bool encountered[] = { false, false, false, false, false };
	for (short i = 0; i < fiveCards; i++)
	{
		if (!encountered[i])
		{
			size++;
			encountered[i] = true;
			count = 1;
			for (short j = 1; j < fiveCards; j++)
			{
				if ((!encountered[j]) && (value[i] == value[j]))
				{
					encountered[j] = true;
					count++;
				}
			}
			num_of_combos[k] = count;
			k++;
		}
	}
	return;
}

void check_cards(bool& four, bool& three, bool& pair, bool& two_pair, short num_of_combos[], short& size)
{
	short pairs(0), threes(0), fours(0);
	for (short i = 0; i < size; i++)
	{
		if (num_of_combos[i] == 2)
		{
			pairs++;
		}
		if (num_of_combos[i] == 3)
		{
			three = true;
		}
		if (num_of_combos[i] == 4)
		{
			four = true;
		}
	}

	if (pairs == 2)
	{
		two_pair = true;
	}
	else if (pairs == 1)
	{
		pair = true;
	}

	return;
}
