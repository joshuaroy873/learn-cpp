// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <iomanip>

// using namespace std;

// // Structure to represent a point with integer coordinates
// struct Point {
//     long long x, y;

//     // Comparator for sorting points
//     bool operator<(const Point& other) const {
//         return x < other.x || (x == other.x && y < other.y);
//     }
    
//     // Check for equality
//     bool operator==(const Point& other) const {
//         return x == other.x && y == other.y;
//     }
// };

// // Cross product of vectors OA and OB (where O is the origin)
// // Returns: x1*y2 - x2*y1
// long long cross_product(Point a, Point b) {
//     return a.x * b.y - a.y * b.x;
// }

// // Cross product of vectors AB and AC
// // Returns: (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)
// long long cross_product(Point a, Point b, Point c) {
//     return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
// }

// // Monotone Chain algorithm to compute the Convex Hull
// vector<Point> get_convex_hull(vector<Point>& pts) {
//     int n = pts.size();
//     if (n <= 2) return pts;
    
//     sort(pts.begin(), pts.end());
    
//     vector<Point> hull;
    
//     // Build lower hull
//     for (const auto& p : pts) {
//         while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), p) <= 0) {
//             hull.pop_back();
//         }
//         hull.push_back(p);
//     }
    
//     // Build upper hull
//     int lower_size = hull.size();
//     for (int i = n - 2; i >= 0; i--) {
//         while (hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
//             hull.pop_back();
//         }
//         hull.push_back(pts[i]);
//     }
    
//     // The last point is a duplicate of the first point, remove it
//     hull.pop_back();
    
//     return hull;
// }

// int main() {
//     // Optimize I/O operations
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     double r;
//     if (!(cin >> n >> r)) return 0;

//     vector<Point> pts(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> pts[i].x >> pts[i].y;
//     }

//     // Edge case: convex hull might degenerate if n is small or points are collinear
//     vector<Point> hull = get_convex_hull(pts);

//     bool origin_inside = true;

//     // A polygon with fewer than 3 vertices cannot contain a point strictly inside
//     if (hull.size() < 3) {
//         origin_inside = false;
//     } else {
//         // Check if origin (0,0) is strictly inside the convex hull.
//         // Since the hull is generated in CCW order, the origin must be strictly 
//         // to the left of all edges (cross product > 0).
//         // If cross product <= 0 for any edge, origin is outside or on boundary.
//         for (size_t i = 0; i < hull.size(); ++i) {
//             Point p1 = hull[i];
//             Point p2 = hull[(i + 1) % hull.size()];
//             if (cross_product(p1, p2) <= 0) {
//                 origin_inside = false;
//                 break;
//             }
//         }
//     }

//     double min_dist = 0.0;

//     if (origin_inside) {
//         min_dist = 1e18; // Initialize with a large value
        
//         // Find the minimum distance from origin to any edge of the hull
//         for (size_t i = 0; i < hull.size(); ++i) {
//             Point p1 = hull[i];
//             Point p2 = hull[(i + 1) % hull.size()];
            
//             // The distance from Origin to line passing through p1 and p2
//             // Area of triangle(O, p1, p2) = 0.5 * base * height
//             // height = (2 * Area) / base
//             // 2 * Area = abs(Cross Product of Op1 and Op2)
            
//             long long cp = abs(cross_product(p1, p2));
//             double base = hypot(p1.x - p2.x, p1.y - p2.y);
            
//             double d = cp / base;
//             if (d < min_dist) {
//                 min_dist = d;
//             }
//         }
//     } else {
//         // If origin is not strictly inside, we can cut through the origin (d=0)
//         min_dist = 0.0;
//     }

//     // Calculate the area of the circular segment
//     // Formula: Area = r^2 * acos(d/r) - d * sqrt(r^2 - d^2)
//     // d is min_dist
    
//     long double ans = 0;
//     // Ensure we don't take sqrt of negative or acos > 1 due to precision errors
//     if (min_dist < r) {
//         long double d = min_dist;
//         long double R = r;
//         long double theta = 2.0 * acos(d / R); 
//         // Area of sector - Area of triangle
//         // Sector area = 0.5 * r^2 * theta = r^2 * acos(d/r)
//         // Triangle area = 0.5 * base * height = d * sqrt(r^2 - d^2)
//         ans = R * R * acos(d / R) - d * sqrt(R * R - d * d);
//     } else {
//         // If dist >= r, the segment area is 0 (though problem constraints say dist <= 0.9r)
//         ans = 0.0;
//     }

//     cout << fixed << setprecision(8) << ans << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double r;
    if (!(cin >> n >> r)) return 0;

    vector<pair<double,double>> pts(n);
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        pts[i] = { (double)xi, (double)yi };
    }

    const double PI = acos(-1.0);
    const double TWO_PI = 2.0 * PI;

    auto feasible = [&](double d) -> bool {
        vector<pair<double,double>> intervals;
        intervals.reserve(2 * n);

        for (auto &pt : pts) {
            double x = pt.first, y = pt.second;
            double rho = hypot(x, y);
            if (rho == 0.0 || rho <= d) continue;  // no restriction

            double k = d / rho;
            if (k >= 1.0) continue;               // no restriction
            if (k < 0.0) k = 0.0;

            double alpha = acos(k);               // 0 <= alpha < pi/2
            double theta = atan2(y, x);           // (-pi, pi]
            if (theta < 0) theta += TWO_PI;       // [0, 2pi)

            double L = theta - alpha;
            double R = theta + alpha;

            // Map forbidden interval (L, R) into [0, 2pi), split if needed.
            if (L < 0) {
                intervals.emplace_back(L + TWO_PI, TWO_PI);
                intervals.emplace_back(0.0, R);
            } else if (R >= TWO_PI) {
                intervals.emplace_back(L, TWO_PI);
                intervals.emplace_back(0.0, R - TWO_PI);
            } else {
                intervals.emplace_back(L, R);
            }
        }

        if (intervals.empty()) return true; // no restriction at all

        sort(intervals.begin(), intervals.end());
        const double EPS = 1e-12;

        double curEnd = 0.0;
        // Check for gap before first interval
        if (intervals[0].first > 0.0 + EPS) return true;
        curEnd = intervals[0].second;

        for (size_t i = 1; i < intervals.size(); ++i) {
            double L = intervals[i].first;
            double R = intervals[i].second;
            if (L > curEnd + EPS) {
                // gap between intervals
                return true;
            }
            if (R > curEnd) curEnd = R;
        }

        // Check gap after last interval up to 2π
        if (TWO_PI - curEnd > EPS) return true;

        // Entire circle is covered by forbidden intervals
        return false;
    };

    // Binary search for minimal d in [0, r] such that feasible(d) is true
    double lo = 0.0, hi = r;
    for (int it = 0; it < 60; ++it) {
        double mid = 0.5 * (lo + hi);
        if (feasible(mid)) hi = mid;
        else lo = mid;
    }
    double d = hi;

    // Area of smaller piece (circular segment at distance d)
    double segArea = r * r * acos(d / r) - d * sqrt(max(0.0, r * r - d * d));

    cout << fixed << setprecision(10) << segArea << "\n";
    return 0;
}
