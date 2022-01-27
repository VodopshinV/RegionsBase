#include<iostream>
#include<map>
#include<string>
#include<tuple>
#include<vector>
using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string>names;
	int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int result = 0;
	map<Region, int> repetition_count;
	for (const Region& region : regions)
	{
		result = max(result, ++repetition_count[region]);
	}
	return result;
}

bool operator<(const Region& lhs, const Region& rhs)
{
	tuple lhs_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	tuple rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_key < rhs_key;
}

int main() {


    //system("pause");
    return 0;
}
