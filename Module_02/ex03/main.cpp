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
	Point p2(Fixed(4), Fixed(1.3f));
	Point p3(Fixed(1.75f), Fixed(-2.2f));
	Point p4(Fixed(2.55f), Fixed(1.25f));
	Point p5(Fixed(-2.15f), Fixed(2.5f));
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

	//// Results ////
	std::cout << _BOLD << _CYAN << "\n/////////\t\tPOINTS TESTING\t\t/////////\n" << _END << std::endl;

	std::cout << _BOLD << "POINT TO TEST\t\tINSIDE ABC?\tINSIDE DEF?" << _END << std::endl;
	std::cout << _GREYER << "\nPoint NAME (x, y)\tResult\t\tResult" << _END << std::endl;
	
	std::cout << "P1 (" << p1.getX() << ", " << p1.getY() << ")\t\t" << (bsp(A, B, C, p1)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p1)?TRUE:FALSE) << std::endl;
	std::cout << "P2 (" << p2.getX() << ", " << p2.getY() << ")\t\t" << (bsp(A, B, C, p2)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p2)?TRUE:FALSE) << std::endl;
	std::cout << "P3 (" << p3.getX() << ", " << p3.getY() << ")\t" << (bsp(A, B, C, p3)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p3)?TRUE:FALSE) << std::endl;
	std::cout << "P4 (" << p4.getX() << ", " << p4.getY() << ")\t" << (bsp(A, B, C, p4)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p4)?TRUE:FALSE) << std::endl;
	std::cout << "P5 (" << p5.getX() << ", " << p5.getY() << ")\t" << (bsp(A, B, C, p5)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p5)?TRUE:FALSE) << std::endl;
	std::cout << "P6 (" << p6.getX() << ", " << p6.getY() << ")\t\t" << (bsp(A, B, C, p6)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p6)?TRUE:FALSE) << std::endl;
	std::cout << "P7 (" << p7.getX() << ", " << p7.getY() << ")\t" << (bsp(A, B, C, p7)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p7)?TRUE:FALSE) << std::endl;
	std::cout << "P8 (" << p8.getX() << ", " << p8.getY() << ")\t\t" << (bsp(A, B, C, p8)?TRUE:FALSE) << "\t\t" << (bsp(D, E, F, p8)?TRUE:FALSE) << std::endl;

	return 0;
}