#include "BezierCurve.h"
#include "ros/ros.h"
#include "std_msgs/String.h" 

/**
 * 阶乘实现
 * @param n
 * @return
 */
double factorial(int n) {
    if(n<=1)return 1;
    return factorial(n-1)*n;
}

/**
 * 贝塞尔公式
 * @param Ps
 * @param t
 * @return
 */
Node bezierCommon(vector<Node> Ps, double t) {
    Vector2d rt(0.,0.);
    vector<Vector2d> gt;
    Node p_t;
    ROS_INFO("num:%d",Ps.size());
    if(Ps.size()==1)return Ps[0];

    for(int i=0;i<Ps.size();i++){
        gt.push_back(Vector2d(Ps[i].x_,Ps[i].y_));
    }
    
    int n = Ps.size()-1;
    // int n = 3;

    // for(int i=0;i<Ps.size();i++){
    //     double C_n_i = factorial(n)/ (factorial(i)* factorial(n-i));
    //     p_t =p_t + Ps[i]*(C_n_i*pow((1-t),(n-i))*pow(t,i));
    // }
    for(int i=0;i<Ps.size();i++){
        double C_n_i = factorial(n)/ (factorial(i)* factorial(n-i));
        rt +=  C_n_i*pow((1-t),(n-i))*pow(t,i)*gt[i];
    }
    p_t.x_ = rt[0] ;
    p_t.y_ = rt[1] ;

    return p_t;
}

vector<Node> beziertest(vector<Node>Ps){

    
    vector<Node> NS;
    for(int i=0;i<100;i++){
        Node pos = bezierCommon(Ps,(double)i/100);
        //cout<<pos[0]<<","<<pos[1]<<endl;45
        NS.push_back(pos);
    }
    return NS;
}