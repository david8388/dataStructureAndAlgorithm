/**
 * https://leetcode.com/problems/container-with-most-water/
 * 
 * 
*/

#define MIN(a, b) (a > b ? b : a)

int maxArea(int *height, int heightSize)
{
    // Solution 1(Brute force)
    /*int maxArea = 0;
    
    for (int index = 0; index < heightSize; index ++) {
         for (int nextIndex = index + 1; nextIndex < heightSize; nextIndex ++) {    
             int min = MIN(height[index], height[nextIndex]);
             int area = min* (nextIndex-index);
             maxArea = maxArea > area ? maxArea: area;
         }
    }*/

    // Solution 2
    int maxArea = 0;
    int front = 0;
    int rear = heightSize - 1;
    while (front != rear)
    {
        int h = MIN(height[front], height[rear]);
        int width = rear - front;
        int area = h * width;
        maxArea = maxArea > area ? maxArea : area;
        if (h == height[front])
        {
            front++;
        }
        else
        {
            rear--;
        }
    }
    return maxArea;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int length = sizeof(height) / sizeof(height[0]);
    // printf("This is a test!\n");
    int area = maxArea(height, length);
    printf("Max area is %d", area);
    return 0;
}
