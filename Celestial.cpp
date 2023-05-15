#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Defining the Universal Gravitational Constant, const as it shouldn't change during the execution of the program
const double G = 6.6743e-11;

vector<double> calculate_gravitational_force(double m1, vector<double> pos1, double m2, vector<double> pos2) {
    // Calculating the distance vector between the two positions
    vector<double> r12(3);
    for (int i = 0; i < 3; i++) {
        r12[i] = pos2[i] - pos1[i];
    }
    // Calculating the distance between the two positions
    double r12_distance = sqrt(pow(r12[0], 2) + pow(r12[1], 2) + pow(r12[2], 2));
    // Calculating the gravitational force vector
    vector<double> F12(3);
    for (int i = 0; i < 3; i++) {
        F12[i] = G * m1 * m2 * r12[i] / pow(r12_distance, 3);
    }
    return F12;
}

class CelestialBody {

public:

    double radius;
    double mass;
    double density;
    CelestialBody(double r, double m, double d) : radius(r), mass(m), density(d) {}
};

class Star : public CelestialBody {
public:
    double luminosity;
    double surface_temperature;
    Star(double r, double m, double d, double l, double t) : CelestialBody(r, m, d), luminosity(l), surface_temperature(t) {}
};

class Planet : public CelestialBody {
public:
    double orbital_radius;
    int num_moons;
    Star* star;
    Planet(double r, double m, double d, double o, int n, Star* s) : CelestialBody(r, m, d), orbital_radius(o), num_moons(n), star(s) {}
    double calculate_orbital_speed() {
        // Calculate the gravitational force between the planet and its star
        vector<double> F_gravity = calculate_gravitational_force(mass, {0, 0, 0}, star->mass, {orbital_radius, 0, 0});
        // Calculate the orbital speed using the centripetal force equation
        double v_orbital = sqrt(F_gravity[0] * orbital_radius / mass);
        return v_orbital;
    }
};

int main() {
    // Create a star and a planet
    Star our_sun(696340000, 1.989e30, 1.408, 3.828e26, 5778);
    Planet earth(6371000, 5.972e24, 5.515, 149.6e9, 1, &our_sun);

    // Calculate the orbital speed of the planet
    double v_orbital = earth.calculate_orbital_speed();
    cout << "Orbital speed of Earth: " << v_orbital << " m/s" << endl;

    return 0;
}
