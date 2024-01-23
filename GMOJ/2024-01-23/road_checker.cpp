#include <cstdlib>
#include <cstdio>
int cnt;
int main() {
    while(true) {
        system("./find_the_most_comfortable_road_data > road.in");
        system("./find_the_most_comfortable_road_poly < road.in > road.ans");
        system("./find_the_most_comfortable_road < road.in > road.out");
        if(system("diff road.ans road.out")) break;
    }
}