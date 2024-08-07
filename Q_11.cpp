class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int area = INT_MIN;
        while(right > left){
            int temp_area = (right - left) * min(height[right] , height[left]); 
            area = max(area , temp_area);
            if(height[right] > height[left])left++;
            else right--;
        }

        return area;
    }
};
