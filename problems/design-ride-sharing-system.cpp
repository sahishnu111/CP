#include <bits/stdc++.h>
using namespace std;

class RideSharingSystem {
public:

    deque<int> riders;
    deque<int> drivers;


    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push_back(riderId);

    }
    
    void addDriver(int driverId) {
        drivers.push_back(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        if(riders.empty() || drivers.empty()){
            return {-1, -1};
        } else {
            int riderId = riders.front();
            int driverId = drivers.front();
            riders.pop_front();
            drivers.pop_front();
            return {driverId, riderId};
        }

        
    }
    
    void cancelRider(int riderId) {
        auto it = find(riders.begin(), riders.end(), riderId);
        if(it != riders.end()){
            riders.erase(it);
        }
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 * 
 * 
 * Implement the RideSharingSystem class:

    RideSharingSystem() Initializes the system.
    void addRider(int riderId) Adds a new rider with the given riderId.
    void addDriver(int driverId) Adds a new driver with the given driverId.
    int[] matchDriverWithRider() Matches the earliest available driver with the earliest waiting rider and removes 
    both of them from the system. Returns an integer array of size 2 where result = [driverId, riderId] if a match is made. 
    If no match is available, returns [-1, -1].

    void cancelRider(int riderId) Cancels the ride request of the rider with the given riderId if the rider exists and has not yet been matched.

 * 
 */


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage
    //RideSharingSystem* system = new RideSharingSystem();
    RideSharingSystem* rideSharingSystem = new RideSharingSystem(); // Initializes the system
    rideSharingSystem->addRider(8); // rider 8 joins the queue
    rideSharingSystem->addDriver(8); // driver 8 joins the queue
    rideSharingSystem->addDriver(6); // driver 6 joins the queue
    rideSharingSystem->matchDriverWithRider(); // returns [8, 8]
    rideSharingSystem->addRider(2); // rider 2 joins the queue
    rideSharingSystem->cancelRider(2); // rider 2 cancels
    rideSharingSystem->matchDriverWithRider(); // returns [-1, -1]
    

    
    return 0;
}