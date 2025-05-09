#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Rectangle
{
    int width;
    int height;
    int area;
    float ratio;

    Rectangle(int W, int H) : width(W), height(H)
    {
        area = width * height;
        ratio = min((float)width / height, (float)height / width);
    }
};

bool compare(const Rectangle &a, const Rectangle &b)
{
    if(a.area != b.area)
        return a.area < b.area;
    if(a.ratio != b.ratio)
        return a.ratio > b.ratio;
    return a.width < b.width;
}

int main() {
    int N, W, H;
    cin >> N;
    vector<Rectangle> rectangles;
    for(int i = 0; i < N; i++)
    {
        cin >> W >> H;
        rectangles.emplace_back(W, H);
    }

    sort(rectangles.begin(), rectangles.end(), compare);

    for(auto rectangle : rectangles)
    {
        cout << rectangle.width << " " << rectangle.height << " ";
    }
    cout << endl;
}
// 64 位输出请用 printf("%lld")