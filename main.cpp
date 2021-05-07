#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &sum, const int &k)
{
    for (int i = 0; i < sum.size(); i++)
        if (sum[i] < k)
            return false;
    return true;
}
void tried(const vector<int> &arr, const int &n, const int &k, int i, long &count, vector<int> &sum)
{
    if (i == arr.size())
    {
        if (check(sum, k))
            count++;
        return;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            sum[j] += arr[i];
            tried(arr, n, k, i + 1, count, sum);
            sum[j] -= arr[i];
        }
    }
}
long splArray(const vector<int> &arr, int n, int k)
{
    long count = 0;
    vector<int> sum(n, 0);
    tried(arr, n, k, 0, count, sum);
    return count;
}
int main()
{
    int numberStudent;
    cin >> numberStudent;
    vector<int> arr(numberStudent);
    for (int i = 0; i < numberStudent; i++)
    {
        cin >> arr[i];
    }
    int n, k;
    cin >> n >> k;
    cout << splArray(arr, n, k);
    return 0;
}