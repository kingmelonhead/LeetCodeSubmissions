class Solution {
    public int maxArea(int[] height) {
        int temp, area = 0, i = 0, j = height.length -1;
        while (i < j){
            temp = j - i;
            if (height[i] < height[j]) temp = temp * height[i++];
            else temp = temp * height[j--];
            if (temp > area) area = temp;
        }
        return area;
    } 
}
