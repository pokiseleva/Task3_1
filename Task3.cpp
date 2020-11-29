#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Fill(const int& m, const int& n)
{
	vector<int> VectorInt;
	vector<vector<int>> VectorOfVector;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp;
			temp=rand()%10;
			VectorInt.push_back(temp);
		}
		VectorOfVector.push_back(VectorInt);
		VectorInt.clear();
	}
	return VectorOfVector;
}

vector<int> FromTableToLine(vector<vector<int>>& VectorOfVector, const int& m, const int& n)
{
	vector<int> VectorInt(n*m);
	for (vector<vector<int>>::iterator it2 = VectorOfVector.begin(); it2 != VectorOfVector.end(); ++it2)
	{
		for (vector<int>::iterator it1 = (*it2).begin(); it1 != (*it2).end(); ++it1)
		{
			vector<int>::iterator it = VectorInt.begin() + (it2 - VectorOfVector.begin()) * n + (it1 - (*it2).begin());
			*it = *it1;
		}
	}
	return VectorInt;
}

vector<vector<int>> FromLineToTable(vector<int>& VectorInt, const int& m, const int& n)
{
	vector<int> tVectorInt(n);
	vector<vector<int>> VectorOfVector(m, tVectorInt);
	int divider;
	for (vector<int>::iterator it = VectorInt.begin(); it != VectorInt.end(); ++it)
	{
		vector<int>::iterator it1;
		vector<vector<int>>::iterator it2;
		divider = it - VectorInt.begin();
		it2 = VectorOfVector.begin() + divider / n;
		it1 = (*it2).begin() + divider % n;
		*it1 = *it;
	}
	return VectorOfVector;
}




int main()
{
	int n, m;
	vector<vector<int>> A;
	vector<int> B;
	vector<vector<int>> C;
	cout << " Enter the size of the array" << endl;
	cin >> m>> n;
	A=Fill(m, n);
	B = FromTableToLine(A, m, n);
	C = FromLineToTable(B, m, n);
	int k = m * n;
	for (int i = 0; i < k; i++)
		cout << B[i] << " ";

	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}