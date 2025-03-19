#include <iostream>

using namespace std;

void calculateNeed(const vector<vector<int>>& max,
                   const vector<vector<int>>& allocation,
                   vector<vector<int>>& need)
{
    int n = max.size();
    int m = max[0].size();

    need.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafe(const vector<int>& available,
            const vector<vector<int>>& allocation,
            const vector<vector<int>>& need,
            vector<int>& safe) {
    int n = allocation.size();
    int m = allocation[0].size();

    vector<int> work = available;
    vector<bool> finish(n, false);

    safe.clear();

    while (true)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool canFinish = true;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = true;
                    safe.push_back(i);
                    found = true;
                }
            }
        }

        if (!found)
        {
            break;
        }
    }

    for (bool f : finish)
    {
        if (!f)
        {
            return false;
        }
    }

    return true;
}

bool request (int process,
              const vector<int>& request,
              vector<int>& available,
              vector<vector<int>>& allocation,
              vector<vector<int>>& need,
              vector<int>& safe)
{
    int n = allocation.size();
    int m = allocation[0].size();

    for (int j = 0; j < m; j++)
    {
        if (request[j] > need[process][j])
        {
            cerr << "Error: Request exceeds maximum need for process." << endl;
            return false;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (request[j] > available[j])
        {
            cerr << "Error: Not enough resources available." << endl;
            return false;
        }
    }

    vector<int> backupAvailable = available;
    vector<vector<int>> backupAllocation = allocation;
    vector<vector<int>> backupNeed = need;


}

int main()
{
  return 0;
}

