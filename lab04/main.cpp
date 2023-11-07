#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"

int main() {
    Triangle<double> t = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };  // center: (3.2; -3.2); area: 14.0524
    Octagon<double> o = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };  // center: (0; 1.34711e-16); area: 13.6896
    Hexagon h = {
        Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
        Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)
    };  // center: (0; 0); area: 10.3923
    Triangle<double> user;
    std::cin >> user;
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t),
        std::make_shared<Octagon<double>>(o),
        std::make_shared<Hexagon<double>>(h),
        std::make_shared<Triangle<double>>(user)
    };
    std::cout << "Centers: ";
    a.print_centers();
    std::cout << std::endl;
    std::cout << "Areas: ";
    a.print_areas();
    std::cout << std::endl;

    return 0;
}
