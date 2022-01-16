#include <iostream>


int main(){
    int x, y, w, h;
    int width_min, height_min, min;

    std::cin >> x >> y >> w >> h;

    width_min = x < (w - x) ? x : (w - x);
    height_min = y < (h - y) ? y : (h - y);
    min = width_min < height_min ? width_min : height_min;
    
    std::cout << min << std::endl;

    return 0;
}