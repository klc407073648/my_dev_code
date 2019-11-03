#include<queue>
#include<iostream>

using namespace std;
class Project
{
public:
	int cost;
	int profit;
	Project(int c,int p)
	{
		cost = c;
		profit = p;
	}
	bool cmp_by_cost(Project &t1, Project t2);

};
struct cmp_by_cost
{
    bool operator()(Project &t1, Project t2)
   {
	return t1.cost > t2.cost;
    }

};

struct cmp_by_profit
{
	bool operator()(Project &t1, Project t2)
	{
		return t1.cost < t2.cost;
	}

};
void makeMaxMoney()
{ 
	priority_queue<Project, vector<Project>, cmp_by_cost>  minCost;
	priority_queue<Project, vector<Project>, cmp_by_profit>  maxProfit;
	int w = 100, k = 3;
	
    minCost.push(Project(120, 50));
	minCost.push(Project(150, 60));
	minCost.push(Project(50, 20));
	minCost.push(Project(80, 30));
	minCost.push(Project(200, 70));

	while (k > 0 && !minCost.empty())
	{
		while (minCost.top().cost <=w)
		{
			maxProfit.push(minCost.top());
			minCost.pop();
		}
        
		if (!maxProfit.empty())
		{
			w = w + maxProfit.top().profit;
			maxProfit.pop();
			k--;
		}
		else
		{
			break;
		}

	}
	cout << w;


}