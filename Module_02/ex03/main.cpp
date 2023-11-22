#include "Fixed.hpp"
#include "Point.hpp"

#define TRUE _FOREST_GREEN "TRUE" _END
#define FALSE _RED "FALSE" _END

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main () {

	//// Triangle 1 ////
	Point A(-4.5, 2.75);
	Point B(2, -5.6);
	Point C(5.4, -1.5);

	//// Triangle 2 ////
	Point D(-6, -2);
	Point E(3.5, 4.1);
	Point F(5.2, -5);

	//// Points to test ////

	Point p1;
	Point p2(Fixed(4), Fixed(1));
	Point p3(Fixed(1.75f), Fixed(-2.22f));
	Point p4(Fixed(2.55f), Fixed(1.25f));
	Point p5(Fixed(2.15f), Fixed(5.5f));
	Point p6(Fixed(-1), Fixed(-2));
	Point p7(Fixed(-2.5f), Fixed(1.1f));
	Point p8 = p6;

	std::cout << _BOLD << _CYAN << "/////////\t\tTRIANGLES POINTS\t\t/////////\n" << _END << std::endl;
	std::cout << _BOLD << "TRIANGLE ABC\t\t\t\tTRIANGLE DEF" << _END << std::endl;
	std::cout << _GREYER << "\nPoint NAME\t(x, y) \t\t\tPoint NAME\t(x, y) " << _END << std::endl;
	std::cout << "Point A \t(" << A.getX() << ", " << A.getY() << ")";
	std::cout << "\t\t" << "Point D \t(" << D.getX() << ", " << D.getY() << ")" << std::endl;
	std::cout << "Point B \t(" << B.getX() << ", " << B.getY() << ")";
	std::cout << "\t\t" << "Point E \t(" << E.getX() << ", " << E.getY() << ")" << std::endl;
	std::cout << "Point C \t(" << C.getX() << ", " << C.getY() << ")";
	std::cout << "\t\t" << "Point F \t(" << F.getX() << ", " << F.getY() << ")" << std::endl;

	std::cout << _BOLD << _CYAN << "\n/////////\t\tPOINTS TESTING\t\t/////////\n" << _END << std::endl;

	std::cout << _BOLD << "POINT TO TEST\t\tINSIDE ABC?\t\tINSIDE DEF?" << _END << std::endl;
	std::cout << _GREYER << "Point NAME\t(x, y)\tResult\t\tResult" << _END << std::endl;
	

}

// int main(void)
// {
// 	Point P1; //default constructor P1 = (0 ; 0)
// 	Point P2(Fixed(4.18f), Fixed(3.02f)); // Fixed constructor P2 = (4.18 ; 3.02)
// 	Point P3(P2); // copy constructor P3 = P2 = (4.18 ; 3.02)
// 	Point P4(Fixed(94.16f), Fixed(100.12f));
// 	Point P5(Fixed(2.56f), Fixed(2.08f));
// 	Point P(Fixed(1.5f), Fixed(1.5f)); 
// 	Point P6 = P; // Assignation operator used
// 	Point P7(Fixed(-0.5f), Fixed(-0.5f));
	
// 	//2.56 ; 2.08 part of the vertex
// 	Point Tc(0, 0);
// 	Point Ta(5.12, 4.16);
// 	Point Tb(1.18, -6.49);

// 	Point Tx(0, 3.02);
// 	Point Ty(5, 3.02);
// 	Point Tz(2.5, 0);

// 	// One of the vertexes
// 	std::cout << std::endl;
// 	std::cout << "P1: one of the vertexes, should be false" << std::endl;
// 	std::cout << "x: " << P1.getX() << " y: " << P1.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Ta, Tb, Tc, P1)?TRUE:FALSE) << std::endl;

// 	// Inside the triangle
// 	std::cout << std::endl;
// 	std::cout << "P2: inside the triangle, should be true" << std::endl;
// 	std::cout << "x: " << P2.getX() << " y: " << P2.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Ta, Tb, Tc, P2)?TRUE:FALSE) << std::endl;
	
// 	// On the edge
// 	std::cout << std::endl;
// 	std::cout << "P3: on the edge, should be false" << std::endl;
// 	std::cout << "x: " << P3.getX() << " y: " << P3.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Tx, Ty, Tz, P3)?TRUE:FALSE) << std::endl;

// 	// Outside the triangle
// 	std::cout << std::endl;
// 	std::cout << "P4: outside the triangle, should be false" << std::endl;
// 	std::cout << "x: " << P4.getX() << " y: " << P4.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Ta, Tb, Tc, P4)?TRUE:FALSE) << std::endl;

// 	// On the edge
// 	std::cout << std::endl;
// 	std::cout << "P5: on the edge, should be false" << std::endl;
// 	std::cout << "x: " << P5.getX() << " y: " << P5.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Ta, Tb, Tc, P5)?TRUE:FALSE) << std::endl;

// 	// Inside
// 	std::cout << std::endl;
// 	std::cout << "P6: inside, should be true" << std::endl;
// 	std::cout << "x: " << P6.getX() << " y: " << P6.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Tx, Ty, Tz, P6)?TRUE:FALSE) << std::endl;

// 	// Outside
// 	std::cout << std::endl;
// 	std::cout << "P7: outside the triangle, should be false" << std::endl;
// 	std::cout << "x: " << P7.getX() << " y: " << P7.getY() << std::endl;
// 	std::cout << "BSP Return value: " << (bsp(Tx, Ty, Tz, P7)?TRUE:FALSE) << std::endl;
// 	return 0; 
// }