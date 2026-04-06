#include <iostream>
#include <queue>
using namespace std;

// Structure to store disaster details
struct Disaster {
    string location;
    int severity;

    // Priority Queue comparator
    bool operator<(const Disaster& d) const {
        return severity < d.severity; // higher severity = higher priority
    }
};

// Function to generate alert
void sendAlert(string location, int severity) {
    cout << "\nALERT: Disaster at " << location;
    cout << " | Severity: " << severity << endl;

    if(severity >= 8)
        cout << "Action: Evacuate immediately!\n";
    else if(severity >= 5)
        cout << "Action: Stay alert and be prepared.\n";
    else
        cout << "Action: Situation under control.\n";
}

int main() {
    priority_queue<Disaster> pq;
    int n;

    cout << "Enter number of locations: ";
    cin >> n;

    // Input details
    for(int i = 0; i < n; i++) {
        Disaster d;

        cout << "\nEnter location: ";
        cin >> d.location;

        cout << "Enter severity (1-10): ";
        cin >> d.severity;

        // Send alert
        sendAlert(d.location, d.severity);

        // Add to priority queue
        pq.push(d);
    }

    // Resource allocation
    cout << "\nResource Allocation Order:\n";
    while(!pq.empty()) {
        cout << pq.top().location 
             << " (Severity: " << pq.top().severity << ")" << endl;
        pq.pop();
    }

    return 0;
}
