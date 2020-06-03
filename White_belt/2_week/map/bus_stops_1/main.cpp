#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<string, vector<string>> buses;
    vector<string> buses_order;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;
        if (command == "NEW_BUS") {
            string bus;
            int stop_count;
            vector<string> stops;
            cin >> bus >> stop_count;
            for (int j = 0; j < stop_count; ++j) {
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }
            buses[bus] = stops;
            buses_order.push_back(bus);
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            // создаём vector для маршрутов, проходящих через данную остановку
            // если маршрут из всех маршрутов встечается в списке маршрутов через данную остановку, добавляем его к вектору
            vector<string> buses_for_a_stop;
            for (const auto &item_buses : buses) {
                for (const auto &item_stops : item_buses.second) {
                    if (item_stops == stop) {
                        buses_for_a_stop.push_back(item_buses.first);
                        break;
                    }
                }
            }
            if (buses_for_a_stop.empty()) {
                cout << "No stop" << endl;
            } else {
                // выводим в порядке, записываемом через команду NEW BUS
                for (const auto &bus : buses_order) {
                    if (count(buses_for_a_stop.begin(), buses_for_a_stop.end(), bus) != 0) {
                        cout << bus << " ";
                    }
                }
                cout << endl;
            }
        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const auto& stop : buses[bus]) {
                    cout << "Stop " << stop << ":";

                    //копия из BUSES_FOR_STOP;
                    vector<string> buses_for_a_stop;
                    for (const auto &item_buses : buses) {
                        for (const auto &item_stops : item_buses.second) {
                            if (item_stops == stop) {
                                buses_for_a_stop.push_back(item_buses.first);
                                break;
                            }
                        }
                    }
                    vector<string> parent_bus = {bus};
                    if (buses_for_a_stop == parent_bus) {
                        cout << " no interchange" << endl;
                    } else {
                        // выводим в порядке, записываемом через команду NEW BUS, за исключением исходной
                        for (const auto &bus_name : buses_order) {
                            if (bus_name != bus && count(buses_for_a_stop.begin(), buses_for_a_stop.end(), bus_name) != 0) {
                                cout << " " << bus_name;
                            }
                        }
                        cout << endl;
                    }
                }
            }
        } else if (command == "ALL_BUSES") {
            if (buses.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& item_buses : buses) {
                    cout << "Bus " << item_buses.first << ":";
                    for (const auto& item_stops : item_buses.second) {
                        cout << " " << item_stops;
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    return 0;
}