#include <vector>
#include <unordered_map>
#define MAX_N 5000
using namespace std;
struct distST
{
	int dist;
	int sCity;
	int eCity;
};
vector < pair<int, int>> _dist[MAX_N]; // ecity, dist
unordered_map<int, distST> _manager;
int _N, _capital;

void init(int N, int mCapital, int k, int mID[], int sCity[], int eCity[], int mDistance[])
{
	for (int i = 0; i < MAX_N; i++)
	{
		_dist[i].clear();
	}
	_manager.clear();

	_N = N;
	_capital = mCapital;
	
	for (int i = 0; i < k; i++)
	{
		add(mID[i], sCity[i], eCity[i], mDistance[i]);
	}
}

void add(int mId, int sCity, int eCity, int mDistance)
{
	distST temp;
	temp.dist = mDistance;
	temp.sCity = sCity;
	temp.eCity = eCity;
	_manager[mId] = temp;
	_dist[sCity].push_back(make_pair(eCity, mDistance));
}

void remove(int mId)
{
	distST temp;
	temp = _manager[mId];
	_manager.erase(mId);

	for (int i = 0; i < _dist[temp.sCity].size(); i++)
	{
		if ((_dist[temp.sCity][i].first = temp.eCity) && (_dist[temp.sCity][i].second = temp.dist))
		{
			_dist[temp.sCity].erase(_dist[temp.sCity].begin() + i);
		}
	}
}

int calculate(int mCity)
{
	return 0;
}