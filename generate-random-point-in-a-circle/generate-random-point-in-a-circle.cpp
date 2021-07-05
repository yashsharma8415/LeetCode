class Solution {
public:
    double r, xc, yc;
    
    Solution(double radius, double x_center, double y_center) 
    {
        r = radius;
        xc = x_center;
        yc = y_center;
        srand(time(NULL));
    }
    
    vector<double> randPoint() 
    {
        double angle = (rand() % 360) * 0.0174533;  
        double dist = sqrt((double)rand()/RAND_MAX) * r;
        
        double x = xc + dist * cos(angle);
        double y = yc + dist * sin(angle);
        
        vector<double> ans = {x, y};
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */