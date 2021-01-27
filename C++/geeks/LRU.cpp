#include <bits/stdc++.h>

using namespace std;

int search_page(int frames[], int page, int c)
{
    for(int i = 0; i < c; i++)
    {
        if(frames[i] == page)
        {
            return i;
        }
    }
    return -1;
}

bool compare(pair<int, int> & a, pair<int, int> & b)
{
    return a.first > b.first;
}

int LRU(int pages[], int n, int c)
{
    int filled = 0, page_faults = 0;
    int frames[c];
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> frames_heap;
    for(int i = 0; i < n; i++)
    {
        int page_idx = search_page(frames, pages[i], c);
        if(page_idx != -1) continue;
        page_faults++;
        if(filled >= c)
        {
            page_idx = frames_heap.top().second;
            frames_heap.pop();
            frames[page_idx] = pages[i];
            frames_heap.push({i, page_idx});
        }
        else
        {
            frames[filled] = pages[i];
            frames_heap.push({i, filled});
            filled++;
        }
    }
    return page_faults;
}

int main() {
	
	int t; cin >> t;
	
	while(t--)
	{
	    int n, c; cin >> c;
	    int pages[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin >> pages[i];
	    }
	    cin >> c;
	    
	    cout << LRU(pages, n, c) << endl;
	}
	
	return 0;
}