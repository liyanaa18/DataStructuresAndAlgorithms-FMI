#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

bool compare(const Point& p1, const Point& p2, const Point& tourist) {
    double dist1 = pow(p1.x - tourist.x, 2) + pow(p1.y - tourist.y, 2);
    double dist2 = pow(p2.x - tourist.x, 2) + pow(p2.y - tourist.y, 2);

    if (dist1 == dist2) {
        return p1.x < p2.x;
    }

    return dist1 < dist2;
}

void findKthLandmarks(vector<Point>& landmarks, Point tourist, int k) {
    sort(landmarks.begin(), landmarks.end(), [&](const Point& p1, const Point& p2) {
        return compare(p1, p2, tourist);
    });

    for (int i = 0; i < k; i++) {
        cout << landmarks[i].x << " " << landmarks[i].y << '\n';
    }
}

int main() {
    int x, y, n, k;
    cin >> x >> y >> n >> k;

    Point tourist = {x, y};
    vector<Point> landmarks(n);

    for (int i = 0; i < n; i++) {
        cin >> landmarks[i].x >> landmarks[i].y;
    }

    findKthLandmarks(landmarks, tourist, k);

    return 0;
}
