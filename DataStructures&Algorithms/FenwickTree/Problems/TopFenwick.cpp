//2D BIT
//BIT can be used as a multi-dimensional data structure. Suppose you have a plane with dots (with non-negative coordinates). There are three queries at your disposal:
//set a dot at (x , y)
//remove the dot from (x , y)
//count the number of dots in rectangle (0 , 0), (x , y) – where (0 , 0) is down-left corner, (x , y) is up-right corner and sides are parallel to x-axis and y-axis.
//If m is the number of queries, max_x is the maximum x coordinate, and max_y is the maximum y coordinate, then this problem can be solved in O(m * log (max_x) * log (max_y)) time as follows. Each element of the tree will contain an array of dimension max_y, that is yet another BIT. Hence, the overall structure is instantiated as tree[max_x][max_y]. Updating indices of x-coordinate is the same as before. For example, suppose we are setting/removing dot (a , b). We will call update(a , b , 1)/update(a , b , -1), where update is:

void update(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}
