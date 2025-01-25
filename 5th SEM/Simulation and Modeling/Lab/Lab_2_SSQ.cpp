#include <iostream>
#include <queue>
#include <random>
#include <ctime>

// Constants
const double ARRIVAL_RATE = 0.2;  // Average arrival rate of customers per minute
const double SERVICE_RATE = 0.25; // Average service rate of the server per minute

// Random number generator
std::mt19937 gen(std::time(nullptr));
std::uniform_real_distribution<> dis(0.0, 1.0);

// Function to generate exponential random variables for inter-arrival and service times
double exponential(double rate) {
    return -std::log(1.0 - dis(gen)) / rate;
}

int main() {
    int total_customers = 0;   // Total number of customers to be served
    std::cout << "Enter the number of customers to be served: ";
    std::cin >> total_customers;

    if (total_customers <= 0) {
        std::cerr << "Error: Number of customers must be positive." << std::endl;
        return 1;
    }

    // Simulation variables
    std::queue<double> arrival_times; // Queue to store arrival times of customers
    double current_time = 0.0;        // Current time in minutes
    double next_arrival_time = exponential(ARRIVAL_RATE); // Time of next customer arrival
    double next_departure_time = current_time + exponential(SERVICE_RATE); // Time of next customer departure

    double total_waiting_time = 0.0;  // Total waiting time of customers
    double total_service_time = 0.0;  // Total service time provided by the server

    int customers_served = 0; // Counter for customers served

    // Simulation loop
    while (customers_served < total_customers) {
        if (next_arrival_time < next_departure_time) {
            // Process arrival of a new customer
            current_time = next_arrival_time;
            arrival_times.push(current_time);
            customers_served++;
            next_arrival_time = current_time + exponential(ARRIVAL_RATE);

            // Update next departure time if server is idle
            if (customers_served == 1) {
                next_departure_time = current_time + exponential(SERVICE_RATE);
            }
        } else {
            // Process departure of a customer
            current_time = next_departure_time;
            double arrival_time = arrival_times.front();
            arrival_times.pop();
            total_waiting_time += current_time - arrival_time;
            total_service_time += exponential(SERVICE_RATE);

            // Update next departure time
            if (!arrival_times.empty()) {
                next_departure_time = current_time + exponential(SERVICE_RATE);
            } else {
                next_departure_time = current_time + 1.0; // No customers left, set to current time + 1
            }
        }
    }

    // Calculate average waiting time and average service time
    double avg_waiting_time = total_waiting_time / total_customers;
    double avg_service_time = total_service_time / total_customers;

    // Output results
    std::cout << "\nSimulation Results:" << std::endl;
    std::cout << "  Total customers served: " << total_customers << std::endl;
    std::cout << "  Average waiting time: " << avg_waiting_time << " minutes" << std::endl;
    std::cout << "  Average service time: " << avg_service_time << " minutes" << std::endl;

    return 0;
}
