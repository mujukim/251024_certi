#include <vector>
#include <unordered_map>
#define MAX_N 5000
#define INF 10e8
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
void function(int pos, int tdist, int maxdist, int end);
void add(int mId, int sCity, int eCity, int mDistance);

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

int _totaldist, _maxdist;

int calculate(int mCity)
{
	_totaldist = INF;
	_maxdist = -1;
	function(_capital, 0, -1, mCity);
	return _maxdist;
}

void function(int pos, int tdist, int maxdist, int end)
{
	if (pos == end)
	{
		if (_totaldist > tdist)
		{
			_totaldist = tdist;
			_maxdist = maxdist;
		}
		if ((_totaldist == tdist) && (_maxdist > maxdist))
		{
			_maxdist = maxdist;
		}
	}
	for (int i = 0; i < _dist[pos].size(); i++)
	{
		int md = maxdist;
		tdist += _dist[pos].at(i).second;
		if (_dist[pos].at(i).second > maxdist)
		{
			md = _dist[pos].at(i).second;
		}
		function(_dist[pos].at(i).first, tdist, md, end);
	}
}