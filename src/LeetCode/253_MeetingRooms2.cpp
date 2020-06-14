#include <stack>
#include <iostream>
#include <vector>


static bool cmp1(std::vector<int> a, std::vector<int> b)
{
    return a[0] < b[0];
}
static bool cmp2(std::vector<int> a, std::vector<int> b)
{
    return a[1] < b[1];
}
int minMeetingRooms(std::vector<std::vector<int>> &intervals)
{
    if (intervals.size() == 0 || intervals[0].size() == 0)
        return 0;
    auto intervals_end = std::vector<std::vector<int>>(intervals.begin(), intervals.end());

    // intervals:按照会议开始的时间排序， intervals_end:按照会议结束的时间排序，是两个不一样的二维数组
    sort(intervals.begin(), intervals.end(), cmp1);
    sort(intervals_end.begin(), intervals_end.end(), cmp2);
  
    int L = intervals.size();
    int used_room = 0;
    int s_point = 0, e_point = 0;
    while (s_point < L)
    {
        // 当某个会议开始的时候晚于会议结束的时间，说明可以翻桌子了，使用的房间数--（其实就是不增不减）
        if (intervals[s_point][0] >= intervals_end[e_point][1])
        {
            used_room--;
            e_point++;
        }
        used_room++;
        s_point++;
    }
    return used_room;
}

int main()
{
    std::vector<std::vector<int>> intervals(6, std::vector<int>(2, 0));
    int a[6][2] = {{1, 10}, {2, 7}, {3, 19}, {8, 12}, {10, 20}, {11, 30}};
    for (int i = 0; i < intervals.size(); ++i)
    {
        for (int j = 0; j < intervals[0].size(); ++j)
        {
            intervals[i][j] = a[i][j];
        }
    }
    std::cout << minMeetingRooms(intervals) << std::endl;
    return 0;
}