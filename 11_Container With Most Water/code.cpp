class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area=0;
        while(i<j)
        {
            int width=j-i;
            int h=height[i]<height[j]?height[i++]:height[j--];
            int curArea=h*width;
            if(curArea>area)
                area=curArea;
        }
        return area;
    }
};