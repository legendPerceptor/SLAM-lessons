#include <iostream>
#include <vector>
#include <algorithm>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv) {
    Quaterniond q1(0.35, 0.2, 0.3, 0.1), q2(-0.5, 0.4, -0.1, 0.2);
    q1.normalize();
    q2.normalize();
    Vector3d t1(0.3, 0.1, 0.1), t2(-0.1, 0.5, 0.3);
    Vector3d p_R1(0.5, 0, 0.2);
    // q1 * p_world_q *q1.inverse() + t1 = p_R1
    // T1w * p_world = pR1
    // T2w * p_world = pR2
    Isometry3d T1w(q1), T2w(q2);
    T1w.pretranslate(t1);
    T2w.pretranslate(t2);
    Vector3d p2 = T2w * T1w.inverse() * p_R1;
    cout << "p2: " << p2.transpose() << endl;
    cout << "p_world Euclidean: " << (T1w.inverse() * p_R1).transpose() << endl;
    Vector4d tmp;
    tmp << (p_R1 - t1), 0;
    cout << "tmp: " << tmp.transpose() << endl;
    Quaterniond p_R1_q(tmp), test_q(0, 0.2, -0.1, 0.1);
    // cout << "test_q: " << test_q.coeffs() << endl;
    // cout << "p_R1_q: " << p_R1_q.coeffs() << endl;
    auto p_world_q = (q1.inverse() * p_R1_q * q1).coeffs();
    tmp << p_world_q.head(3), 0;
    // When using a vector to initialize Quaterniond, it is x,y,z,w.
    // The constructor of Quaterniond is w, x, y, z
    auto p2_q = q2 * Quaterniond(tmp) * q2.inverse();
    auto p2_result = p2_q.coeffs().head(3) + t2;
    cout << "p2_q: " << p2_q.coeffs().transpose() << endl;
    cout << "p2: " << p2_result.transpose() << endl;
    return 0;
}