/* cpp introductory course day 4
 *
 * implement a patient database
 * provide interface which offers the options:
 *      add new patient record [a]
 *      delete patient record by id [d]
 *      print record by id [p]
 *      quit [q]
 *
 *      --> should be as fast as possible
 * "add..." should check if the records already exist and produce an
 * patient record consists of name, patient-id (0-1'000'000) and health-status ("healthy", "sick", "dead")
 */


#include <iostream>
#include <tuple>
#include <map>


using namespace std;
map <int, tuple <string, string>> patient_database;

void a(int const& id, string const& name, string const& health_status)
{
    if (patient_database.find(id) == patient_database.end()) {  // check if record already exists
        patient_database.insert(make_tuple(id, make_tuple(name, health_status)));   // insert new record
    }
}

void d(int const& id)
{
    patient_database.erase(id);
}

void p(int const& id)
{
    cout << "ID: " << patient_database.find(id)->first;
    cout << ", Name: " << get<0>(patient_database.find(id)->second);
    cout << ", Health Status: "<< get<1>(patient_database.find(id)->second);
}

void q()
{
    patient_database.clear();
}

int main()
{
    a(1, "Pauline", "healthy");
    a(34, "Tom", "sick");
    a(22, "Marianne", "dead");

    d(22);
    p(1);
}

