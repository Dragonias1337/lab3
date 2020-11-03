

#include <vector>
#include <string>
#include <iostream>


using namespace std;

void main()
{
	int a;//частное из задания 2
	int subtask;
	int task;
	
	cout << "choose task 1-11" << endl;
	cin >> task;
	if (task == 1)
	{
		int size;
		setlocale(LC_ALL, "RUSSIAN");
		cout << "enter array size"<< endl;
			cin >> size;
		double* array = new double[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 1000 + 1;
		}
		cout << "choose subtask 1-3" << endl;
		cin >> subtask;
		if (subtask == 1)
		{
		
	
			
			for (int i = 0; i < size; i++)
			{
				array[i] *= 2;
				cout << array[i] << endl;
			}
		}
		else if (subtask == 2)
		{
			
			
			cout << "enter a" << endl;
			cin >> a;
			for (int i = 0; i < size; i++)
			{
				array[i] -= a;
				cout << array[i] << endl;
			}
		}
		else if (subtask == 3)
		{
			int denom = array[1];
			for (int i = 0; i < size; i++)
			{
				array[i] /= denom;
				cout << array[i];
			}
		}

	}
	if (task == 2)
	{
		int size;
		setlocale(LC_ALL, "RUSSIAN");
		cout << "enter array size"<< endl;
			cin >> size;
		double* array = new double[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 1000 + 1;
		}
		cout << "choose subtask 1-6" << endl;
		cin >> subtask;
		if (subtask == 1)
		{
			int summ = 0;
			for (int i = 0; i < size; i++)
				summ += array[i];
			cout << summ << endl;
		}
		if (subtask == 2)
		{
			double summ = 0;
			for (int i = 0; i < size; i++)
				summ += (array[i] * array[i]);
			cout << summ << endl;
		}
		if (subtask == 3)
		{
			if (size < 6)
			{
				cout << "ARRAY IZ 2 SMOL!!!!!!!" << endl;
			}
			else
			{
				int summ = 0;
				for (int i = 0; i < 6; i++)
					summ += (array[i] * array[i]);
				cout << summ << endl;
			}
		}

		if (subtask == 4)
		{
			cout << "enter k1 & k2" << endl;
			int k1, k2;
			cin >> k1;
			cin >> k2;
			int summ = 0;
			for (int i = k1; i <= k2; i++)
				summ += array[i];
			cout << summ << endl;
		}
		if (subtask == 5)
		{
			int summ = 0;
			for (int i = 0; i < size; i++)
				summ += array[i];
			int ans5 = summ / size;
			cout << ans5 << endl;
		}
		if (subtask == 6)
		{
			int s1 = 0;
			int s2 = 0;
			cout << "enter s1&s2" << endl;
			cin >> s1;
			cin >> s2;
			int summ = 0;
			for (int i = s1; i <= s2; i++)
				summ += array[i];
			cout << summ / (s2 - s1) << endl;
		}
	}

	if (task == 3)
	{
		int array2[23];
		for (int i = 0; i < 20; i++)
		{
			array2[i] = rand() % 1000000 + 1;
			cout << array2[i] << endl;
		}


		for (int i = 0; i < 3; i++)
		{
			array2[20 + i] = array2[i];
			array2[i] = array2[17 + i];
			array2[17 + i] = array2[20 + i];

		}
		for (int i = 0; i < 20; i++)
		{
			array2[i] = rand() % 100 + 1;
			cout << array2[i] << endl;
		}
	}
	if (task == 4)
	{
		cout << "choose subtask 1-2" << endl;
		cin >> subtask;
		if (subtask == 1)
		{
			int SIZE;
			cout << "enter array size" << endl;
			cin >> SIZE;
			vector<int> array4(SIZE);
			for (int i = 0; i < SIZE; i++)
				array4[i] = rand() % 20 - 10;
			for (int i = 0; i < SIZE; i++)
			{
				if (array4[i] < 0)
					array4.erase(array4.begin() + i);
				SIZE--;
				break;
			}
			for (int i = 0; i < SIZE; i++)
			{
				cout << array4[i] << ' ';
			}
		}
		if (subtask == 2)
		{
			int SIZE;
			cout << "enter array size" << endl;
			cin >> SIZE;
			vector<int> array4(SIZE);
			for (int i = 0; i < SIZE; i++)
				array4[i] = rand() % 20 - 10;
			for (int i = SIZE - 1; i >= 0; i--)
			{
				if (array4[i] % 2 == 0)
					array4.erase(array4.begin() + i);
				SIZE--;
				break;
			}
			for (int i = 0; i < SIZE; i++)
			{
				cout << array4[i] << ' ';
			}
		}
	}
	if (task == 5)
	{
		string city;
		cout << "enter cityname" << endl;
		cin >> city;
		if (city.size() % 2 == 0)
			cout << "cityname's length is even" << endl;
		else cout << "cityname's length is odd" << endl;
	}

	if (task == 6)
	{

		string surname1;
		string surname2;
		cout << "enter 1st surname" << endl;
		cin >> surname1;
		cout << "enter 2st surname" << endl;
		cin >> surname2;
		if (surname1.size() >= surname2.size())
		{
			cout << "return true" << endl;
		}
	}
	if (task == 7)
	{
		string the_longest;
		string the_shortest;
		string name1;
		string name2;
		string name3;
		cout << "enter 3 city names" << endl;
		cin >> name1;
		cin >> name2;
		cin >> name3;
		the_longest = name1;
		if (the_longest > name2)
			the_longest = name2;
		if (the_longest > name3)
			the_longest = name3;
		the_shortest = name1;
		if (the_shortest < name2)
			the_shortest = name2;
		if (the_shortest < name3)
			the_shortest = name3;
		cout << the_longest << endl << the_shortest << endl;
	}
	if (task == 8)
	{
		int n, m;
		string word;
		cout << "enter the word" << endl;
		cin >> word;
		cout << "m & n" << endl;
		cin >> n >> m;
		for (m; m < n - 1; m++)
		{
			cout << word[m - 1];
		}

	}
	if (task == 9)
	{
		string word;
		cout << "enter the word" << endl;
		cin >> word;
		string st=word;
		int n = word.size();
		string st(n, '*');
		word = st + word + st;
		cout << word << endl;
	}
	if (task == 10)
	{
		string sentence;
		float a_percent;
		float a_amount;
		cout << "enter the sentence" << endl;
		cin >> sentence;
		a_amount = 0;
		for (int i = 0; i<sentence.size(); i++)
		{
			if (sentence[i] == 'a')
				a_amount++;
		}
		a_percent = a_amount / sentence.size()* 100;
		cout << a_percent << "%"<< endl;
	}
	if (task == 11)
	{
		unsigned long pos =-1;
		string st = "can you can a can as a canner can can a can";
		string new_word;
		cout << "enter new word" << endl;
		cin >> new_word;
		string st1 = new_word, t = "can";
		while (st.find(t) != pos)
		{
			st.replace(st.find(t), t.length(), new_word);
		}
		for (int i=0; i<st.length();i++)
		cout << st[i];
	}


	system("pause");
}
