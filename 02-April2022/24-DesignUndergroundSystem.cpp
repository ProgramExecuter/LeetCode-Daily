// Time Complexity => O(logN)
// Space Complexity => O( (no. of concurrent cutomers) + (no. of station routes) )

class UndergroundSystem {
public:
    // Map of route and {time, count}
    // {startStation, endStation} --- {totalTime, noOfCus}
    map<pair<string, string>, pair<int, int>> stationTime;
    
    // Map of user_id and {checkIn, noCus}
    // id --- {chechInTime, startStation}
    map<int, pair<int, string>> mpCus;
    
    UndergroundSystem() {
        ;
    }
    
    void checkIn(int id, string stationName, int t) {
        if(mpCus.find(id) != mpCus.end())       // This customer is already checked in
            return;
        
        mpCus[id] = {t, stationName};           // Make a check-in for this customer
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mpCus.find(id) == mpCus.end())       // This customer is not checked in
            return;
        
        int startTime = mpCus[id].first;
        string startStation = mpCus[id].second;
        
        mpCus.erase(id);        // Remove customer from check-in, thus making mem-efficient
                                // Thus only stores concurrent customers travelling
        
        // Increase total travel time of this route and ( +1 no. of customer )
        stationTime[{startStation, stationName}].first += (t - startTime);
        stationTime[{startStation, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        // No customers for this station
        if( stationTime.find({startStation, endStation}) == stationTime.end() )
            return 0.0;
        
        int totalTime = stationTime[{startStation, endStation}].first;
        int nCus      = stationTime[{startStation, endStation}].second;
        
        // Avg Time = (total travel time in this route) / (no. of customers)
        return ( (1.0*totalTime) / (1.0*nCus) );
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */