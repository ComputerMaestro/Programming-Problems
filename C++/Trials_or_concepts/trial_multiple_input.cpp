#include <iostream>
#include <vector>


using namespace std;
int main()
{
    int T, N;
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> N;
        int curr_n, max = 0;
        vector<int> collected(2*N-1, 0);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                scanf("%d", &curr_n);
                collected[N-1-i+j] += curr_n;
            }
        }
        for(int i : collected)
        {
            if(max < i)
            {
                max = i;
            }
        }
        cout << "Case #" << t << ": " << max << endl;
    }
    
    return 0;
}