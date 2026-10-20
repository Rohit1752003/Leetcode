class Solution {
public:
/*
    void maxHeapify(vector<int>& v, int i, int n) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && v[left] > v[largest])
            largest = left;

        if (right < n && v[right] > v[largest])
            largest = right;

        if (largest != i) {
            swap(v[i], v[largest]);
            maxHeapify(v, largest, n);
        }
    }

    void buildHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            maxHeapify(nums, i, n);
        }
    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();
        buildHeap(nums);

        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);   // move max to end
            maxHeapify(nums, 0, i);   // heapify reduced heap size
        }
    }
    */
    
    int findKthLargest(vector<int>& nums, int k) {
        // heapSort(nums);  // now nums is sorted ascending
        // return nums[nums.size() - k];  // k-th largest
        
    /*    nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
        */
         priority_queue<int> pq(nums.begin(), nums.end());

        while (--k) {
            pq.pop();
        }

        return pq.top();
    }
};
